#include "stock_exchange.h"

StockExchange::StockExchange() {};

//ensures singleton design
StockExchange& StockExchange::set_connection() {
    static StockExchange single_instance;
    return single_instance;
}
