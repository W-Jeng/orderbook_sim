#pragma once
#include<vector>
#include<string>
#include<unordered_map>
#include "order_book.h"

class StockExchange {
public:
    static StockExchange& set_connection();

private:
    StockExchange();
    std::vector<std::string> available_tickers;
    std::unordered_map<std::string, OrderBook> ticker_specific_ob; //ticker specific orderbook
};