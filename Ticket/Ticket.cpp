//
//  Ticket.cpp
//  Ticket
//
//  Created by supeng on 31/08/2017.
//  Copyright © 2017 supeng. All rights reserved.
//

#include "Ticket.hpp"
using namespace std;

Ticket::Ticket(Buyer* buyer,Station* startStation, Station* endStation) {
    this->buyer = buyer;
    this->startStation = startStation;
    this->endStation = endStation;
    this->ticketID = currentTicketID++;
    
    float tempPrice = 0;
    float tempDistance = 0;
    Station* tempStaion = startStation;
    while (tempStaion->nextStation && tempStaion != endStation) {
        tempPrice += tempStaion->priceToNextStation;
        tempDistance += tempStaion->distanceToNextStation;
    }
    this->price = tempPrice;
    this->distance = tempDistance;
}

void Ticket::print() {
//    cout << "Here are ticket info\n";
//    cout << "Buyer: " + this->bu
}
