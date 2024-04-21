#pragma once

#include "account.h"
#include "trading_behavior.h"

class MarketParticipant {
public:
    void perform_action();
private:
    std::string ticker_trading = "SPY";
    Account account;
    TradingBehavior trading_behavior;
};