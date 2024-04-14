#include "stock_exchange.h"

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

