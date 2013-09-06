//
//  GraphColoring.cpp
//  AlgorithmTutorials
//
//  Created by Vishal on 7/07/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#include "GraphColoring.h"
// TODO: make generic and add comments.
using namespace std;

GraphColoring::GraphColoring() {
	m = 3;
	x[1] = 1;
}

void GraphColoring :: cerateAdjecencyMatrix() {
}

void GraphColoring :: colorGraph(int k, int n) {
	do {
		x[k] = getNodeColor(k);
		if (k == n) {
			printNodeColors();
			return;
		}
		else colorGraph(k + 1, n);
	}
	while (true);
}

int GraphColoring :: getNodeColor(int k) {
	do {
		printf("%d+1 mod %d+1 ", x[k], m); cout << endl;
		x[k] = (x[k] + 1) % (m + 1);
		cout << "X[" << k << "]=" << x[k] << endl;
		if (x[k] == 0) return x[k];
        
		int j = 1;
		for (j = 1; j <= 4; j++) {
			cout << "G[" << k << "][" << j << "]=" << G[k][j] << endl;
			if (k != j) {
				if (G[k][j] != 0 && x[k] == x[j]) {
					break;
				}
			}
		}
        
		if (j == 5) {
			return x[k];
		}
	}
	while (true);
}

void GraphColoring :: printNodeColors() {
	for (int i = 1; i <= 4; i++) {
		cout << x[i] << endl;
	}
}

void GraphColoring :: run() {
	colorGraph(2, 4);
}
