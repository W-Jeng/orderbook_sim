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

enum TimeEnforcementType {
				GOODTILLCANCEL,
				FILLORKILL
};

class ClientOrder {
public:
				ClientOrder(std::string temp_ticker, long int temp_quantity, double temp_take_profit_price, double temp_stop_loss, TimeEnforcementType temp_time_enforcement_type);

private:
				std::string ticker;
				long int quantity;
				double take_profit_price;
				double stop_loss;
				TimeEnforcementType time_enforcement_type;
				OrderStatus order_status;
				std::string order_time_submitted;
};

const std::string order_status_to_str(const OrderStatus& order_status);
