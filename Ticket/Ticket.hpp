//
//  Ticket.hpp
//  Ticket
//
//  Created by supeng on 31/08/2017.
//  Copyright © 2017 supeng. All rights reserved.
//
//  火车票

#ifndef Ticket_hpp
#define Ticket_hpp

#include <stdio.h>
#include <iostream>
#include "Buyer.hpp"
#include "Station.hpp"


static int currentTicketID = 0;

class Ticket {
public:
    Buyer* buyer; //购买者
    Station* startStation;//起始站点
    Station* endStation;//终点站
    int ticketID; //票务ID
    float price;//价格
    float distance;//总里程
    Ticket(Buyer* buyer,Station* startStation, Station* endStation);
    void print();
};

#endif /* Ticket_hpp */
