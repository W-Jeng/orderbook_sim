#include "order_book.h"

OrderBook::OrderBook() {};

void OrderBook::add_order(const DirectionalOrder& directional_order) {
    // push new LimitPriceQueue at the particular price, if the price point does't exist at that point
    std::cout << "here 1";
    if (directional_order.quantity > 0) {
        // check if bid order book exists at the limit price
        if (bid_price_map.find(directional_order.limit_price) == bid_price_map.end()) {
            // cannot find it, then create one
            LimitPriceQueue limit_price_queue = LimitPriceQueue(directional_order.limit_price);
            // bid_book.push(limit_price_queue);
            bid_price_map.emplace(directional_order.limit_price, limit_price_queue);
            std::cout << "here added!" << "\n";
        }
        // create basic order to the particular LimitPriceQueue
        BasicOrder basic_order = { directional_order.order_id, directional_order.quantity };

        
    } else {
        // check if ask order book exists at the limit price
        if (ask_price_map.find(directional_order.limit_price) == ask_price_map.end()) {
            // cannot find it, then create one 
            LimitPriceQueue limit_price_queue = LimitPriceQueue(directional_order.limit_price);
            // ask_book.push(limit_price_queue);
           
        }
        // create basic order to the particular LimitPriceQueue
        BasicOrder basic_order = { directional_order.order_id, -directional_order.quantity };
        
    }
    return;
}

void OrderBook::update_book(const BasicOrder& basic_order, const BookSide) {

    return;
}

void OrderBook::print_maps() {
    for (auto& pair : bid_price_map) {
        std::cout << "Limit Price: " << pair.first << ", Value: ";
        LimitPriceQueue temp = pair.second;
        std::cout << temp.get_limit_price();
    }
}