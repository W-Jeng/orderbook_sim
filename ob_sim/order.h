#pragma once

#include<string>

enum OrderStatus {
				ACTIVE,
				FILLED,
				CANCELLED
};

struct BasicOrder {
				//BasicOrder(std::string temp_order_id, unsigned long int temp_quantity);
				std::string order_id;
				unsigned long int quantity;
				OrderStatus order_status = OrderStatus::ACTIVE; //active by nature
};

struct DirectionalOrder {
				std::string order_id;
				double limit_price;
				long int quantity;
};

const std::string order_status_to_str(const OrderStatus& order_status);
