//
//  Line.hpp
//  Ticket
//
//  Created by supeng on 31/08/2017.
//  Copyright © 2017 supeng. All rights reserved.
//
//  线路数据结构

#ifndef Line_hpp
#define Line_hpp

#include <stdio.h>
#include "Station.hpp"
#include "Train.hpp"

using namespace std;

class Line {
public:
    string lineName; //线路名字
    int lineID;   //线路ID
    Station* startStation;  //起始站点
    Train* train; //车辆信息
    Line(string lineName, int lineID, Station* startStation, Train* train);
};

#endif /* Line_hpp */
