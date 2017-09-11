//
//  main.cpp
//  Ticket
//
//  Created by supeng on 31/08/2017.
//  Copyright © 2017 supeng. All rights reserved.
//

#include <iostream>
#include <string>
#include "SalesSystem.hpp"

using namespace std;

void showHomeWelcome();
static SalesSystem* salesSystem = NULL;

void pressEnterToMainPage() {
    cout << "Press enter to back to main page\n";
    char a;
    cin >> a;
    showHomeWelcome();
}

void inputAndValid(int* startStationIndex,int* endStationIndex) {
    cout << "Please input index of start station (1 ~ 10):\n";
    cin >> *startStationIndex;
    
    while (*startStationIndex < 1 || *startStationIndex > 10) {
        cout << "Wrong station index.Input again\n";
        cin >> *startStationIndex;
    }
    
    cout << "Please input index of end station (1 ~ 10):\n";
    
    cin >> *endStationIndex;
    while (*endStationIndex < 1 || *endStationIndex > 10) {
        cout << "Wrong station index.Input again\n";
        cin >> *endStationIndex;
    }
    
    if (*startStationIndex == *endStationIndex) {
        cout << "Error, Start station index equals end station index\n";
        pressEnterToMainPage();
    }
    
    if (*startStationIndex > *endStationIndex) {
        int tempStation = *startStationIndex;
        *startStationIndex = *endStationIndex;
        *endStationIndex = tempStation;
    }
}

void showSearchRemainTicket() {
    cout << "Welcome to remain ticket search system!\n";
    
    int startStationIndex;
    int endStationIndex;

    inputAndValid(&startStationIndex, &endStationIndex);
    Station* startStation = salesSystem->stationWithIndex(startStationIndex);
    Station* endStation = salesSystem->stationWithIndex(endStationIndex);
    RemainedTicketsInfo* remainedTicketsinfo = salesSystem->searchRemainedTickesInfo(startStation, endStation);
    
    cout << "Start station is " + startStation->stationName + ". And the end station is " + endStation->stationName + " .\n";
    cout << "There are " + to_string(remainedTicketsinfo->remainedTickets) + " tickets remains.";
    pressEnterToMainPage();
}



void showBuyTicket() {
    cout << "Welcome to ticket purchase system!\n";
    cout << "Please input your name:\n";
    string name;
    cin >> name;
    cout << "Please input your ID:\n";
    int id;
    cin >> id;
    
    int startStationIndex;
    int endStationIndex;
    
    inputAndValid(&startStationIndex, &endStationIndex);
    
    Station* startStation = salesSystem->stationWithIndex(startStationIndex);
    Station* endStation = salesSystem->stationWithIndex(endStationIndex);
    RemainedTicketsInfo* remainedTicketsinfo = salesSystem->searchRemainedTickesInfo(startStation, endStation);
    Ticket* ticket = NULL;
    if (remainedTicketsinfo->remainedTickets > 0) {
        ticket = salesSystem->buyTicket(new Buyer(name,id), salesSystem->stationWithIndex(startStationIndex), salesSystem->stationWithIndex(endStationIndex));
    }
    if (ticket) {
        cout << "Puchase succeeded !!!";
    }
    pressEnterToMainPage();
}

void showSearchPurchaseHistory() {
    
}

void showRefoundTicket() {
    
}

void showHomeWelcome(){
    cout << "Welcome to train ticket sale system!\n";
    cout << "Choose function you want:\n";
    cout << "1. Search Remain ticket:\n";
    cout << "2. Buy ticket:\n";
    cout << "3. Search puchase history:\n";
    cout << "4. Refound ticket:\n";
    cout << "Input others to quit:\n";
    
    int index = 0;
    cin >> index;
    
    switch (index) {
        case 1:
            showSearchRemainTicket();
            break;
        case 2:
            showBuyTicket();
            break;
        case 3:
            showSearchPurchaseHistory();
            break;
        case 4:
            showRefoundTicket();
            break;
        default:
            exit(0);
            break;
    }
}

int main(int argc, const char * argv[]) {

    salesSystem = new SalesSystem();
    
    while (1) {
        showHomeWelcome();
    }
    
    return 0;
}
