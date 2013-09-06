//
//  RecursiveLoop.cpp
//  AlgorithmTutorials
//
//  Created by Vishal on 24/06/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#include "RecursiveLoop.h"
#include <iostream>

using namespace std;

RecursiveLoop::RecursiveLoop() {
}

void RecursiveLoop::printLoop(int a[], int k, int n) {
	for (int i = 1; i <= 3; i++) {
		a[k] = i;
		if (k < 3)
			printLoop(a, k + 1, n);
		else
			cout << a[1] << "," << a[2] << "," << a[3] << endl;
	}
}
