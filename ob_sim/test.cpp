#include "test.h"
#include "limit_price_queue.h"
#include "order.h"

Test::Test() {};

void Test::QueueTest() {
	BasicOrder order1{ "a1", 100 };
	BasicOrder order2{ "a2", -200 };
	LimitPriceQueue limit_price_queue;
	limit_price_queue.add_order(order1);
	limit_price_queue.add_order(order2);
	limit_price_queue.print_status();

	limit_price_queue.cancel_order("a2");
	limit_price_queue.print_status();
	return;
};

