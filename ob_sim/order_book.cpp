#include "order_book.h"

OrderBook::OrderBook() {};

void OrderBook::add_order(const DirectionalOrder& directional_order) {
    // push new LimitPriceQueue at the particular price, if the price point does't exist at that point
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
    }
    match_order();
    return;
}

void OrderBook::match_order() {
    if (!bid_book.empty() && !ask_book.empty() && bid_book.top() >= ask_book.top()) {
        std::cout << "matches order here!" << "\n";
        std::cout << "top of bid book: " << bid_book.top() << ", top of ask book " << ask_book.top() << "\n";
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


