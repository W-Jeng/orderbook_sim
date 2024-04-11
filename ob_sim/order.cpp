#include<string>
#include "order.h"

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