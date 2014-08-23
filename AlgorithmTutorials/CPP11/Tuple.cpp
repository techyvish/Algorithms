//
//  Tuple.cpp
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 8/23/14.
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
#include <tuple>

using namespace std;

#include "Tuple.h"

class Tuple
{
public:
    void demo()
    {
        tuple<int,int,string> t1(2,2,"element1");
        tuple<int,int,string> t2(3,3,"element2");
        tuple<int,int,string> t3(4,5,"element3");
        
        cout << get<0>(t1);
        cout << get<1>(t2);
        cout << get<2>(t3);
        
        auto t4 = make_tuple(2,100,"element4");
        get<1>(t1) = get<1>(t4);
        
        if ( t1 < t2 ) // compare value for value
            t1 = t2 ; // assign value for value
        
        cout << get<0>(t1);
        cout << get<1>(t1);
        cout << get<2>(t1);
        
        int i;
        float f;
        std::string s;
        
        tie(i,f,s)=t1;
        
    }
};

int main()
{
 
    Tuple t;
    t.demo();
}