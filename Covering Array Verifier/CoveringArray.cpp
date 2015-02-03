//
//  CoveringArray.cpp
//  CSE 430 Individual Project 1
//
//  Created by Gregory Moon on 1/22/15.
//  Copyright (c) 2015 Gregory Moon. All rights reserved.
//

#include "CoveringArray.h"

CoveringArray::CoveringArray(std::vector<std::vector<int>> values, int colsInSubArray, int numDistinctElements){
    this->values = values;
    this->columns.resize(values[0].size());
    
    this->createColumns();
    
    this->occurenceArray = new OccurenceArray(this->columns, colsInSubArray, numDistinctElements);
    this->occurenceLocationArray = new OccurenceLocationArray(values, this->occurenceArray->getTable());
    
    this->modifyOriginal();
}   //end constructor

bool CoveringArray::validCoveringArray(){
    return this->occurenceArray->validCoveringArray();
}

void CoveringArray::createColumns(){
    for(int i = 0; i < this->columns.size(); i++){
        Column *newColumn = new Column(this->values.size());
        
        for(int j = 0; j < this->values.size(); j++)
            newColumn->add(this->values[j][i]);
        
        this->columns[i] = newColumn;
    }
}   //end createColumns

void CoveringArray::modifyOriginal(){
    std::vector<std::vector<int>> arrToCheck = occurenceLocationArray->getCounts();
    this->modifiedValues.resize(arrToCheck.size());
    
    
    for(int i = 0; i < arrToCheck.size(); i++){
        std::vector<string> newVec(arrToCheck[i].size());
        this->modifiedValues[i] = newVec;
        for(int j = 0; j < arrToCheck[i].size(); j++){
            if(arrToCheck[i][j] == 0)
                this->modifiedValues[i][j] = "*";
            else{
                int value = values[i][j];
                string charToAdd = std::to_string(value);
                modifiedValues[i][j] = charToAdd;
            }
        }
    }
}	//end modifyOriginal

std::vector<std::vector<std::string>> CoveringArray::getModifiedValues(){
    return this->modifiedValues;
}

