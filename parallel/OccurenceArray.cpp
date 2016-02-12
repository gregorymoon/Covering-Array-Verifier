//
//  OccurenceArray.cpp
//  CSE 430 Individual Project 1
//
//  Created by Gregory Moon on 1/22/15.
//  Copyright (c) 2015 Gregory Moon. All rights reserved.
//

#include "OccurenceArray.h"

#include <unordered_map>
#include <omp.h>
#include <ctime>

omp_lock_t tableMutex;

OccurenceArray::OccurenceArray(std::vector<Column *> columns, int colsInSubArray, int numDistinctElements){
    this->columns = columns;
    this->colsInSubArray = colsInSubArray;
    this->numDistinctElements = numDistinctElements;
    this->calc = new Calculator();
    
    this->generateDistinctElementCombinations();
    this-> generateColumnCombinations();
    this->generateOccurenceArrayKeys();
    this->initializeTable();
    this->updateTable();
}

std::vector<OccurenceArrayKey *> OccurenceArray::getOccurenceArrayKeys(){
    return this->occurenceArrayKeys;
}

std::unordered_map<OccurenceArrayKey *, int> OccurenceArray::getTable(){
    return this->table;
}

void OccurenceArray::updateTable(){
//	#pragma omp parallel for
    for(int i = 0; i < this->occurenceArrayKeys.size(); i++){
        OccurenceArrayKey * key = this->occurenceArrayKeys[i];
        
        std::vector<Column *> cols = key->getCols();
        std::vector<int> vals = key->getVals();
        
        switch(cols.size()){
            case 1:
                for(int i = 0; i < cols[0]->length(); i++){
                    int val1ToCheck = cols[0]->get(i);
                    
                    if(val1ToCheck == vals[0])
                        table[key] = table[key] + 1;
                }
                break;
            case 2:
                switch (vals.size()) {
                    case 1:
                        for(int i = 0; i < cols[0]->length(); i++){
                            int val1ToCheck = cols[0]->get(i), val2ToCheck = cols[1]->get(i);
                            
                            if(val1ToCheck == vals[0] || val2ToCheck == vals[0])
                                table[key] = table[key] + 1;
                        }
                        break;
                    case 2:
		//		#pragma omp parallel for
                        for(int i = 0; i < cols[0]->length(); i++){
                                omp_set_lock(&tableMutex);
                            int val1ToCheck = cols[0]->get(i), val2ToCheck = cols[1]->get(i);

			if (val1ToCheck == vals[0] && val2ToCheck == vals[1]){
				table[key] = table[key] + 1;
			}
                                omp_unset_lock(&tableMutex);
        	}
                        break;

    		}

                break;
            case 3:
                switch (vals.size()) {
                    case 1:
                        for(int i = 0; i < cols[0]->length(); i++){
                            int val1ToCheck = cols[0]->get(i), val2ToCheck = cols[1]->get(i), val3ToCheck = cols[2]->get(i);
                            
                            if(val1ToCheck == vals[0] || val2ToCheck == vals[0] || val3ToCheck == vals[0] )
                                table[key] = table[key] + 1;
                        }
                        break;
                    case 2:
                        for(int i = 0; i < cols[0]->length(); i++){
                            int val1ToCheck = cols[0]->get(i), val2ToCheck = cols[1]->get(i), val3ToCheck = cols[2]->get(i);
                            
                            if((val1ToCheck == vals[0] && val2ToCheck == vals[1]) || (val2ToCheck == vals[0] && val3ToCheck == vals[1]) || (val1ToCheck == vals[0] && val3ToCheck == vals[1]))
                                table[key] = table[key] + 1;
                        }
                        break;
                    case 3:
                        for(int i = 0; i < cols[0]->length(); i++){
                            int val1ToCheck = cols[0]->get(i), val2ToCheck = cols[1]->get(i), val3ToCheck = cols[2]->get(i);
                            
                            if(val1ToCheck == vals[0] && val2ToCheck == vals[1] && val3ToCheck == vals[2])
                                table[key] = table[key] + 1;
                        }
                        break;
                }
                
                break;
        }
    }    
}   //end updateTable

bool OccurenceArray::validCoveringArray(){
    for(int i = 0; i < this->occurenceArrayKeys.size(); i++){
        OccurenceArrayKey * key = this->occurenceArrayKeys[i];
      
        if(table[key] == 0)
            return false;
    }
    
    return true;
}

void OccurenceArray::initializeTable(){
	#pragma omp parallel for
	for (int i = 0; i < this->occurenceArrayKeys.size(); i++){
		omp_set_lock(&tableMutex);
		table[this->occurenceArrayKeys[i]] = 0;
		omp_unset_lock(&tableMutex);
	}
}	//end initializeTable

void OccurenceArray::generateOccurenceArrayKeys(){
	#pragma omp parallel for
    for(int i = 0; i < this->columnCombinations.size(); i++){
		omp_set_lock(&tableMutex);
        std::vector<Column *> col = this->columnCombinations[i];

	//	#pragma omp parallel for
        for(int j = 0; j < this->distinctElementCombinations.size(); j++){
            std::vector<int> val = this->distinctElementCombinations[j];
            OccurenceArrayKey * newKey = new OccurenceArrayKey(col, val);
            occurenceArrayKeys.push_back(newKey);
        }
		omp_unset_lock(&tableMutex);
    }
}	//end generateOccurenceArrayKeys

void OccurenceArray::generateDistinctElementCombinations(){
    std::vector<int> elementsToPermute(this->numDistinctElements);
    
    for(int i = 0; i < elementsToPermute.size();  i++)
        elementsToPermute[i] = i;
    
    //distinctElementCombinations = Calculator::permute(elementsToPermute, numDistinctElements);
    this->distinctElementCombinations = calc->permute(elementsToPermute, this->colsInSubArray);
}	//end generateDistinctElementCombinations

void OccurenceArray::generateColumnCombinations(){
    columnCombinations = calc->getColumnCombinations(columns, colsInSubArray);
}	//end setColCombinations
