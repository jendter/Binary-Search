//
//  main.c
//  Binary Search
//
//  Created by Josh Endter on 6/9/15.
//  Copyright (c) 2015 Josh Endter. All rights reserved.
//

#include <stdio.h>

// Define structs
typedef struct {
    int firstOccurrence;
    int numberOfTimes;
} indexRange;

// Define functions
int findIndex(int numToFind, int arrayToSearchThrough[], int minArrayIndex, int maxArrayIndex);
indexRange findBinary(int numToFind, int arrayToSearchThrough[], int minArrayIndex, int maxArrayIndex);


int main(int argc, const char * argv[]) {
    
    int testArray[20] = {2, 3, 3, 8, 13, 17, 26, 48, 73, 103, 140, 140, 140, 177, 177, 444, 444, 552, 773, 965};
    
    int part1Index = findIndex(177, testArray, 0, 20);
    printf("Part 1 \nIndex value: %d \n\n", part1Index);
    
    indexRange testingRange = findBinary(140, testArray, 0, 20);
    printf("Part 2 \nFirst Index Value: %d \nNumber of occurrences: %d \n", testingRange.firstOccurrence, testingRange.numberOfTimes);
    
    return 0;
}

int findIndex(int numToFind, int arrayToSearchThrough[], int minArrayIndex, int maxArrayIndex) {
    
    int indexOfNumToFind = -1;
    
    int midpoint = (minArrayIndex + maxArrayIndex) / 2;
    
    if (maxArrayIndex < minArrayIndex) {
        indexOfNumToFind = -1;
        return indexOfNumToFind;
    } else {
        
        if (numToFind < arrayToSearchThrough[midpoint]){
            return findIndex(numToFind, arrayToSearchThrough, minArrayIndex, midpoint-1);
        } else if (numToFind > arrayToSearchThrough[midpoint]) {
            return findIndex(numToFind, arrayToSearchThrough, midpoint+1, maxArrayIndex);
        } else if (numToFind == arrayToSearchThrough[midpoint]) {
            return midpoint;
        }
        
    }
    
    return indexOfNumToFind;
    
    
}

indexRange findBinary(int numToFind, int arrayToSearchThrough[], int minArrayIndex, int maxArrayIndex) {
    
    indexRange range;
    
    int midpoint = (minArrayIndex + maxArrayIndex) / 2;

    if (maxArrayIndex < minArrayIndex) {
        range.firstOccurrence = -1;
        range.numberOfTimes = 0;
        return range;
    } else {
        
        if (numToFind < arrayToSearchThrough[midpoint]){
            return findBinary(numToFind, arrayToSearchThrough, minArrayIndex, midpoint-1);
        } else if (numToFind > arrayToSearchThrough[midpoint]) {
            return findBinary(numToFind, arrayToSearchThrough, midpoint+1, maxArrayIndex);
        } else if (numToFind == arrayToSearchThrough[midpoint]) {
            
            
            for (int movingMidpoint = midpoint; arrayToSearchThrough[movingMidpoint] == numToFind; movingMidpoint--) {
                range.firstOccurrence = movingMidpoint;
            }
            
            int numOfOccurrences = 0;
            for (int movingMidpoint = range.firstOccurrence; arrayToSearchThrough[movingMidpoint] == numToFind; movingMidpoint++) {
                numOfOccurrences++;
                range.numberOfTimes = numOfOccurrences;
            }
            
            return range;
            
        }

        
    }
    
    return range;
    

}