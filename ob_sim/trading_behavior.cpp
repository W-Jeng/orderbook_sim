#include "trading_behavior.h"
#include<vector>
#include<random>
#include<iostream>

int TradingBehavior::get_buysell_quantity(const int& stock_holding) {
    // what we want is that a holding tend not to hold too much stock
    static std::vector<double> probability_buying_splits = { 0.2, 0.5, 0.8 };
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> uniform_real(0.0, 1.0);
    static std::uniform_int_distribution<> uniform_int(0, 100);

    double random_number_generated = uniform_real(gen);
    double buying_segment;
    if (stock_holding < 0) {
        buying_segment = probability_buying_splits[2];
    } else if (stock_holding > 0) {
        buying_segment = probability_buying_splits[0];
    } else {
        buying_segment = probability_buying_splits[1];
    }

    if (random_number_generated < buying_segment) {
        // selling
        return -uniform_int(gen);
    } else {
        // buying 
        return uniform_int(gen);
    }
};

double TradingBehavior::get_buysell_price(const double& last_traded_price) {
    // general idea is to set the last_traded_price as the mean of normal distribution, then sample from it.
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static double tick_spacing = 0.01 * 2;
    static std::normal_distribution<> dis(last_traded_price, std::sqrt(tick_spacing));
    double price_generated = dis(gen);
    price_generated = std::round(price_generated * 100) / 100.0;
    return std::max(price_generated, 0.01);
};