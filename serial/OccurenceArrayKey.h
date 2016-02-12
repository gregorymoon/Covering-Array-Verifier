//
//  OccurenceArrayKey.h
//  CSE 430 Individual Project 1
//
//  Created by Gregory Moon on 1/22/15.
//  Copyright (c) 2015 Gregory Moon. All rights reserved.
//

#ifndef __CSE_430_Individual_Project_1__OccurenceArrayKey__
#define __CSE_430_Individual_Project_1__OccurenceArrayKey__

#include <stdio.h>
#include <vector>

#include "Column.h"

using namespace std;

class OccurenceArrayKey {
    std::vector<Column *> cols;
    std::vector<int> vals;
    
public:
    OccurenceArrayKey(std::vector<Column *> colInputs, std::vector<int> valInputs);
    std::vector<Column *> getCols();
    std::vector<int> getVals();
};

#endif /* defined(__CSE_430_Individual_Project_1__OccurenceArrayKey__) */
