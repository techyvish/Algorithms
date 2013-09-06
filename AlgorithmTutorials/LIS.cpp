//
//  LIS.cpp
//  AlgorithmTutorials
//
//  Created by Vishal on 22/07/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#include "LIS.h"
using namespace std;

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int MSS :: mss(int arr[], int n) {
	if (n == 0) {
		s[n] = arr[n];
		return s[n];
	}
	else {
		s[n] = max((mss(arr, n - 1) + arr[n]), arr[n]);
		if (s[n] != arr[n]) {
			cout << arr[n - 1] << ",";
		}
		return s[n];
	}
}

void MSS :: run() {
	s = (int *)malloc(sizeof(int) * 8);
	int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
	mss(arr, 8);
	cout << endl;
	free(s);
}
