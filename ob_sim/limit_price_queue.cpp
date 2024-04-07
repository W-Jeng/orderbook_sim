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
	// cancelling order doesnt really delete off the order in the queue, because this is inefficient to do so
	// to achieve better time complexity, we can create an unordered_map to mark it as cancelled first,
	// then only pop the queue when it becomes the head of the queue.
	if (order_status_map.find(order_id) != order_status_map.end()) {
		order_status_map[order_id] = OrderStatus::CANCELLED;
		total_num_orders--;
	}
	return;
}

signed long int LimitPriceQueue::get_priority_order_qty() {
	// first we should check whether the highest order is cancelled or not
	// if cancelled then we take off top order and continue searching for active order qty
	while (!order_queue.empty()) {
		BasicOrder highest_priority_order = order_queue.front();
		if (order_status_map[highest_priority_order.order_id] == OrderStatus::CANCELLED) {
			order_queue.pop();
		} else if (order_status_map[highest_priority_order.order_id] == OrderStatus::ACTIVE) {
			return highest_priority_order.quantity;
		}
	}
	return 0;
}

void LimitPriceQueue::print_status() {
	for (const auto& pair : order_status_map) 
		std::cout << "Order Id: " << pair.first << ", Status: " << order_status_to_str(pair.second) << "\n";
	return;
}
