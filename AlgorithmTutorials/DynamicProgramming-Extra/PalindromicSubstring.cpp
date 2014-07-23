//
//  PalindromicSubstring.cpp
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 22/07/2014.
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
#include <list>
#include <string>

using namespace std;

#define NMAX 50

typedef vector<int> VI ; typedef vector<vector<int>> VVI;
typedef vector<string> VS; typedef vector<vector<string>> VVS;
typedef signed long long i64; typedef unsigned long long u64;

class PalindromicSubstring {
  
public:
    u_long max = 0;
    u_long subString(string s, u_long start, u_long end,vector<char>& s1, vector<char>& s2)
    {
        if ( start == 0 && end == 0 )
        {
            return max;
        }
        
        if ( ( start == end )|| (start == end + 1 ))
        {
            if (  ((start == end ) || start == (end + 1)) && (s1.size() != 0 && s2.size() !=0 )   )
            {
                string k;
                if ( start == end )
                    s1.push_back(s[start]);
                
                if ( s1.size() != 0 && s2.size() != 0 )
                {
                    reverse(s2.begin(), s2.end());
                    k =  std::string(s1.begin(),s1.end()) +   std::string(s2.begin(),s2.end());
                    if ( !k.empty() )
                    {
                        if ( max < k.length() )
                        {
                            max = k.length();
                            cout << k << endl;
                        }
                    }
                }
            }
            return max;
        }
        
        if ( s[start] == s[end] )
        {
            s1.push_back(s[start]);
            s2.push_back(s[end]);
            subString(s, start +1, end-1,s1,s2);
        }
        
        if ( s1.size() || s2.size())
        {
            s1.clear();
            s2.clear();
        }
        
        subString(s, start  , end-1,s1,s2);
        subString(s, start+1, end,s1,s2 );
    }
};

//int main()
//{
//    string s = "forgeeksskeegfor";
//    vector<char > s1;
//    vector<char > s2;
//    
//    PalindromicSubstring p;
//    int length = p.subString(s, 0, s.length()-1,s1,s2);
//    return 0;
//}

