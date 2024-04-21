#pragma once


class TradingBehavior {
public:
    int get_buysell_quantity(const int& stock_holding);
    double get_buysell_price(const double& last_traded_price);
};