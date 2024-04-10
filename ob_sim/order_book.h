#pragma once

#include<queue>
#include "limit_price_queue.h"

using max_heap = std::priority_queue<LimitPriceQueue, std::vector<LimitPriceQueue>, std::less<LimitPriceQueue>>;
using min_heap = std::priority_queue<LimitPriceQueue, std::vector<LimitPriceQueue>, std::greater<LimitPriceQueue>>;

enum BookSide {
    Bid,
    Ask
};

class OrderBook {
public:
    OrderBook();
    // max heap, get largest bid price at O(1)
    // min heap, get smallest ask price at O(1)
    max_heap bid_book;
    min_heap ask_book;
    std::unordered_map<double, LimitPriceQueue> bid_price_map; // key holds the price, value holds LimitPriceQueue as we can add new orders at "not the top"
    std::unordered_map<double, LimitPriceQueue> ask_price_map;

    void add_order(const DirectionalOrder& directional_order);
    void update_book(const BasicOrder& basic_order, const BookSide);
};
