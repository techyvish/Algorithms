//
//  Parentheses.cpp
//  AlgorithmTutorials
//
//  Created by Vishal on 9/07/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

//Implement an algorithm to print all valid (e g , properly opened and closed) combinations of n-pairs of parentheses
//EXAMPLE:
//input: 3 (e g , 3 pairs of parentheses)
//output: ()()(), ()(()), (())(), ((()))

#include "Parentheses.h"
using namespace std;

void Parentheses :: printParenthesis(int leftperenthesis, int rightparanthesis, string str) {
	if (leftperenthesis == 0 && rightparanthesis == 0) {
		cout << str << endl;
	}
    
	if (leftperenthesis > 0) {
		printParenthesis(leftperenthesis - 1, rightparanthesis + 1, str += "(");
	}
    
	if (rightparanthesis > 0) {
		printParenthesis(leftperenthesis, rightparanthesis - 1, str += ")");
	}
}

//void Parentheses :: printParenthesis(int leftperenthesis, int rightparanthesis,int k, int n) {
//
//    for (int  i = 1 ; i <= n ; i++ ) {
//        if ( k < n ) {
//            printParenthesis(leftperenthesis +1 , rightparanthesis, k + 1, n);
//        }
//        else {
//            printf("%d \n",k);
//        }
//    }

//    //if  ( rightparanthesis <= leftperenthesis) {
//    for (  ; rightparanthesis <= leftperenthesis ; ++rightparanthesis ){
//        printf(")");
//    }
//    //}
//
//
//    if ( k != n ) {
//        printParenthesis(leftperenthesis , rightparanthesis-1, k + 1, n);
//    }
//
//    printf("\n");
//}




void Parentheses :: run() {
	printParenthesis(3, 0, "");
}
