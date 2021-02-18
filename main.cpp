//
//  main.cpp
//  Project3
//
//  Created by Max Matkovski on 1/30/21.
//

#include <iostream>
#include <string>
using namespace std;

// Declare Functions

bool isValidBatchString (string results);
bool isValidResultString (string results);
bool negativeTests (string results);
bool totalTests (string results);
int batches (string results);


int main (){
    
    string input = "Ra1=1=";
    
    //Outcome = isValidResultString (input);
    bool outcome = isValidResultString(input);
    if (outcome)
        cout << "valid" << endl;
    else
        cout << "invalid" << endl;
        
    return 0;
    
}


    // Checks Single Batch
    bool isValidBatchString (string results){
    if (results [0] == 'R')
    {
        if (results [1] == '0'){
           return false;
        }
      
        if (!isdigit(results[1]))
            return false;
        
        // Calculating Value for Total String
        int i = 1;
        string totalTestsString = "";
        while (isdigit(results [i])){
            totalTestsString = totalTestsString + results[i];
            i++;
        }
        
        int totalTests;
        totalTests = stoi(totalTestsString);

        // Calculating Second Int
        int b = i+1;
        string totalPositiveString = "";
        while (isdigit(results[b])){
            totalPositiveString = totalPositiveString + results[b];
            b++;
    
        }
        
        // Precaution to avoid no empty positive cases
        if (totalPositiveString == ""){
            return false;
        }
            
        int totalPositiveTests;
        totalPositiveTests = stoi(totalPositiveString);
        
        // Calculating Third Int
        int c = b+1;
        string totalNegativeString = "";
        while (isdigit(results[c])){
            totalNegativeString = totalNegativeString + results[c];
            c++;
        }
        
        // Precaution to avoid no empty negative cases
        if (totalNegativeString == ""){
            return false;
        }
            
        int totalNegativeTests;
        totalNegativeTests = stoi(totalNegativeString);
       
        // Calculating totalSum and Valdiating for Equality
        int totalSum;
        totalSum = totalNegativeTests + totalPositiveTests;
        if(totalSum != totalTests){
            return false;
        }
        
        if (c != results.length()){
            return false;
        }
        return true;
    }
    return false;
}


bool isValidResultString (string results) {
    
    int startOfBatchIndex = 0;
    string batch = "";
        
    if (results[0] != 'R')
        return false;
    
    for (int i = 0; i < results.length(); i++) {
        if ((results[i] == 'R' && i != 0) || i == results.length()-1) {
            if (i == results.length()-1)
                i++;
            int len = i - startOfBatchIndex;
            batch = results.substr(startOfBatchIndex,len);
                        
            if (!isValidBatchString(batch))
                return false;
            
            startOfBatchIndex = i;
        }
    }
    
    return true;
}



