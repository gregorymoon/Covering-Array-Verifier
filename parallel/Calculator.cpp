//
//  Calculator.cpp
//  CSE 430 Individual Project 1
//
//  Created by Gregory Moon on 1/30/15.
//  Copyright (c) 2015 Gregory Moon. All rights reserved.
//

#include "Calculator.h"

Calculator::Calculator(){}  //end init
/*
 Calculator:
    this class just contains some support methods for different functions performed by different classes.
 */

/*
 choose:
    binomial coefficient
 */

int Calculator::choose(int n, int k){
     return factorial(n)/factorial(k)*factorial(n-k);
}   //end choose

/*
 factorial:
    calculates factorial
 */

int Calculator::factorial(int num){
    if(num == 0 || num == 1)
        return 1;
    
    return num * factorial(num - 1);
}   //end factorial

/*
 permute:
    calculates all permutations of elements in the input array
 */

void Calculator::permute(std::vector<int> input, int size, std::vector<int> start){
    if(start.size() >= size){{
        std::vector<int> newVector(start.begin(),start.end());
        this->permutationList.push_back(newVector);
    }
    }else{
        for(int i = 0; i < input.size(); i++){
            int x = input[i];
            start.push_back(x);
            permute(input, size, start);
            start.pop_back();
        }
    }
}   //end permute (private)

/*
 permute:
    public method used to pass the appropriate variables to the private method with the same name which finds all the permutations in n elements of a set of size k.
 */

std::vector<std::vector<int>> Calculator::permute(std::vector<int> valsToPermute, int elementsInPermutation){
    this->permutationList.clear();
    for(int i = 0; i < valsToPermute.size(); i++){
        std::vector<int> generatePermutationsList;
        generatePermutationsList.push_back(valsToPermute[i]);
        
        permute(valsToPermute, elementsInPermutation, generatePermutationsList);
    }
    
    return this->permutationList;
}   //end permute (public)

/*
 getColumnCombinations:
    get all combinations of the columns included in the input array. derived from a similar method found at http://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/
 */

void Calculator::getColumnCombinations(std::vector<Column *> arr, std::vector<Column *> data, int start, unsigned long end, int idx, int r){
    if(idx == r){
        std::vector<Column *> listToAdd;
        
        for(int i = 0; i < r; i++)
            listToAdd.push_back(data[i]);
        
        this->columnCombinationList.push_back(listToAdd);
        return;
    }
    
    for(int i = start; i <= end && end - i + 1 >= r - idx; i++){
        data[idx] = arr[i];
        getColumnCombinations(arr, data, i+1, end, idx+1, r);
    }
}   //end getColumnCombinations (private)

/*
 getColumnCombinations:
    public version of the method is used just to pass appropriate parameters to private version which does all of the work. The columnCombinationList is populated with all of the differenc combinations of columns in the covering array that need to be checked for t-set values
    
        input parameters:
            arr: 
                the array of Columns that need to be arranged into different combinations
            colsInSubArray:
                the number of columns in each subarray that needs to be checked for t-set values. it is the same number as the "t" parameter in the original N t k v values that were passed in from a file.
    
        return value:
            the array of arrays of columns that represents every possible combination subarrays in the original array.
 */
                                          
std::vector<std::vector<Column *>> Calculator::getColumnCombinations(std::vector<Column *> arr, int colsInSubArray){
    std::vector<Column *> data(colsInSubArray);
    this->columnCombinationList.clear();
    
    getColumnCombinations(arr, data, 0, arr.size() - 1, 0, colsInSubArray);
    
    return this->columnCombinationList;
}   //end getColumnCombinations (public)