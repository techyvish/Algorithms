//
//  CoinChange.cpp
//  AlgorithmTutorials
//
//  Created by Vishal on 19/07/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#include "CoinChange.h"
using namespace std;

int CoinChange :: change(int sum, int coins[]) {
	if (sum == 0)
		return 0;
	else {
		int min = 999;
		for (int i = 0; i < 3; i++) {
			if (results[sum - coins[i]] < min && (sum - coins[i]) >= 0) {
				if (results[sum - coins[i]] != 0)
					min = results[sum - coins[i]];
				else
					min = change(sum - coins[i], coins);
			}
		}
		results[sum] = min + 1;
		return results[sum];
	}
}

//TODO:Try to wrtie recursive solution
void CoinChange::call(int sum, int coins[]) {
	for (int i = 3; i > 0; i--) {
		int tCoin = coins[i];
		for (int j = 3; j >= 0; j--) {
			int p = 0;
			while (true) {
				p += (tCoin + coins[j]);
				if (p != sum)
					break;
				if (coins[j])
					cout << coins[j] << ",";
				else
					cout << sum  << ",";
			}
			cout << endl;
		}
	}
}

void CoinChange :: run() {
	int coins[] = { 1, 2, 3 };
	int coinArr[] = { 0, 1, 2, 3 };
    
	int amt = 11;
	results = (int *)malloc(sizeof(int) * amt + 1);
	memset(results, 0, sizeof(int) * amt);
    
	call(2, coinArr);
	//  int coinsRequired = change(amt, coins);
	//  std::cout << "numberOfCoinsRequired for "<< amt << " is " << coinsRequired << std::endl;
}
