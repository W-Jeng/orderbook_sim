#pragma once
#ifndef ORDER_H
#define ORDER_H
#include<string>


enum OrderStatus {
	ACTIVE,
	FILLED,
	CANCELLED
};

struct BasicOrder {
	std::string order_id;
	signed long int quantity;
};

const std::string order_status_to_str(const OrderStatus& order_status);

#endif