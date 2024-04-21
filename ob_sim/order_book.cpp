#include "order_book.h"
#include "util.h"

OrderBook::OrderBook() {};

void OrderBook::add_order(const DirectionalOrder& directional_order) {
    // push new LimitPriceQueue at the particular price, if the price point does't exist at that point
    BookSide new_order_side;
    if (directional_order.quantity > 0) {
        // check if bid order book exists at the limit price
        if (bid_price_map.find(directional_order.limit_price) == bid_price_map.end()) {
            // if cannot find it, then create one
            bid_book.push(directional_order.limit_price);
            bid_price_map.emplace(directional_order.limit_price, LimitPriceQueue(directional_order.limit_price));
        }
        // create basic order to the particular LimitPriceQueue
        BasicOrder basic_order = { directional_order.order_id, directional_order.quantity };
        bid_price_map.at(directional_order.limit_price).add_order(basic_order);
        new_order_side = BookSide::Bid;
    } else {
        // check if ask order book exists at the limit price
        if (ask_price_map.find(directional_order.limit_price) == ask_price_map.end()) {
            // cannot find it, then create one 
            ask_book.push(directional_order.limit_price);
            ask_price_map.emplace(directional_order.limit_price, LimitPriceQueue(directional_order.limit_price));
        }
        // create basic order to the particular LimitPriceQueue
        BasicOrder basic_order = { directional_order.order_id, -directional_order.quantity };
        ask_price_map.at(directional_order.limit_price).add_order(basic_order);
        new_order_side = BookSide::Ask;
    }
    OrderBook::match_order(new_order_side);
    return;
}

void OrderBook::match_order(const BookSide& new_order_side) {
    while (!bid_book.empty() && !ask_book.empty() && bid_book.top() >= ask_book.top()) {
        // remember that although the top of the book isn't cancelled status, that doesnt mean that after matching order, we will always see active orders
        const double matching_price = (new_order_side == BookSide::Bid) ? ask_book.top() : bid_book.top();
        LimitPriceQueue* bid_order_queue = &bid_price_map.at(bid_book.top());
        LimitPriceQueue* ask_order_queue = &ask_price_map.at(ask_book.top());
        
        if (!bid_order_queue->is_empty() && !ask_order_queue->is_empty()) {
            const int matching_quantity = std::min(bid_order_queue->get_priority_order_quantity(), ask_order_queue->get_priority_order_quantity());
            bid_order_queue->fill_order(matching_quantity);
            ask_order_queue->fill_order(matching_quantity);
            last_done_price = matching_price;
            last_done_quantity = matching_quantity;
            std::cout << "Order matched at: " << matching_price << ", quantity matched: " << last_done_quantity << "\n";
        }

        if (bid_order_queue->is_empty()) {
            // remove top price on bid_order + removing the price at bid_price_map
            bid_price_map.erase(bid_book.top());
            bid_book.pop();
        }

        if (ask_order_queue->is_empty()) {
            // remove top price on ask_order + removing the price at ask_price_map
            ask_price_map.erase(ask_book.top());
            ask_book.pop();
        }
    }
    return;
}


void OrderBook::tabulate_order_book() {
    // tabulate columns in order:
    // Bid Side [Order, Volume, Buy],  || Ask Side [Sell, Volume, Order]
    static const std::vector<std::string> ordered_table_columns = { "BidOrder", "BidVolume", "BidPrice", "AskPrice", "AskVolume", "AskOrder" };
    static std::unordered_map<std::string, int> table_column_spacing = { {"BidOrder", 15},
                                                                        {"BidVolume", 15},
                                                                        {"BidPrice", 15},
                                                                        {"AskPrice", 15},
                                                                        {"AskVolume", 15},
                                                                        {"AskOrder", 15} };
    for (auto& col_name : ordered_table_columns) {
        std::cout << col_name << empty_space(table_column_spacing[col_name] - col_name.length());
    }
    std::cout << "\n-------------------------------------------------------------------------------------\n";
    std::vector<double> sorted_bid_prices, sorted_ask_prices;

    for (const auto& pair : bid_price_map) {
        sorted_bid_prices.push_back(pair.first);
    }
    for (const auto& pair : ask_price_map) {
        sorted_ask_prices.push_back(pair.first);
    }
    std::sort(sorted_bid_prices.begin(), sorted_bid_prices.end(), std::greater<>());
    std::sort(sorted_ask_prices.begin(), sorted_ask_prices.end(), std::less<>());

    // we go through level by level to print its item
    for (int i = 0; i < std::max(sorted_bid_prices.size(), sorted_ask_prices.size()); ++i) {
        if (i < sorted_bid_prices.size()) {
            LimitPriceQueue temp = bid_price_map.at(sorted_bid_prices[i]);
            std::cout << temp.get_total_num_orders() << empty_space(table_column_spacing["BidOrder"] - std::to_string(temp.get_total_num_orders()).length());
            std::cout << temp.get_total_volume() << empty_space(table_column_spacing["BidVolume"] - std::to_string(temp.get_total_volume()).length());
            std::cout << temp.get_limit_price() << empty_space(table_column_spacing["BidPrice"] - double_to_string(temp.get_limit_price()).length());
        } else {
            std::cout << empty_space(table_column_spacing["BidOrder"]+ table_column_spacing["BidVolume"]+table_column_spacing["BidPrice"]);
        }
        if (i < sorted_ask_prices.size()) {
            LimitPriceQueue temp = ask_price_map.at(sorted_ask_prices[i]);
            std::cout << temp.get_limit_price() << empty_space(table_column_spacing["AskPrice"] - double_to_string(temp.get_limit_price()).length());
            std::cout << temp.get_total_volume() << empty_space(table_column_spacing["AskVolume"] - std::to_string(temp.get_total_volume()).length());
            std::cout << temp.get_total_num_orders() << empty_space(table_column_spacing["AskOrder"] - std::to_string(temp.get_total_num_orders()).length());
        } else {
            std::cout << empty_space(table_column_spacing["AskPrice"]+table_column_spacing["AskVolume"]+table_column_spacing["AskOrder"]);
        }
        std::cout << "\n";
    }
    std::cout << "-------------------------------------------------------------------------------------\n\n";
    return;
}

double OrderBook::get_bid_ask_spread() const {
    if (!bid_book.empty() && !ask_book.empty()) {
        return ask_book.top() - bid_book.top();
    }
    return -1.0;
}

double OrderBook::get_last_done_price() const {
    return last_done_price;
};
