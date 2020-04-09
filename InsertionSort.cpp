//
// Created by Colton on 2/17/2019.
//


#include "InsertionSort.h"
#include <bits/stdc++.h>

using namespace std;

//Sorts the vector using insertion sort
InsertionSort::InsertionSort(vector<int>::iterator begin, vector<int>::iterator end)
{
    for (auto it = begin; it != end; ++it)
        rotate(upper_bound(begin, it, *it), it, next(it));
}

