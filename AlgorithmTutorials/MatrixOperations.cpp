//
//  SpiralMatrix.cpp
//  AlgorithmTutorials
//
//  Created by Vishal on 28/06/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#include "MatrixOperations.h"

using namespace std;
MatrixOperations :: MatrixOperations() {
	//    a = new int *[3];
	//    for ( int  i = 0 ;  i < 4 ; i ++ ){
	//        a[i] = new int [4];
	//    }
}

void MatrixOperations :: printSpiral(int a[][5], int numCol, int numRow) {
	int top = 0;
	int bottom = numRow;
	int left = 0;
	int right = numCol;
    
	int curX = 0;
	int curY = 0;
	while (true) {
		if (right == numCol / 2 && right == numRow / 2) {
			break;
		}
        
		while (curY < right - 1)
			cout << a[curX][curY++] << endl;
        
		while (curX < bottom - 1)
			cout << a[curX++][curY] << endl;
        
		while (curY > left)
			cout << a[curX][curY--] << endl;
        
		while (curX > top)
			cout << a[curX--][curY] << endl;
        
		curX++;
		curY++;
        
		right -= 1;
		bottom -= 1;
		top++;
		left++;
	}
	cout << endl;
}

void MatrixOperations :: printMatrix(int a[][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void MatrixOperations :: rotateClockWise(int a[][5], int n) {
	int row = 0;
	int col = 0;
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < 4; j++) {
			int temp = a[row][3];
			a[row][3] = a[i][j];
			row++;
            
			col = 3;
			int temp2 = a[3][col];
			a[3][col] = temp;
			col--;
            
			row = 3;
			int temp3 = a[row][0];
			a[row][0] = temp2;
			row--;
            
			a[0][col++] = temp3;
		}
	}
	printMatrix(a);
}

void MatrixOperations :: run() {
	int a[5][5] = {
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 }
	};
	int k = 1;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = k++;
		}
	}
    
	this->printMatrix(a);
	//this->rotateClockWise(a,4);
	this->printSpiral(a, 5, 5);
}
