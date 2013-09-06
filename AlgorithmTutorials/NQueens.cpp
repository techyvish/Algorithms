//
//  NQueens.cpp
//  AlgorithmTutorials
//
//  Created by Vishal on 4/07/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#include "NQueens.h"
using namespace std;

bool NQueens :: place(int k /*row*/, int i /*column*/) { // can I place queen on in this cell ?
	for (int j = 1; j <= k; j++) {
		{
			for (int p = 1; p <= k - 1; p++) { // can I place queen in ith colun ??
				if (x[p] == i) {
					return false;
				}
			}
            
			{
				bool t = true;
				for (int p = 1; p <= k - 1; p++) {
					if (abs(x[p] - i) == abs(p - k)) {  // whith all row check that current position is diagonally shared by any queen in any row ??
						t &= false;
					}
				}
				return t;
			}
		}
	}
	return false;
}

void NQueens :: nqueens(int k, int n) {
	for (int i = 1; i <= n; i++) {
		if (place(k, i)) {
			x[k] = i;
			if (k == n) {
				printQueenLocations(x, n);
			}
			nqueens(k + 1, n);
		}
	}
}

void NQueens :: printQueenLocations(int *x, int n) {
	for (int i = 1; i <= n; i++) {
		cout << x[i] << ",";
	}
	cout << endl;
}

void NQueens :: run() {
	nqueens(1, 4);
}
