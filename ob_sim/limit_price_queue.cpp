#include "limit_price_queue.h"
#include<iostream>

LimitPriceQueue::LimitPriceQueue(const double& set_limit_price):limit_price(set_limit_price) {};

void LimitPriceQueue::add_order(const BasicOrder& basic_order) {
				order_queue.push(basic_order);
				order_status_map[basic_order.order_id] = basic_order;
				total_num_orders++;
				total_volume += basic_order.quantity;
				return;
}

void LimitPriceQueue::cancel_order(const std::string& order_id) {
				// cancelling order doesnt really delete off the order in the queue, because this is inefficient to do so
				// to achieve better time complexity, we can create an unordered_map to mark it as cancelled first,
				// then only pop the queue when it becomes the head of the queue.
				if (order_status_map.find(order_id) != order_status_map.end()) {
								order_status_map[order_id].order_status = OrderStatus::CANCELLED;
								total_num_orders--;
								total_volume -= order_status_map[order_id].quantity;

								// ensuring that the head is always an active order
								if (order_queue.front().order_id == order_id) {
												order_queue.pop(); 
								}
				}
				return;
}

const int LimitPriceQueue::get_priority_order_quantity() {
				// remember that priority order always has an active status!
				return order_queue.front().quantity;
}

const bool LimitPriceQueue::is_empty() const {
				if (order_queue.empty())
								return true;
				else
								return false;
}

void LimitPriceQueue::print_status() {
				for (const auto& pair : order_status_map) 
								std::cout << "Order Id: " << pair.first << ", Status: " << order_status_to_str(pair.second.order_status) << "\n";
				return;
}

void LimitPriceQueue::fill_order(const int& fill_quantity) {
				// fill the order by subtracting then check if the underlying front queue has zero quantity
				// if zero quantity or status = cancelled then pop the front
				order_queue.front().quantity -= fill_quantity;
				total_volume -= fill_quantity;

				if (order_queue.front().quantity == 0) {
								order_queue.pop();
								total_num_orders--;
				}
				//ensuring the front queue has an active orders or just leave it as empty queue
				while (!order_queue.empty() && order_status_map[order_queue.front().order_id].order_status == OrderStatus::CANCELLED) {
								order_queue.pop();
				}

				return;
}
