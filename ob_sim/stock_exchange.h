#pragma once
#include<vector>
#include<string>
#include<unordered_map>
#include "order_book.h"
#include<iostream>
#include "order_book.h"

class StockExchange {
public:
    static StockExchange& set_connection();

private:
    StockExchange();
    void add_ticker(const std::string& ticker);
    std::unordered_map<std::string, OrderBook> ticker_specific_ob; //ticker specific orderbook
};