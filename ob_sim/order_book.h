#pragma once

#include<queue>
#include "limit_price_queue.h"
#include<iostream>

using max_heap = std::priority_queue<double, std::vector<double>, std::less<double>>;
using min_heap = std::priority_queue<double, std::vector<double>, std::greater<double>>;

enum BookSide {
    Bid,
    Ask
};

class OrderBook {
public:
    OrderBook();
    void add_order(const DirectionalOrder& directional_order);
    void match_order();
    void print_maps();

private:
    // max heap, get largest bid price at O(1)
    // min heap, get smallest ask price at O(1)
    max_heap bid_book;
    min_heap ask_book;
    std::unordered_map<double, LimitPriceQueue> bid_price_map; // key holds the price, value holds LimitPriceQueue as we can add new orders at "not the top"
    std::unordered_map<double, LimitPriceQueue> ask_price_map;
};
