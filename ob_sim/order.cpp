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

ClientOrder::ClientOrder(std::string temp_ticker, long int temp_quantity, double temp_take_profit_price,
                         double temp_stop_loss, TimeEnforcementType temp_time_enforcement_type):
                         ticker(temp_ticker), quantity(temp_quantity), take_profit_price(temp_take_profit_price),
                         stop_loss(temp_stop_loss), time_enforcement_type(temp_time_enforcement_type), order_status(OrderStatus::ACTIVE) {

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