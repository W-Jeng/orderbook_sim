#include <iostream>
#include "test.h"

int main() {   
    /*
    Main of the order book solution, here we create market participants simulation and slow down the
    orders to see the dynamics of order book
    */
    Test test;
    // test.QueueTest();
    // test.PriorityQueueTest();
    // test.LobPromptTest();
    // test.TestConnection();
    // test.TestOrder();
    // test.TestAccount();
    test.TestMarketParticipant();
    return 0;
}

