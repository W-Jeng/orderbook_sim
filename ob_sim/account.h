#pragma once
#include<string>
#include "stock_exchange.h"

class Account {
public:
    Account();
    bool submit_order(const ClientOrder& client_order);

private:
    StockExchange stock_exchange;
    double capital;
    double net_asset_value;
    std::unordered_map<std::string, int> stock_inventory;
};

