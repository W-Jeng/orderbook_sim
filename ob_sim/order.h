#pragma once

#include<string>

enum OrderStatus {
				ACTIVE,
				FILLED,
				CANCELLED
};

struct BasicOrder {
				std::string order_id;
				unsigned long int quantity;
				OrderStatus order_status = OrderStatus::ACTIVE; //active by nature
};

const std::string order_status_to_str(const OrderStatus& order_status);
