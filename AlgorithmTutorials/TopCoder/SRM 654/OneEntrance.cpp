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

using namespace std;

class OneEntrance{
public:


	vector<int>g[25];
	int dist[25];
	bool vis[25];
	bool valid[25];

	int ar[25];
	void dfs(int u){

		vis[u] = true;
		for (int i = 0; i<g[u].size(); i++){
			int v = g[u][i];
			if (valid[v] && !vis[v]){
				dfs(v);
			}
		}
	}

	int count(vector <int> a, vector <int> b, int s){
		int n = (int)a.size() + 1;
		for (int i = 0; i<a.size(); i++){
			g[a[i]].push_back(b[i]);
			g[b[i]].push_back(a[i]);
		}

		for (int i = 0; i<n; i++){
			ar[i] = i;
		}
		int res = 0;
		do{
			bool val = true;
			memset(valid, true, sizeof(valid));
			for (int i = 0; i < n; i ++)
			{
				cout << ar[i] << " ";
			}
			cout << endl;
			for (int i = 0; i<n; i++){
				memset(vis, false, sizeof(vis));
				valid[ar[i]] = false;
				dfs(ar[i]);
				if (!vis[s]){
					val = false;
					break;
				}
			}
			res += val;
		} while (next_permutation(ar, ar + n));
		return res;
	}
};

// CUT begin
ifstream data("../../SRM 654/OneEntrance.sample");

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

bool do_test(vector<int> a, vector<int> b, int s, int __expected) {
    time_t startClock = clock();
    OneEntrance *instance = new OneEntrance();
    int __result = instance->count(a, b, s);
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
        vector<int> a;
        from_stream(a);
        vector<int> b;
        from_stream(b);
        int s;
        from_stream(s);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(a, b, s, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1427538546;
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
        cout << "OneEntrance (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end