//
//  Power.cpp
//  AlgorithmTutorials
//
//  Created by Vishal on 25/06/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#include "Power.h"
#include <iostream>

using namespace std;

Power::Power() {
	temp = 1;
}

Power::~Power() {
}

int Power::power(int n, int x) {
	if (x == 0) {
		return 1;
	}
    
	temp = power(n, x / 2);
    
	if (x % 2 == 0)
		return  (temp * temp);
	else
		return (n * temp * temp);
}
