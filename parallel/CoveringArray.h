//
//  CoveringArray.h
//  CSE 430 Individual Project 1
//
//  Created by Gregory Moon on 1/22/15.
//  Copyright (c) 2015 Gregory Moon. All rights reserved.
//

#ifndef __CSE_430_Individual_Project_1__CoveringArray__
#define __CSE_430_Individual_Project_1__CoveringArray__

#include <stdio.h>
#include <vector>

#include "OccurenceArray.h"
#include "OccurenceLocationArray.h"
#include "Column.h"

class CoveringArray {
    OccurenceArray * occurenceArray;
    OccurenceLocationArray * occurenceLocationArray;
    std::vector<std::vector<int>> values, dontCarePositions;
    std::vector<Column *> columns;
    std::vector<std::vector<std::string>> modifiedValues;
    
public:
    CoveringArray(std::vector<std::vector<int>> values, int colsInSubArray, int numDistinctElements);
    std::vector<std::vector<std::string>> getModifiedValues();
    std::vector<std::vector<int>> getDontCarePositions();
    bool validCoveringArray();
    
private:
    void createColumns();
    void modifyOriginal();

};

#endif /* defined(__CSE_430_Individual_Project_1__CoveringArray__) */
