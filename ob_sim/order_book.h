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


};
