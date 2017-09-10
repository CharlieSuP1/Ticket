//
//  Buyer.cpp
//  Ticket
//
//  Created by supeng on 31/08/2017.
//  Copyright © 2017 supeng. All rights reserved.
//

#include "Buyer.hpp"

Buyer::Buyer(string name,int id) {
    this->name = name;
    this->id = id;
}

bool Buyer::sameBuyer(Buyer* buyer) {
    if(buyer->name == this ->name) {
        if (buyer->id == this->id) {
            return true;
        }
    }
    return false;
}
