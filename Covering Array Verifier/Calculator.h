//
//  Calculator.h
//  CSE 430 Individual Project 1
//
//  Created by Gregory Moon on 1/30/15.
//  Copyright (c) 2015 Gregory Moon. All rights reserved.
//

#ifndef __CSE_430_Individual_Project_1__Calculator__
#define __CSE_430_Individual_Project_1__Calculator__

#include <stdio.h>
#include <vector>

#include "Column.h"

class Calculator {
    std::vector<std::vector<int>> permutationList;
    std::vector<std::vector<Column *>> columnCombinationList;
    
    void getColumnCombinations(std::vector<Column *> arr, std::vector<Column *> data, int start, unsigned long end, int idx, int r);
    void permute(std::vector<int> c, int n, std::vector<int> start);
    
public:
    int choose(int n, int k);
    int factorial(int num);
    std::vector<std::vector<int>> permute(std::vector<int> valsToPermute, int elementsInPermutation);
    std::vector<std::vector<Column *>> getColumnCombinations(std::vector<Column *> arr, int r);

    Calculator();
};

#endif /* defined(__CSE_430_Individual_Project_1__Calculator__) */
