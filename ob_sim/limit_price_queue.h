#pragma once

#include<queue>
#include<unordered_map>
#include "order.h"

class LimitPriceQueue {
public:
				LimitPriceQueue(const double& limit_price);
				const double limit_price;
				void add_order(const BasicOrder& basic_order);
				void cancel_order(const std::string& order_id);
				void print_status();
				BasicOrder* get_priority_order();

private:
				int total_num_orders = 0;
				std::queue<BasicOrder> order_queue; //first in first out
				std::unordered_map<std::string, BasicOrder> order_status_map; //constant lookup to check whether it has been cancelled
};
