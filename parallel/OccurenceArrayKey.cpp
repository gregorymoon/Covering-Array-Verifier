//
//  OccurenceArrayKey.cpp
//  CSE 430 Individual Project 1
//
//  Created by Gregory Moon on 1/22/15.
//  Copyright (c) 2015 Gregory Moon. All rights reserved.
//

#include "OccurenceArrayKey.h"

OccurenceArrayKey::OccurenceArrayKey(std::vector<Column *> colInputs, std::vector<int> valInputs){
    cols = colInputs;
    vals = valInputs;
}   //end init

std::vector<Column *> OccurenceArrayKey::getCols(){
    return this->cols;
}

std::vector<int> OccurenceArrayKey::getVals(){
    return this->vals;
}