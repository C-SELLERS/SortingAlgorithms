#include<iostream>
#include<sys/time.h>
#include<algorithm>  // sort
#include<vector>
#include<stdlib.h> // random
#include<time.h>   // time()
#include<climits>  // max int
#include "InsertionSort.h"
#include "RadixSort.h"

using namespace std;

bool isSorted(vector<int> v) {
	int prev = -1;
	for (auto val : v) {
		if (prev > val) {
			return false;
		}
		prev = val;
	}
	return true;
}

int main (int argc, char** argv) {
	if (argc != 2) {
		cout << "Enter size of array on the command line" << endl;
		return -1;
	}

	struct timeval start, end; // for timing
	long seconds, useconds;
	double timeA, timeB, timeC;

	int vectorsize = atoi(argv[1]);

	srand(time(NULL)); // seed with current time
	vector<int> unsortedA;
	vector<int> unsortedB;
	vector<int> unsortedC;
	for (int i = 0; i < vectorsize; i++) {
		int temp = rand() % INT_MAX;
		unsortedA.push_back(temp);
		unsortedB.push_back(temp);
		unsortedC.push_back(temp);
	}

	//A: Insertion Sort
	gettimeofday(&start, NULL);
	InsertionSort(unsortedA.begin(),unsortedA.end());
	gettimeofday(&end, NULL);

	seconds = end.tv_sec - start.tv_sec;
	useconds = end.tv_usec - start.tv_usec;

	timeA = seconds + useconds/1000000.0;

	//B: Radix Sort
    gettimeofday(&start, NULL);
	RadixSort(unsortedB.begin(),unsortedB.end());
    gettimeofday(&end, NULL);

    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;

    timeB = seconds + useconds/1000000.0;


	//C: std::sort
    gettimeofday(&start, NULL);
    sort(unsortedC.begin(),unsortedC.end());
    gettimeofday(&end, NULL);

    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;

    timeC = seconds + useconds/1000000.0;

	if (!(isSorted(unsortedA) and isSorted(unsortedB) and isSorted(unsortedC))) {
		cout << "Sort failed" << endl;
		return -1;
	}

	cout << "Insertion Sort: " << timeA << endl;	
	cout << "Radix Sort: " << timeB << endl;
	cout << "std::sort: " << timeC << endl;


	return 0;

}
