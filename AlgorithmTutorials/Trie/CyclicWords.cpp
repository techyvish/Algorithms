//
//  CyclicWords.cpp
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 17/07/2014.
//  Copyright (c) 2014 Vishal. All rights reserved.
//

/*
                Problem Statement for CyclicWords


                Problem Statement
                We can think of a cyclic word as a word written in a circle. To represent a cyclic word, we choose an arbitrary starting position and read the characters in clockwise order. So, "picture" and "turepic" are representations for the same cyclic word.



                You are given a String[] words, each element of which is a representation of a cyclic word. Return the number of different cyclic words that are represented.




                Definition

                Class:	CyclicWords
                Method:	differentCW
                Parameters:	String[]
                Returns:	int
                Method signature:	int differentCW(String[] words)
                (be sure your method is public)


                Constraints
                -	words will contain between 1 and 50 elements, inclusive.
                -	Each element of words will contain between 1 and 50 lowercase letters ('a'-'z'), inclusive.

                Examples
                0)

                { "picture", "turepic", "icturep", "word", "ordw" }
                Returns: 2
                "picture", "turepic" and "iceturep" are representations of the same cyclic word. "word" and "ordw" are representations of a second cyclic word.
                1)

                { "ast", "ats", "tas", "tsa", "sat", "sta", "ttt" }
                Returns: 3
                2)

                {"aaaa", "aaa", "aa", "aaaa", "aaaaa"}
                Returns: 4
                This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved.




                This problem was used for:
                Single Round Match 358 Round 1 - Division II, Level One
 */

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
#include <list>
#include <string>
#include "Trie.cpp"

using namespace std;

#define NMAX 50

typedef vector<int> VI ; typedef vector<vector<int>> VVI;
typedef vector<string> VS; typedef vector<vector<string>> VVS;
typedef signed long long i64; typedef unsigned long long u64;

class CyclicWords {

    char buf[1000];
    char g[200][200];

public:
    
    int differentCW(VS a)
    {
        int count = 0;
        VI v(a.size());
        
        for (int i = 0 ; i < a.size() ; i++ )
        {
            if ( !v[i] )
            {
                count ++;
                for (int  j = i + 1 ; j < a.size() ; j++ )
                {
                    if (same(a[i],a[j]))
                        v[j] = 1;
                    
                }
            }

            cout << endl;
        }
        
        return count ;
    }
    
    bool same(string& a,string& b)
    {
        for ( int i = 0 ; i < a.size() ; i ++ )
        {
            if ( a == b )
            {
                return  true ;
            }
            else
            {
                rotate(b);
            }
        }
        
        return false;
    }
    
    void rotate(string& b)
    {
        char t = b[b.size() - 1];
        for ( int  i = b.size() - 1; i >= 0 ; i-- )
        {
            b[i] = b[i - 1];
        }
        b[0] = t;
    }
};

//int main()
//{
//    VS s ;
//    //EX 1
////    s.push_back("picture");
////    s.push_back("turepic");
////    s.push_back("icturep");
////    s.push_back("word");
////    s.push_back("ordw");
//
//    // EX 2
//    s.push_back( "ast");
//    s.push_back( "ats");
//    s.push_back( "tas");
//    s.push_back( "tsa");
//    s.push_back( "sat");
//    s.push_back( "sta");
//    s.push_back( "ttt");
//    
//    CyclicWords c;
//    cout << c.differentCW(s);
//    
//    return 0;
//}
