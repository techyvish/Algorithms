//
//  CutTheRod.cpp
//  AlgorithmTutorials
//
//  Created by Vishal on 25/07/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#include "CutTheRod.h"

using namespace std;
int maximum(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int CutTheRod::cutTheRod(int s, int e) {
	if (e == 0) {
		B[0] = V[0];
		return B[0];
	}
	else {
		int max = -1;
		for (int p = s ; p < e; p++) {
			if (B[e - p] == -1) {
                int c = cutTheRod(s, e - 1);
                cout << "V["<<s<<"] " << V[s] << " cutTheRoad " << c << endl;
				B[e - p] = V[s] + c;
                max = B[e-p];
            }
            cout << "**V[" << p << "] " <<  V[p] << " B[" << e << "-" << p << "] " << B[e - p - 1] << endl;
            if ( p != s ){
                if (max < V[p] + B[e - p - 1 ]) // we already haver from B[e-p] now we need results from B[e-p-1]
                    max = V[p] + B[e - p - 1 ];
            }
		}
		B[e] = maximum(max, V[e]);
		cout << "B[" << e << "] " << B[e] << endl ;
		return B[e];
	}
}

void CutTheRod::run() {
	this->cutTheRod(0, 7);
    for ( int  i = 0 ; i < 8 ; i ++ )
        cout << B[i] << ",";
    cout << endl;
}
