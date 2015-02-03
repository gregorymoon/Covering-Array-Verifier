//
//  OccurenceLocationArray.cpp
//  CSE 430 Individual Project 1
//
//  Created by Gregory Moon on 1/22/15.
//  Copyright (c) 2015 Gregory Moon. All rights reserved.
//

#include "OccurenceLocationArray.h"

OccurenceLocationArray::OccurenceLocationArray(std::vector<std::vector<int>> values, std::unordered_map<OccurenceArrayKey *, int> occurenceArr){
    this->occurenceArr = occurenceArr;
    
    for(int i = 0; i < values.size(); i++){
        std::vector<int> newVec(values[0].size());
        counts.push_back(newVec);
    }
    
    initCounts();
    populateCounts();
}	//end init

std::vector<std::vector<int>> OccurenceLocationArray::getCounts(){
    return this->counts;
}	//end getCounts

void OccurenceLocationArray::populateCounts(){
    for(auto it = this->occurenceArr.begin(); it != this->occurenceArr.end(); it++){
        OccurenceArrayKey *key = it->first;
        
        if(occurenceArr[key] == 1){
            int row = findLocation(key->getCols(), key->getVals());
            for(int i = 0; i < key->getCols().size(); i++)
                counts[row][key->getCols()[i]->getColNum()]++;
        }
    }
}	//end populateCounts


int OccurenceLocationArray::findLocation(std::vector<Column *> cols, std::vector<int> integers){
    int val1, val2, val3, retVal = -1;
    Column *col1, *col2, *col3;
    
    switch(cols.size()){
        case 1:
            col1 = cols[0];
            val1 = integers[0];
            
            for(int i = 0; i < col1->length(); i++){
                int val1ToCheck = col1->get(i);
                
                if(val1ToCheck == val1){
                    retVal = i;
                    break;
                }
            }
            break;
        case 2:
            col1 = cols[0];
            col2 = cols[1];
            val1 = integers[0];
            val2 = integers[1];
            
            for(int i = 0; i < col1->length(); i++){
                int val1ToCheck = col1->get(i), val2ToCheck = col2->get(i);
                
                if(val1ToCheck == val1 && val2ToCheck == val2){
                    retVal = i;
                    break;
                }
            }
            break;
        case 3:
            switch(integers.size()){
                case 1:
                    col1 = cols[0];
                    col2 = cols[1];
                    col3 = cols[2];
                    val1 = integers[0];
                    
                    for(int i = 0; i < col1->length(); i++){
                        int val1ToCheck = col1->get(i), val2ToCheck = col2->get(i), val3ToCheck = col3->get(i);
                        
                        if(val1ToCheck == val1 || val2ToCheck == val1 || val3ToCheck == val1){
                            retVal = i;
                            break;
                        }
                    }
                    break;
                case 2:
                    col1 = cols[0];
                    col2 = cols[1];
                    col3 = cols[2];
                    val1 = integers[0];
                    val2 = integers[1];
                    
                    for(int i = 0; i < col1->length(); i++){
                        int val1ToCheck = col1->get(i), val2ToCheck = col2->get(i), val3ToCheck = col3->get(i);
                        
                        if((val1ToCheck == val1 && val2ToCheck == val2) || (val1ToCheck == val1 && val3ToCheck == val2) || (val2ToCheck == val1 && val3ToCheck == val2)){
                            retVal = i;
                            break;
                        }
                    }
                    break;
                case 3:
                    col1 = cols[0];
                    col2 = cols[1];
                    col3 = cols[2];
                    val1 = integers[0];
                    val2 = integers[1];
                    val3 = integers[2];
                    
                    for(int i = 0; i < col1->length(); i++){
                        int val1ToCheck = col1->get(i), val2ToCheck = col2->get(i), val3ToCheck = col3->get(i);
                        
                        if(val1ToCheck == val1 && val2ToCheck == val2 && val3ToCheck == val3){
                            retVal = i;
                            break;
                        }
                    }
                    break;
            }
            break;
    }
    
    return retVal;
}	//end findLocation

void OccurenceLocationArray::initCounts(){
    for(int i = 0; i < counts.size(); i++){
        for(int j = 0; j < counts[i].size(); j++)
            counts[i][j] = 0;
    }
}	//end initCounts