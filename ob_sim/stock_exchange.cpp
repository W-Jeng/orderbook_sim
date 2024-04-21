#include "stock_exchange.h"
#include <random>

StockExchange::StockExchange() {
    StockExchange::init_ticker("SPY");
    StockExchange::init_ticker("QQQ");
    StockExchange::init_ticker("VT");
};

//ensures singleton design
StockExchange& StockExchange::set_connection() {
    static StockExchange single_instance;
    // std::cout << "Stock Exchange Connected\n";
    return single_instance;
};

void StockExchange::init_ticker(const std::string& ticker) {
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

bool StockExchange::receive_order(const ClientOrder& client_order) {
    if (ticker_specific_ob.find(client_order.get_ticker()) != ticker_specific_ob.end()) {
        const std::string unique_order_id = StockExchange::get_randomized_order_id();
        const DirectionalOrder directional_order = { unique_order_id, client_order.get_limit_price(), client_order.get_quantity() };
        ticker_specific_ob.at(client_order.get_ticker()).add_order(directional_order);
        ticker_specific_ob.at(client_order.get_ticker()).tabulate_order_book();
        return true;
    } else {
        return false;
    }
};

const double StockExchange::get_last_traded_price(std::string ticker) const {
    if (ticker_specific_ob.find(ticker) != ticker_specific_ob.end()) {
        return ticker_specific_ob.at(ticker).get_last_done_price();
    } 
    return 0.0;
};