#include<string>
#include "order.h"
#include<chrono>
#include<iostream>
//BasicOrder::BasicOrder(std::string temp_order_id, unsigned long int temp_quantity) : order_id(temp_order_id), quantity(temp_quantity) {};

const std::string order_status_to_str(const OrderStatus& order_status) {
    std::string status_str;
    switch (order_status) {
        case OrderStatus::ACTIVE:
            status_str = "ACTIVE";
            return "ACTIVE";

        case OrderStatus::FILLED:
            return "FILLED";

        case OrderStatus::CANCELLED:
            return "CANCELLED";
                
        default:
            return "UNKNOWN STATUS";
    }
    return "";
}

ClientOrder::ClientOrder(std::string temp_ticker, long int temp_quantity, double temp_limit_price, double temp_take_profit_price,
                         double temp_stop_loss, TimeEnforcementType temp_time_enforcement_type):
                         ticker(temp_ticker), quantity(temp_quantity), limit_price(temp_limit_price), take_profit_price(temp_take_profit_price),
                         stop_loss_price(temp_stop_loss), time_enforcement_type(temp_time_enforcement_type), order_status(OrderStatus::ACTIVE) {

    const auto now = std::chrono::system_clock::now();
    const auto time_zone = std::chrono::current_zone();
    const auto local_time = time_zone->to_local(now);
    const auto time_point = std::chrono::time_point_cast<std::chrono::days>(local_time);
    const auto year_month_day = std::chrono::year_month_day{ time_point };

    int year = static_cast<int>(year_month_day.year());
    int month = static_cast<unsigned>(year_month_day.month());
    int day = static_cast<unsigned>(year_month_day.day());
    std::cout << "year: " << year << ", month: " << month << ", day: " << day << "\n";
};

const std::string ClientOrder::get_ticker() const {
    return ticker;
}

const long int ClientOrder::get_quantity() const {
    return quantity;
}

const double ClientOrder::get_limit_price() const {
    return limit_price;
}

const double ClientOrder::get_take_profit() const {
    return take_profit_price;
}

const double ClientOrder::get_stop_loss() const {
    return stop_loss_price;
}

const TimeEnforcementType ClientOrder::get_time_enforcement_type() const {
    return time_enforcement_type;
}

const OrderStatus ClientOrder::get_order_status() const {
    return order_status;
}

const std::string ClientOrder::get_order_time_submitted() const {
    return order_time_submitted;
}

void ClientOrder::set_order_status(const OrderStatus& enum_type) {
    order_status = enum_type;
    return;
}