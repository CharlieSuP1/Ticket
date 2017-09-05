//
//  Station.hpp
//  Ticket
//
//  Created by supeng on 31/08/2017.
//  Copyright © 2017 supeng. All rights reserved.
//
//  车站站点数据结构

#ifndef Station_hpp
#define Station_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Station {
public:
    int stationID;  //站点ID
    string stationName; //站点名字
    float distanceToNextStation; //到下一站距离
    float priceToNextStation; //到下个站点价钱
    Station* nextStation;  //下一个站点
    Station(int stationID,string stationName,float distanceToNextStation,Station* nextStation);
};

#endif /* Station_hpp */
