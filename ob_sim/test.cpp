#include "test.h"
#include "limit_price_queue.h"
#include "order.h"
#include "order_book.h"
#include<iostream>

Test::Test() {};

void Test::QueueTest() {
    BasicOrder order1{ "a1", 100 };
    BasicOrder order2{ "a2", 200 };
    LimitPriceQueue limit_price_queue(1.21);
    limit_price_queue.add_order(order1);
    limit_price_queue.add_order(order2);
    limit_price_queue.print_status();

    limit_price_queue.cancel_order("a1");
    limit_price_queue.print_status();
    BasicOrder* order3 = limit_price_queue.get_priority_order();
    std::cout << "order id: " << order3->order_id << ", quantity: " << order3->quantity << ", status: "
        << order_status_to_str(order3->order_status) << "\n";

    return;
};

void Test::PriorityQueueTest() {
    OrderBook order_book;
    DirectionalOrder directional_order = {"A1", 1.51, 100};
    order_book.add_order(directional_order);
    order_book.print_maps();
};

