#include "limit_price_queue.h"
#include<iostream>

LimitPriceQueue::LimitPriceQueue() {};

void LimitPriceQueue::add_order(const BasicOrder& basic_order) {
	order_queue.push(basic_order);
	order_status_map[basic_order.order_id] = OrderStatus::ACTIVE;
	total_num_orders++;
	return;
}

void LimitPriceQueue::cancel_order(const std::string& order_id) {
	if (order_status_map.find(order_id) != order_status_map.end()) {
		order_status_map[order_id] = OrderStatus::CANCELLED;
		total_num_orders--;
	}
	return;
}

void LimitPriceQueue::print_status() {
	for (const auto& pair : order_status_map) 
		std::cout << "Order Id: " << pair.first << ", Status: " << order_status_to_str(pair.second) << "\n";
	return;
}
