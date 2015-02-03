//
//  Calculator.cpp
//  CSE 430 Individual Project 1
//
//  Created by Gregory Moon on 1/30/15.
//  Copyright (c) 2015 Gregory Moon. All rights reserved.
//

#include "Calculator.h"

Calculator::Calculator(){
    
}

int Calculator::choose(int n, int k){
     return factorial(n)/factorial(k)*factorial(n-k);
}   //end choose

int Calculator::factorial(int num){
    if(num == 0 || num == 1)
        return 1;
    
    return num * factorial(num - 1);
}   //end factorial

void Calculator::permute(std::vector<int> c, int n, std::vector<int> start){
    if(start.size() >= n){{
        std::vector<int> newVector(start.begin(),start.end());
        this->permutationList.push_back(newVector);
    }
    }else{
        for(int x : c){ // not a valid syntax in Java
            start.push_back(x);
            permute(c, n, start);
            start.pop_back();
        }
    }
}

std::vector<std::vector<int>> Calculator::permute(std::vector<int> valsToPermute, int elementsInPermutation){
    this->permutationList.clear();
    for(int i = 0; i < valsToPermute.size(); i++){
        std::vector<int> generatePermutationsList;
        generatePermutationsList.push_back(valsToPermute[i]);
        
        permute(valsToPermute, elementsInPermutation, generatePermutationsList);
    }
    
    return this->permutationList;
}

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
}

                                          
std::vector<std::vector<Column *>> Calculator::getColumnCombinations(std::vector<Column *> arr, int r){
    std::vector<Column *> data(r);
    this->columnCombinationList.clear();
    
    getColumnCombinations(arr, data, 0, arr.size() - 1, 0, r);
    
    return this->columnCombinationList;
}