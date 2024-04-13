#pragma once

#include<queue>
#include<unordered_map>
#include "order.h"

class LimitPriceQueue {
public:
				LimitPriceQueue(const double& limit_price);

				void add_order(const BasicOrder& basic_order);
				void cancel_order(const std::string& order_id);
				void print_status();
				BasicOrder* get_priority_order();
				inline const double get_limit_price() { return limit_price; };
				inline const int get_total_num_orders() { return total_num_orders; };
				inline const int get_total_volume() { return total_volume; };
				void fill_order(const int& quantity);
				
private:
				int total_num_orders = 0;
				int total_volume = 0;
				const double limit_price;
				std::queue<BasicOrder> order_queue; //first in first out
				std::unordered_map<std::string, BasicOrder> order_status_map; //constant lookup to check whether it has been cancelled
};
