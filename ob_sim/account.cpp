#include "account.h"

Account::Account():stock_exchange(StockExchange::set_connection()) {};

bool Account::submit_order(const ClientOrder& client_order) {
    // check internal whether the user has enough shares to sell or money to buy

    stock_exchange.receive_order(client_order);
    return;
};
