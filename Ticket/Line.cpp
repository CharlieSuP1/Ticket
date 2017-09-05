//
//  Line.cpp
//  Ticket
//
//  Created by supeng on 31/08/2017.
//  Copyright © 2017 supeng. All rights reserved.
//

#include "Line.hpp"

Line::Line(string lineName, int lineID, Station* startStation, Train* train) {
    this->lineName = lineName;
    this->lineID = lineID;
    this->startStation = startStation;
    this->train = train;
}
