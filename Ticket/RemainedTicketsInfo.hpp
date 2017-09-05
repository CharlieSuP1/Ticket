//
//  RemainedTicketsInfo.hpp
//  Ticket
//
//  Created by supeng on 31/08/2017.
//  Copyright © 2017 supeng. All rights reserved.
//
//  剩余票务信息

#ifndef RemainedTicketsInfo_hpp
#define RemainedTicketsInfo_hpp

#include <stdio.h>
#include "Station.hpp"

class RemainedTicketsInfo {
public:
    Station* startStation;
    Station* endStation;
    unsigned remainedTickets;
    float price;
    float distance;
    
    RemainedTicketsInfo (Station* startStation, Station* endStation,unsigned remainedTickets);
};
#endif /* RemainedTicketsInfo_hpp */
