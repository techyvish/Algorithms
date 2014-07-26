//
//  WordFind.cpp
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 16/07/2014.
//  Copyright (c) 2014 Vishal. All rights reserved.
//


/*

                        Problem Statement for WordFind


                        Problem Statement

                        You have been given a "word search" puzzle, which consists of a rectangular grid of letters, in which several words are hidden. Each word may begin anywhere in the puzzle, and may be oriented in any straight line horizontally, vertically, or diagonally. However, the words must all go down, right, or down-right. (see examples)

                        You are given a String[], grid, indicating the letters in the grid to be searched. Character j of element i of grid is the letter at row i, column j. You are also given a String[], wordList, indicating the words to be found in the grid. You are to return a String[] indicating the locations of each word within the grid.

                        The return value should have the same number of elements as wordList. Each element of wordList corresponds to the element of the return value with the same index.

                        Each element of the return value should be formatted as "row col" (quotes added for clarity), where row is the 0-based row in which the first letter of the word is found, and col is the 0-based column in which the first letter of the word is found. If the same word can be found more than once, the location in the lowest-indexed row should be returned. If there is still a tie, return the location with the lowest-indexed column. If a word cannot be found in the grid, return an empty string for that element.


                        Definition

                        Class:	WordFind
                        Method:	findWords
                        Parameters:	String[], String[]
                        Returns:	String[]
                        Method signature:	String[] findWords(String[] grid, String[] wordList)
                        (be sure your method is public)


                        Constraints
                        -	grid will contain between 1 and 50 elements, inclusive.
                        -	Each element of grid will contain between 1 and 50 characters, inclusive.
                        -	Each element of grid will contain the same number of characters.
                        -	Each character of each element of grid will be 'A'-'Z'.
                        -	wordList will contain between 1 and 50 elements, inclusive.
                        -	Each element of wordList will contain between 1 and 50 characters, inclusive.
                        -	Each character of each element of wordList will be 'A'-'Z'.

                        Examples
                        0)

                        {"TEST",
                            "GOAT",
                            "BOAT"}
                        {"GOAT", "BOAT", "TEST"}
                        Returns: { "1 0",
                            "2 0",
                            "0 0" }
                        These words are pretty easy to find.
                        1)

                        {"SXXX",
                            "XQXM",
                            "XXLA",
                            "XXXR"}
                        {"SQL", "RAM"}
                        Returns: { "0 0",
                            "" }
                        While "RAM" may be found going up at "3 3", we are only allowing words that go down and right.
                        2)

                        {"EASYTOFINDEAGSRVHOTCJYG",
                            "FLVENKDHCESOXXXXFAGJKEO",
                            "YHEDYNAIRQGIZECGXQLKDBI",
                            "DEIJFKABAQSIHSNDLOMYJIN",
                            "CKXINIMMNGRNSNRGIWQLWOG",
                            "VOFQDROQGCWDKOUYRAFUCDO",
                            "PFLXWTYKOITSURQJGEGSPGG"}
                        {"EASYTOFIND", "DIAG", "GOING", "THISISTOOLONGTOFITINTHISPUZZLE"}
                        Returns: { "0 0",
                            "1 6",
                            "0 22",
                            "" }
                        This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved.




                        This problem was used for:
                        Single Round Match 232 Round 1 - Division I, Level One
                        Single Round Match 232 Round 1 - Division II, Level Two
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
char buf[1000];
char g[200][200];

class WordFind {

public:
    
    vector<string > findWords(vector<string> a ,vector<string> b)
    {
        int i,j,x,y,z;
        vector<string> ret(b.size());
        
        for ( i = 0 ; i < a.size() ; i++ )
        {
            for ( j = 0 ; j < a[i].size(); j ++)
            {
                g[i][j] = a[i][j];
            }
        }
        
        for ( i = 0 ; i < b.size() ; i++ )
        {
            for ( y = 0 ; y < a.size() ; y ++ )
            {
                for (x =0 ; x < a[i].size(); x++ )
                {
                    // pick a character in two dim array;
                    z = 0 ;
                    for ( j = 0 ; j < b[i].size() ; j ++ )  // check horizontal dir.
                        if (g[y][x+j] != b[i][j] )
                            break;
                    if ( j == b[i].size()) z =1;
                    
                    for ( j = 0 ; j < b[i].size() ; j ++) // check diagonal dir.
                        if ( g[y+j][x+j] != b[i][j] )
                            break;
                    if ( j == b[i].size() ) z = 1;
                    
                    for ( j = 0 ; j < b[i].size() ; j ++) // check vertical dir.
                        if ( g[y+j][x] != b[i][j] )
                            break;
                    if ( j == b[i].size() ) z = 1;
                    
                    if ( z ) // if thre is a match record location.
                    {
                        sprintf(buf, "%d %d", y ,x );
                        cout << y << "," << x << endl;
                        ret[i] = buf;
                    }
                }
            }
        }
        
        return  ret;
    }
};

//int main()
//{
//    WordFind words;
//
//    VS v ;
//    v.push_back("TEST");
//    v.push_back("GOAT");
//    v.push_back("BOAT");
//    v.push_back("XXXR");
//
//    vector<string> wordlist;
//    wordlist.push_back("GOAT");
//    wordlist.push_back("BOAT");
//    wordlist.push_back("TEST");
//
//    words.findWords(v, wordlist);
//
//    return 0;
//}