#pragma once

#include<queue>
#include "limit_price_queue.h"

class OrderBook {
public:
    OrderBook();
    // max heap, get largest bid price at O(1)
    // min heap, get smallest ask price at O(1)
    std::priority_queue<LimitPriceQueue, std::vector<LimitPriceQueue>, std::less<LimitPriceQueue>> bid_book; 
    std::priority_queue<LimitPriceQueue, std::vector<LimitPriceQueue>, std::greater<LimitPriceQueue>> ask_book; 
    std::unordered_map<double, int> bid_price_map; // key holds the price, value holds the number of active orders (not volume) at the price point.
    std::unordered_map<double, int> ask_price_map;

    void add_order(const DirectionalOrder& directional_order);

};
