//
//  Column.cpp
//  CSE 430 Individual Project 1
//
//  Created by Gregory Moon on 1/21/15.
//  Copyright (c) 2015 Gregory Moon. All rights reserved.
//

#include "Column.h"

int Column::staticColNum = 0;

/*
 Column:
    The Column class simply holds the elements in the Covering Array so that they are easier to manage and index. It's really more of a helper class because it doesn't provide too much additional funtionality over an array.
 */

/*
 Constructor 1:
    input parameters:
        numElementsInColInputs:
            This parameter is used to make sure that all columns created or a Covering Array are the same size.
 */

Column::Column(unsigned long numElementsInColInput){
    numElementsInCol = numElementsInColInput;
    colNum = staticColNum;
    currIdx = 0;

    staticColNum++;
}   //end init

/*
 add:
    Adds an element to the column
 
    input parameters:
        element: the element to add to the column
 */

void Column::add(int element){
    if(currIdx < numElementsInCol){
        values.push_back(element);
        currIdx++;
    }
}   //end add

/*
 get:
    Gets an element from the column
    
    input parameters: 
        idx: the index to retrieve an element from
 */

int Column::get(int idx){
    if(idx < numElementsInCol && idx >= 0)
        return values[idx];
    else
        return -1;
}	//end get

/*
 getColNum:
    This method is helpful for indexing columns. It is a getter for the colNum variable which is incremented every time a new column is made.
    
    output:
        The column number
 */

int Column::getColNum(){
    return colNum;
}	//end getColNum

/*
 length:
    returns the number of elements in the column
    
    output:
        the number of elements in the column
 */

unsigned long Column::length(){
    return numElementsInCol;
}	//end length