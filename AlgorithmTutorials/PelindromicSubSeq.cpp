//
//  PelindromicSubSeq.cpp
//  AlgorithmTutorials
//
//  Created by Vishal on 5/08/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#include "PelindromicSubSeq.h"
#include "common.h"

using namespace std;
LongestPelindromicSubsequence::LongestPelindromicSubsequence() {
    
}

int LongestPelindromicSubsequence::LPS(char x[],int from , int to){
    
    if ( from == to )
        return 1;
    if ( (from == to + 1) && (x[from] != x[to]))
        return 1;
    if ( (from == to + 1 ) && x[from] == x[to])
        return 2;
    if ( x[from] == x[to] )
        return LPS(x, from+1, to-1) + 2;
    else {
        return themax(LPS(x, from+1, to),LPS(x, from, to-1));
    }
    return 0;
}

void LongestPelindromicSubsequence::run() {
    char x[] = "PAYBZBA";
    int length = this->LPS(x,0,6);
    cout << length << endl;
}

