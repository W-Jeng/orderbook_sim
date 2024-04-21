#pragma once
#include<string>
#include "stock_exchange.h"

class Account {
public:
    Account();
    bool submit_order(const ClientOrder& client_order);
    void add_to_inventory(const ClientOrder& client_order);
    const int get_quantity(std::string ticker_specified) const;
    const double get_last_traded_price(std::string ticker_specified) const;
private:
    StockExchange stock_exchange;
    std::unordered_map<std::string, int> stock_inventory;
};

