//
//  QuickSort.cpp
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 11/09/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#include "QuickSort.h"

using namespace std;
void QuickSort::print(int a[]) {
	for (int i = 0; i <= 8; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int QuickSort::calculatePivote(int a[], int start, int end) {
	int pivoteIndex = end;
	int j = pivoteIndex - 1;
	int i = start;
	while (true) {
		if (i > j)
			break;
		if (a[i] > a[pivoteIndex]) {
			int temp = a[i]; a[i] = a[j]; a[j] = temp;
			if (a[j] > a[pivoteIndex]) {
				int temp = a[j]; a[j] = a[pivoteIndex]; a[pivoteIndex] = temp;
				pivoteIndex = j;
				j--;
			}
		}
		else {
			i++;
		}
	}
	return pivoteIndex;
}

void QuickSort::quickSortThis(int a[], int start, int end) {
	if (start > end)
		return;
    
	int r = calculatePivote(a, start, end);
    
	quickSortThis(a, start, r - 1);
	quickSortThis(a, r + 1, end);
}

void QuickSort::Run() {
	int a[] = { 3, 7, 8, 5, 2, 1, 9, 5, 4 };
	quickSortThis(a, 0, 8);
    print(a);
}
