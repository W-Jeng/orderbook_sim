#include<string>
#include "order.h"

std::string order_status_to_str(const OrderStatus order_status) {
	std::string status_str;
	switch (order_status) {
	case OrderStatus::ACTIVE:
		status_str = "ACTIVE";
		break;

	case OrderStatus::FILLED:
		status_str = "FILLED";
		break;

	case OrderStatus::CANCELLED:
		status_str = "CANCELLED";
		break;

	default:
		status_str = "UNKNOWN STATUS";
		break;
	}
	return status_str;
}