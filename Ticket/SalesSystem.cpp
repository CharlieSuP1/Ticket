//
//  SalesSystem.cpp
//  Ticket
//
//  Created by supeng on 31/08/2017.
//  Copyright © 2017 supeng. All rights reserved.
//

#include "SalesSystem.hpp"

RemainedTicketsInfo* SalesSystem::searchRemainedTickesInfo(Station* startStation, Station* endStation) {
    unsigned int currentSeat = this->line->train->totalSeat;
    for (int i = 0; i < this->ticketHistory.size(); i++) {
        Ticket* tmpTicket = this->ticketHistory[i];
        if (startStationWithIn(startStation,endStation, tmpTicket->startStation, tmpTicket->endStation)) {
            currentSeat--;
        }
    }
    if (currentSeat > 0) {
        return new RemainedTicketsInfo(startStation, endStation, currentSeat);
    }
    return NULL;
}

Ticket* SalesSystem::buyTicket(Buyer* buyer,Station* startStation,Station* endStation) {
    //首先查询余票
    RemainedTicketsInfo* remainedTicketInfo = this->searchRemainedTickesInfo(startStation, endStation);
    Ticket* newTicket = NULL;
    if (remainedTicketInfo) {
        //查询余票成功，开始订票
        newTicket = new Ticket(buyer, startStation, endStation);
        this->ticketHistory.push_back(newTicket);
    }
    return newTicket;
}

vector<Ticket*> SalesSystem::searchTickesInfo(Buyer* buyer) {
    vector<Ticket*> resultTickets = vector<Ticket*> ();
    for (int i = 0; i < this->ticketHistory.size(); i++) {
        
        //从购票历史中，搜索满足条件的票
        Ticket* tmpticket = ticketHistory[i];
        if (tmpticket->buyer->sameBuyer(buyer)) {
            resultTickets.push_back(tmpticket);
        }
    }
    return resultTickets;
}

vector<Ticket*> SalesSystem::refoundTickets(Buyer* buyer) {
    vector<Ticket*> resultTickets = vector<Ticket*> ();
    vector<Ticket*>::iterator it = this->ticketHistory.begin();

    //从购票历史中，查询和入参buyer一致的ticket，并且从购票历史中删除
    while(it != this->ticketHistory.end()){
        Ticket* tmpticket = *it;
        if (tmpticket->buyer->sameBuyer(buyer)) {
            it = this->ticketHistory.erase(it);
            resultTickets.push_back(tmpticket);
        }else {
            it++;
        }
    }
    return resultTickets;
}

bool SalesSystem::saveTicketToFile() {
#warning TODO 增加保存到文件操作
    return true;
}

vector<Ticket*> SalesSystem::loadTicketFromFile() {
#warning TODO 增加从文件中读取操作
    return vector<Ticket*>();
}

SalesSystem::SalesSystem () {
    Station* firstStation = setupStation();
    Train* train = setupTrain();
    this->line = new Line("K27", 1234, firstStation, train);
    this->ticketHistory = loadTicketFromFile();
}

SalesSystem::~SalesSystem() {
    saveTicketToFile();
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

bool SalesSystem::startStationWithIn(Station*searchStartStation,Station*searchEndStation, Station* startStation,Station* endStation) {
    Station* currentStation = searchStartStation;
    while (currentStation) {
        if (currentStation->stationID <= endStation->stationID) {
            if (currentStation->stationID > startStation->stationID) {
                return true;
            }
        }
        if (currentStation->stationID == searchEndStation->stationID) {
            break;
        }
        currentStation = currentStation->nextStation;
    }
    return false;
}

