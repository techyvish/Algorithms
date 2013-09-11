//
//  Permutations.cpp
//  AlgorithmTutorials
//
//  Created by Vishal on 25/06/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#include "Permutations.h"
#include <iostream>

using namespace std;

Permutations::Permutations() {
}

void Permutations::permutations(char a[], int k, int n) {
	if (k == n) {
        cout << 3 << "," << k << endl;
        cout << a << endl;
	}
	else {
		for (int i = k; i <= n; i++) {
			cout << i << "," << k << endl;
			int t = a[k]; a[k] = a[i]; a[i] = t;
			permutations(a, k + 1, n);
			//cout << ">>>>>>" << i << "," << k << endl;
			t = a[k]; a[k] = a[i]; a[i] = t;
		}
	}
}
