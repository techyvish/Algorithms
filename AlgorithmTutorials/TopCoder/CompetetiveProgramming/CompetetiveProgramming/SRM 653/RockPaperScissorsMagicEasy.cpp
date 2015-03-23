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
#include <algorithm>

using namespace std;
#define MOD 1000000007 

class RockPaperScissorsMagicEasy {
public:
	long long  binormialCoeff(long long  n, long long  k)
	{
		long long C[100][100];
		long long int i, j;
		// Caculate value of Binomial Coefficient in bottom up manner 
		for (i = 0; i <= n; i++) {
			for (j = 0; j <= min(i, k); j++) {
				// Base Cases 
				if (j == 0 || j == i)
					C[i][j] = 1;

				// Calculate value using previosly stored values 
				else
					C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
			}
		}
		//cout<<"Hello"<<endl; 

		return C[n][k];
	}

	int count(vector<int> card, int score) {
		if (score > card.size())
			return 0;
		unsigned long  N = card.size();
		long long wins = binormialCoeff(N, score);
		long long y = 1;
		int k = N - score;
		long long res = 0;
		res += wins;
		while (k--)
		{
			y <<= 1;
			y %= MOD;
		}
		res = (res * y) % MOD;
		return res;
	}
};

// CUT begin
ifstream data("SRM 653/RockPaperScissorsMagicEasy.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(vector<int> card, int score, int __expected) {
    time_t startClock = clock();
    RockPaperScissorsMagicEasy *instance = new RockPaperScissorsMagicEasy();
    int __result = instance->count(card, score);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<int> card;
        from_stream(card);
        int score;
        from_stream(score);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(card, score, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1427004083;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "RockPaperScissorsMagicEasy (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
