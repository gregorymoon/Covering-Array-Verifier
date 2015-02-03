//
//  Column.h
//  CSE 430 Individual Project 1
//
//  Created by Gregory Moon on 1/21/15.
//  Copyright (c) 2015 Gregory Moon. All rights reserved.
//

#ifndef __CSE_430_Individual_Project_1__Column__
#define __CSE_430_Individual_Project_1__Column__

#include <stdio.h>
#include <iostream>

#include <vector>

class Column {
    static int staticColNum;
    std::vector<int> values;
    int currIdx, colNum;
    unsigned long numElementsInCol;
    
public:
    Column(unsigned long numElementsInColInput);
    void add(int element);
    int get(int idx);
    int getColNum();
    unsigned long length();
    std::string toString();
};

#endif /* defined(__CSE_430_Individual_Project_1__Column__) */
