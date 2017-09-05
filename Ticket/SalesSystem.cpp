//
//  SalesSystem.cpp
//  Ticket
//
//  Created by supeng on 31/08/2017.
//  Copyright © 2017 supeng. All rights reserved.
//

#include "SalesSystem.hpp"

RemainedTicketsInfo* SalesSystem::searchRemainedTickesInfo(Station* startStation, Station* endStation) {
    return NULL;
}

Ticket* SalesSystem::buyTicket(Buyer* buyer,Station* startStation,Station* endStation) {
    return NULL;
}

vector<Ticket*> SalesSystem::searchTickesInfo(Buyer* buyer) {
    return vector<Ticket*>();
}

bool SalesSystem::refoundTickets(Buyer* buyer) {
    return false;
}

SalesSystem::SalesSystem () {
    Station* firstStation = setupStation();
    Train* train = setupTrain();
    this->line = new Line("K27", 1234, firstStation, train);
}

Station* SalesSystem::setupStation() {
    int stationID = 1;
    float distanceToNext = 99;
    
    Station* firstStation = NULL;
    Station* preStation = NULL;
    for (int i = 0; i < 10; i++) {
        string stationName = "A" + to_string(stationID);
        Station* station = new Station(stationID, stationName, distanceToNext, NULL);
        if (i == 0) {
            firstStation = station;
        }
        if (preStation) {
            preStation->nextStation = station;
        }
        preStation = station;
        stationID++;
        distanceToNext++;
    }
    return firstStation;
}

Station* SalesSystem::stationWithIndex(int index) {
    Station* currentStation = this->line->startStation;
    while (currentStation && currentStation->stationID != index) {
        currentStation = currentStation->nextStation;
    }
    return currentStation;
}

Train* SalesSystem::setupTrain() {
    return new Train("Old train", 1234, 10);
}
