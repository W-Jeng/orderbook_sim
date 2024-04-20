#pragma once

#include<string>
#include<chrono>
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
				ClientOrder(std::string temp_ticker, long int temp_quantity, double temp_limit_price, double temp_take_profit_price,
																double temp_stop_loss, TimeEnforcementType temp_time_enforcement_type);
				const std::string get_ticker() const;
				const long int get_quantity() const;
				const double get_limit_price() const;
				const double get_take_profit() const;
				const double get_stop_loss() const;
				const TimeEnforcementType get_time_enforcement_type() const;
				const OrderStatus get_order_status() const;
				const std::chrono::local_time <std::chrono::system_clock::duration> get_order_time_submitted() const;
				void set_order_status(const OrderStatus& enum_type);

private:
				std::string ticker;
				long int quantity;
				double limit_price;
				double take_profit_price;
				double stop_loss_price;
				TimeEnforcementType time_enforcement_type;
				OrderStatus order_status;
				std::chrono::local_time <std::chrono::system_clock::duration> order_time_submitted;
};

const std::string order_status_to_str(const OrderStatus& order_status);
