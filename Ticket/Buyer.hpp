//
//  Buyer.hpp
//  Ticket
//
//  Created by supeng on 31/08/2017.
//  Copyright © 2017 supeng. All rights reserved.
//
//  购买者信息

#ifndef Buyer_hpp
#define Buyer_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Buyer {
public:
    string name;  //购买者名字
    int id;       //购买者身份证号
    Buyer(string name,int id);
    //返回当前buyer和入参的buyer是否同一个人
    //也可以重载 == 运算符实现
    bool sameBuyer(Buyer* buyer);
};

#endif /* Buyer_hpp */
