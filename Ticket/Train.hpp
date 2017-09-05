//
//  Train.hpp
//  Ticket
//
//  Created by supeng on 31/08/2017.
//  Copyright © 2017 supeng. All rights reserved.
//
//  火车（坐席相关）数据结构

#ifndef Train_hpp
#define Train_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Train {
public:
    string trainName;  //火车名字
    int trainID;       //火车ID
    unsigned totalSeat; //总坐席
    Train(string trainName,int trainID,unsigned totalSeat);
};

#endif /* Train_hpp */
