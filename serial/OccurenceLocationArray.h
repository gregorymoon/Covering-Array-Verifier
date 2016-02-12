//
//  OccurenceLocationArray.h
//  CSE 430 Individual Project 1
//
//  Created by Gregory Moon on 1/22/15.
//  Copyright (c) 2015 Gregory Moon. All rights reserved.
//

#ifndef __CSE_430_Individual_Project_1__OccurenceLocationArray__
#define __CSE_430_Individual_Project_1__OccurenceLocationArray__

#include <stdio.h>
#include <unordered_map>
#include <vector>

#include "OccurenceArray.h"

class OccurenceLocationArray {
    std::vector<std::vector<int>> counts;
    std::unordered_map<OccurenceArrayKey *, int> occurenceArr;
    void populateCounts();
    void initCounts();
    int findLocation(std::vector<Column *> cols, std::vector<int> integers);
    
public:
    OccurenceLocationArray(std::vector<std::vector<int>> values, std::unordered_map<OccurenceArrayKey *, int> occurenceArr);
    std::vector<std::vector<int>> getCounts();
};

#endif /* defined(__CSE_430_Individual_Project_1__OccurenceLocationArray__) */
