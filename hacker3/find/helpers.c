/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int array[], int begin, int end)
{
    // TODO: implement a searching algorithm
    if (end <= 0) return false;
    else
    {
        /**
         * Linear search
        for (int i = 0; i < n; i++){
            if (array[i] == value) return true;
        }
        */
        //Recursive search
        if ((end - begin) <=1) return (array[end] == value || array[begin] == value);
        int middle = (begin + end)/2;
        if (array[middle] == value) return true;
        if (array[middle] > value)
            return search(value, array, begin, middle);
        else
            return search(value, array, middle, end);
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n) sorting algorithm
    for (int i = 0; i < n; i++){
        int element = values[i];
        int j = i;
        while (j > 0 && values[j-1] > element){
            values[j] = values[j-1];
            j--;
        }
        values[j] = element;
    }
    return;
}