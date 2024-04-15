#include "stock_exchange.h"
#include <random>

StockExchange::StockExchange() {
    StockExchange::add_ticker("SPY");
    StockExchange::add_ticker("QQQ");
    StockExchange::add_ticker("VT");
};

//ensures singleton design
StockExchange& StockExchange::set_connection() {
    static StockExchange single_instance;
    std::cout << "connected here\n";
    return single_instance;
};

void StockExchange::add_ticker(const std::string& ticker) {
    ticker_specific_ob.emplace(ticker, OrderBook());
    return;
};

const std::string StockExchange::get_randomized_order_id() {
    static const std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    static int string_size = 15;
    std::string result;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, charset.size() - 1);

    for (int i = 0; i < string_size; ++i) {
        result += charset[distr(gen)];
    }
    return StockExchange::ensure_order_id_uniqueness(result);
};

const std::string StockExchange::ensure_order_id_uniqueness(const std::string& order_id) {
    if (all_order_id_set.find(order_id) == all_order_id_set.end()) {
        return order_id;
    }
    return StockExchange::get_randomized_order_id();
};