//
// Created by Colton on 2/17/2019.
//

#include "RadixSort.h"
#include <vector>
#include <algorithm>


using namespace std;

//Sorts the vector using radix sort
RadixSort::RadixSort(vector<int>::iterator begin, vector<int>::iterator end){
        int maxValue = *(max_element(begin, end));
        vector<vector<int>> buckets(10);

        int i=1;
        while ( maxValue != 0 ) {
            //Put numbers in buckets
            for (auto iter = begin; iter != end; ++iter) {
                int num = *iter;
                int remainder = (num / i) % 10;
                buckets[remainder].push_back(num);
            }

            //Move them back to original vector
            auto iter = begin;
            for (auto const &bucket1:buckets) {
                for (auto value: bucket1) {
                    *iter = value;
                    ++iter;
                }

            }

            //Clear the buckets
            for (int j = 0; j < 10; j++) {
                buckets[j].clear();
            }

            maxValue /= 10;
            i *= 10;
        }
}

