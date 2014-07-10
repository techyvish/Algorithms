//
//  Parentheses.cpp
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 9/07/2014.
//  Copyright (c) 2014 Vishal. All rights reserved.
//
#include <cstdio>

#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <unistd.h>
#include <climits>

using namespace std;

class Parentheses {

public:
    int n ;
    
    void printParenthesis(int i, int j )
    {
        if ( j == n )
            return ;
        
        while ( i < n) {
            cout << "(";
            printParenthesis(++i,j + 1);
            i++;
            cout << ")";
            printParenthesis(++i,j + 1);
            
            //cout << ")";
        }
    }
};

//int main()
//{
//    Parentheses p;
//    p.n = 2;
//    for ( int j = 0 ; j < 2 ; j ++ )
//    {
//        p.printParenthesis( 0 , 0 );
//        cout << endl << "------" << endl ;
//    }
//    return 0;
//}
