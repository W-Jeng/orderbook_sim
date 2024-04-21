#include "market_participants.h"

void MarketParticipants::perform_action() {
    int buysell_units = trading_behavior.get_buysell_quantity(account.get_quantity(ticker_trading));
    double buysell_price = trading_behavior.get_buysell_price(account.get_last_traded_price(ticker_trading));

    std::cout << "New Orders In -> Units: " << buysell_units << ", Limit Price: " << buysell_price << "\n";
    if (buysell_units != 0) {
        account.submit_order(ClientOrder(ticker_trading, buysell_units, buysell_price, 0.0, 0.0, TimeEnforcementType::GOODTILLCANCEL));
    }
    return;
};