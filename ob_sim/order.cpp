#include<string>
#include "order.h"

const std::string order_status_to_str(const OrderStatus& order_status) {
    std::string status_str;
    switch (order_status) {
        case OrderStatus::ACTIVE:
            status_str = "ACTIVE";
            return "ACTIVE";

        case OrderStatus::FILLED:
            return "FILLED";
            break;

        case OrderStatus::CANCELLED:
            return "CANCELLED";
            break;
                
        default:
            return "UNKNOWN STATUS";
    }
    return "";
}