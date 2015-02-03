//
//  Column.cpp
//  CSE 430 Individual Project 1
//
//  Created by Gregory Moon on 1/21/15.
//  Copyright (c) 2015 Gregory Moon. All rights reserved.
//

#include "Column.h"

int Column::staticColNum = 0;

Column::Column(unsigned long numElementsInColInput){
    this->numElementsInCol = numElementsInColInput;
    colNum = staticColNum;
    staticColNum++;
    currIdx = 0;
}   //end init

void Column::add(int element){
    if(currIdx < this->numElementsInCol){
        values.push_back(element);
        currIdx++;
    }
}   //end add

int Column::get(int idx){
    if(idx < this->numElementsInCol)
        return values[idx];
    else
        return -1;
}	//end get

int Column::getColNum(){
    return colNum;
}	//end getColNum

unsigned long Column::length(){
    return this->numElementsInCol;
}	//end length