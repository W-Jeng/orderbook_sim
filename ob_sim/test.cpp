#include "test.h"
#include "limit_price_queue.h"
#include "order.h"
#include "order_book.h"
#include<iostream>
#include <sstream>
#include "stock_exchange.h"
#include "account.h"
#include "market_participants.h"
#include <thread>
#include <chrono>

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
    //BasicOrder* order3 = limit_price_queue.get_priority_order();
    //std::cout << "order id: " << order3->order_id << ", quantity: " << order3->quantity << ", status: "
       // << order_status_to_str(order3->order_status) << "\n";

    return;
};

void Test::PriorityQueueTest() {
    OrderBook order_book;
    DirectionalOrder directional_order = {"A1", 1.51, 100};
    order_book.add_order(directional_order);

    DirectionalOrder directional_order2 = { "A2", 1.51, -50 };
    order_book.add_order(directional_order2);

    DirectionalOrder directional_order3 = { "A3", 1.51, 100 };
    order_book.add_order(directional_order);

    DirectionalOrder directional_order4 = { "A4", 1.50, -125 };
    order_book.add_order(directional_order4);

    DirectionalOrder directional_order5= { "A5", 1.52, 300 };
    order_book.add_order(directional_order5);

    DirectionalOrder directional_order6 = { "A6", 1.52, 100 };
    order_book.add_order(directional_order6);

    order_book.tabulate_order_book();

    DirectionalOrder directional_order7 = { "A7", 1.51, -450 };
    order_book.add_order(directional_order7);

    order_book.tabulate_order_book();
    return;
};

void Test::LobPromptTest() {
    std::string input;
    std::string order_id;
    double limit_price;
    int quantity;
    OrderBook order_book;
    DirectionalOrder directional_order;
    std::cout << "Enter order_id, limit price, quantity: ";

    while(std::getline(std::cin, input)) {
        std::stringstream ss(input);
        ss >> order_id >> limit_price >> quantity;

        if (ss.fail()) {
            break;
        }

        directional_order = { order_id, limit_price, quantity };
        order_book.add_order(directional_order);
        order_book.tabulate_order_book();

        std::cout << "Enter order_id, limit price, quantity: ";
    }
    return;
}

void Test::TestConnection() {
    StockExchange& stock_exchange1 = StockExchange::set_connection();
    StockExchange& stock_exchange2 = StockExchange::set_connection();

    return;
}

void Test::TestOrder() {
    ClientOrder client_order("SPY", 100, 10.0, 0, 0, TimeEnforcementType::GOODTILLCANCEL);

    return;
}

void Test::TestAccount() {
    Account account;
    bool order_valid = account.submit_order(ClientOrder("SPY", 100, 10.0, 0, 0, TimeEnforcementType::GOODTILLCANCEL));
    bool order_valid2 = account.submit_order(ClientOrder("SPY", 200, 10.1, 0, 0, TimeEnforcementType::GOODTILLCANCEL));
    bool order_valid3 = account.submit_order(ClientOrder("SPY", -100, 10.2, 0, 0, TimeEnforcementType::GOODTILLCANCEL));
    return;
};

void Test::TestMarketParticipant() {
    MarketParticipants market_participant;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100; ++i) {
        market_participant.perform_action();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed_milliseconds = end - start;
    std::cout << "Elapsed time: " << elapsed_milliseconds.count() << " milliseconds" << std::endl;
    return;
}