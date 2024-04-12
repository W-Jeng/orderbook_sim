#include "order_book.h"

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
    match_order(new_order_side);
    return;
}

void OrderBook::match_order(const BookSide& new_order_side) {
    if (!bid_book.empty() && !ask_book.empty() && bid_book.top() >= ask_book.top()) {
        std::cout << "matches order here!" << "\n";
        std::cout << "top of bid book: " << bid_book.top() << ", top of ask book " << ask_book.top() << "\n";
        // remember that although the top of the book isn't cancelled status, that doesnt mean that after matching order, we will always see active orders
        
        const double matching_price = (new_order_side == BookSide::Bid) ? ask_book.top() : bid_book.top();
        std::cout << "matching price: " << matching_price << "\n";
        LimitPriceQueue bid_order_queue = bid_price_map.at(bid_book.top());
        LimitPriceQueue ask_order_queue = ask_price_map.at(ask_book.top());
        
        BasicOrder* bid_order = bid_order_queue.get_priority_order();
        BasicOrder* ask_order = ask_order_queue.get_priority_order();

        if (bid_order != nullptr && ask_order != nullptr) {
            // means there's order in the top queue
            const int matching_quantity = std::min(bid_order->quantity, ask_order->quantity);
            // match the trade by filling the bid order using its member function.
        } 

        if (bid_order == nullptr) {
            // remove top price on bid_order + removing the price at bid_price_map
        }

        if (ask_order == nullptr) {
            // remove top price on ask_order + removing the price at ask_price_map
        }
    }
    return;
}

void OrderBook::print_maps() {
    for (auto& pair : bid_price_map) {
        std::cout << "Limit Price: " << pair.first << ", Value: ";
        LimitPriceQueue temp = pair.second;
        std::cout << temp.get_limit_price() << "\n";
    }
}


