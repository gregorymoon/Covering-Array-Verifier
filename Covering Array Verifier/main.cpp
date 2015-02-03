//
//  main.cpp
//  CSE 430 Individual Project 1
//
//  Created by Gregory Moon on 1/21/15.
//  Copyright (c) 2015 Gregory Moon. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

#include "CoveringArray.h"

static CoveringArray* coveringArrFromFile(std::string filename);
static void printArr(std::vector<std::vector<int>> arr);
static void printArr(std::vector<std::vector<std::string>> arr);

int main(int argc, const char * argv[]) {
    std::string filename = argv[1];
    
    CoveringArray *ca = coveringArrFromFile(filename);
    
    if(ca->validCoveringArray()){
        std::cout << filename << ": pass" << std::endl;
        std::cout << "Modified Values:" << std::endl;
        printArr(ca->getModifiedValues());
        std::cout << std::endl;
    }
    else
        std::cout << filename << ": fail\n" << std::endl;

    return 0;
}   //end main

static void printArr(std::vector<std::vector<std::string>> arr){
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size(); j++)
            std::cout << arr[i][j] << " ";
        
        std::cout << std::endl;
    }
}	//end printArr

static void printArr(std::vector<std::vector<int>> arr){
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size(); j++)
            std::cout << arr[i][j] << " ";
        
        std::cout << std::endl;
    }
}	//end printArr

/*
 
 */
static CoveringArray* coveringArrFromFile(std::string filename){
    const int NUM_PARAMS = 4;
    int params[4];
    
    std::ifstream inFile;
    std::string input, buff;
    
    inFile.open(filename);
    
    if(inFile.is_open()){
        for(int i = 0; i < NUM_PARAMS; i++){
            bool first = true;
            
            do{
                if(first){
                    first = false;
                    input = inFile.get();
                    buff = inFile.get();
                }
                else{
                    input += buff;
                    buff = inFile.get();
                }
                
            }while(buff != " " && buff != "\n");
            
            params[i] = stoi(input);
        }
        
        int numRows = params[0], strength = params[1], numCols = params[2], numDistinctVals = params[3];
        std::vector<std::vector<int>> values;
        
        for(int i = 0; i < numRows; i++){
            std::vector<int> row;
            values.push_back(row);
            for(int j = 0; j < numCols; j++){
                do{
                    input = inFile.get();
                }while(input == " " || input == "\n");
                
                values[i].push_back(stoi(input));
            }
        }
        
        CoveringArray *ca = new CoveringArray(values, strength, numDistinctVals);
        return ca;
    }
    else
        throw "Unable to read file";
}	//end coveringArrFromFile