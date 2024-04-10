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
				//bool operator<(const LimitPriceQueue& other) const;
				//bool operator>(const LimitPriceQueue& other) const;
				//LimitPriceQueue& operator=(const LimitPriceQueue& other);
private:
				int total_num_orders = 0;
				const double limit_price;
				std::queue<BasicOrder> order_queue; //first in first out
				std::unordered_map<std::string, BasicOrder> order_status_map; //constant lookup to check whether it has been cancelled
};
