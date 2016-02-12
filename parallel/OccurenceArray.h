//
//  OccurenceArray.h
//  CSE 430 Individual Project 1
//
//  Created by Gregory Moon on 1/22/15.
//  Copyright (c) 2015 Gregory Moon. All rights reserved.
//

#ifndef __CSE_430_Individual_Project_1__OccurenceArray__
#define __CSE_430_Individual_Project_1__OccurenceArray__

#include <stdio.h>
#include <vector>
#include <unordered_map>

#include "Column.h"
#include "OccurenceArray.h"
#include "OccurenceArrayKey.h"
#include "Calculator.h"

class OccurenceArray {
    int numDistinctElements, colsInSubArray;
    std::vector<std::vector<int>> distinctElementCombinations;
    std::vector<Column *> columns;
    std::vector<std::vector<Column *>> columnCombinations;
    std::vector<OccurenceArrayKey *> occurenceArrayKeys;
    std::unordered_map<OccurenceArrayKey *, int> table;
    Calculator *calc;
    
    void updateTable();
    void initializeTable();
    void generateOccurenceArrayKeys();
    void generateDistinctElementCombinations();
    void generateColumnCombinations();
    bool hasImportantValues();


public:
    OccurenceArray(std::vector<Column *> columns, int colsInSubArray, int numDistinctElements);
    std::unordered_map<OccurenceArrayKey *, int> getTable();
    std::vector<OccurenceArrayKey *> getOccurenceArrayKeys();
    bool validCoveringArray();
    
};

#endif /* defined(__CSE_430_Individual_Project_1__OccurenceArray__) */
