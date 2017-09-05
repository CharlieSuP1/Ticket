//
//  Station.cpp
//  Ticket
//
//  Created by supeng on 31/08/2017.
//  Copyright © 2017 supeng. All rights reserved.
//

#include "Station.hpp"

Station::Station(int stationID,string stationName,float distanceToNextStation,Station* nextStation) {
    this->stationID = stationID;
    this->stationName = stationName;
    this->distanceToNextStation = distanceToNextStation;
    this->priceToNextStation = distanceToNextStation;
    this->nextStation = nextStation;
}
