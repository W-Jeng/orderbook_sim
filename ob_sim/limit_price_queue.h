#pragma once
#ifndef LIMIT_PRICE_QUEUE_H
#define LIMIT_PRICE_QUEUE_H

#include<queue>
#include<unordered_map>
#include "order.h"

class LimitPriceQueue {
public:
	LimitPriceQueue();
	
	void add_order(const BasicOrder& basic_order);
	void cancel_order(const std::string& order_id);
	void print_status();

private:
	int total_num_orders = 0;
	std::queue<BasicOrder> order_queue;
	std::unordered_map<std::string, OrderStatus> order_status_map;
};

#endif
