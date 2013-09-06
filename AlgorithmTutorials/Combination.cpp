//
//  Combination.cpp
//  AlgorithmTutorials
//
//  Created by Vishal on 25/06/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#include "Combination.h"
#include <iostream>

using namespace std;

void Combination::combination(int a[], int k, int n) {
	if (k == n) {
		a[k] = 0;  cout << a[1] << "," << a[2] << "," << a[3] << endl;
		a[k] = 1;  cout << a[1] << "," << a[2] << "," << a[3] << endl;
		return;
	}
	a[k] = 0;
	combination(a, k + 1, n);
	a[k] = 1;
	combination(a, k + 1, n);
}
