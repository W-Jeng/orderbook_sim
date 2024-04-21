#include "market_participant.h"

void MarketParticipant::perform_action() {
    int buysell_units = trading_behavior.get_buysell_quantity(account.get_quantity(ticker_trading));
    double buysell_price = trading_behavior.get_buysell_price(account.get_last_traded_price(ticker_trading));

    std::cout << "buy sell units: " << buysell_units << ", price: " << buysell_price << "\n";

    return;
};