#include "order_book.h"

OrderBook::OrderBook() {};

void OrderBook::add_order(const DirectionalOrder& directional_order) {
    // push new LimitPriceQueue at the particular price, if the price point does't exist at that point

    if (directional_order.quantity > 0) {
        // check if bid order book exists at the limit price
        if (bid_price_map.find(directional_order.limit_price) != bid_price_map.end()) {
            // cannot find it, then create one

            bid_price_map[directional_order.limit_price] = 1;
        }
        // add the order to the particular LimitPriceQueue

    } else {
        // check if ask order book exists at the limit price
        if (ask_price_map.find(directional_order.limit_price) != ask_price_map.end()) {
            // cannot find it, then create one 
            ask_price_map[directional_order.limit_price] = 1;
        }
        // add the order to the particular LimitPriceQueue

    }
    return;
}