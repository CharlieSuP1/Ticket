//
//  RemainedTicketsInfo.cpp
//  Ticket
//
//  Created by supeng on 31/08/2017.
//  Copyright © 2017 supeng. All rights reserved.
//

#include "RemainedTicketsInfo.hpp"

RemainedTicketsInfo::RemainedTicketsInfo (Station* startStation, Station* endStation,unsigned remainedTickets) {
    this->startStation = startStation;
    this->endStation = endStation;
    this->remainedTickets = remainedTickets;
    
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
