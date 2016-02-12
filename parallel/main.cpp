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
#include <time.h>
#include <omp.h>
#include "CoveringArray.h"

//nothing
#include <string>

//forward declarations
static CoveringArray* coveringArrFromFile(std::string filename);
static void printArr(std::vector<std::vector<std::string>> arr);

/*
 main:
    The main method reads a filename from stdin and processes the array described within it. If the array is a valid covering array, the program will output that the array is valid, will identify potential don't care positions in the array and will mark them with an asterisk (*) before outputting the modified array to stdout.
 */

int main(int argc, const char * argv[]) {


	int start_s = clock();
    std::string filename = argv[1];
    
    CoveringArray *ca = coveringArrFromFile(filename);
    
    if(ca->validCoveringArray()){
        std::cout << filename << ": pass" << std::endl;
        std::cout << "Modified Values:" << std::endl;
        printArr(ca->getModifiedValues());
        std::cout << "Don't Cares: " << std::endl;
        
        std::vector<std::vector<int>> dontCares = ca->getDontCarePositions();
        
		int maxIdx = dontCares.size() - 1;

		#pragma omp parallel for
		for (int i = 0; i < maxIdx; i++)
			std::cout << "(" << dontCares[i][0] << ", " << dontCares[i][1] << "), ";
		
		std::cout << "(" << dontCares[maxIdx][0] << ", " << dontCares[maxIdx][1] << ")\n" << std::endl;
    }
    else
        std::cout << filename << ": fail\n" << std::endl;

	int stop_s = clock();

	cout << "time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) << endl;

    return 0;
}   //end main

/*
 printArr:
    This method simply prints a 2d array of strings
    
    input parameters:
        arr: a 2d array of strings
 */

static void printArr(std::vector<std::vector<std::string>> arr){
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size(); j++){
            if(j != arr[i].size() - 1)
                std::cout << arr[i][j] << " ";
            else
                std::cout << arr[i][j] << std::endl;
        }
    }
}	//end printArr

/*
 coveringArrayFromFile:
    This method creates a CoveringArray from a file continging information about a particular array
 
    input parameters:
        filename: the filepath to a file containing information about a covering array with the format N t k v followed by N rows with k columns with elements ranging from 0 to v - 1 where v <= 3. For example:
                3 2 3 2
                0 1 0
                0 0 0
                1 1 0
    output:
        A CoveringArray object created form the input file information is returned.
 */

static CoveringArray* coveringArrFromFile(std::string filename){
    const int NUM_PARAMS = 4;
    int params[NUM_PARAMS];
    
    std::ifstream inFile;
    
    inFile.open(filename);
    
    if(inFile.is_open()){
        std::string input, buff;
        
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
            values.push_back(*new std::vector<int>());
            
            for(int j = 0; j < numCols; j++){
                do{
                    input = inFile.get();
                }while(input == " " || input == "\n");
                
                values[i].push_back(stoi(input));
            }
        }
        
        return new CoveringArray(values, strength, numDistinctVals);
    }
    else
        throw "Unable to read file";
}	//end coveringArrFromFile