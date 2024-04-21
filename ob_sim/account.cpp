#include "account.h"

Account::Account():stock_exchange(StockExchange::set_connection()) {};

bool Account::submit_order(const ClientOrder& client_order) {
    bool order_received = stock_exchange.receive_order(client_order);
    if (order_received) {
        Account::add_to_inventory(client_order);
    }
    return order_received;
};

void Account::add_to_inventory(const ClientOrder& client_order) {
    if (stock_inventory.find(client_order.get_ticker()) != stock_inventory.end()) {
        stock_inventory[client_order.get_ticker()] += client_order.get_quantity();
    } else {
        stock_inventory.emplace(client_order.get_ticker(), client_order.get_quantity());
    }
    return;
};

const int Account::get_quantity(std::string ticker_specified) const {
    if (stock_inventory.find(ticker_specified) != stock_inventory.end()) {
        return stock_inventory.at(ticker_specified);
    }
    return 0;
}

const double Account::get_last_traded_price(std::string ticker_specified) const {
    return stock_exchange.get_last_traded_price(ticker_specified);
}