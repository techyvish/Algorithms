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
#include <map>
#include <list>

using namespace std;

#define SZ(x) ((int)x.size())
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define ALL(X) X.begin(), X.end()
#define SRT(x) sort(ALL(x))
#define RVRS(x) reverse(ALL(x))
#define FILL(x, value) memset(x, value, sizeof(x))

#define next next1
#define hash hash1
#define rank rank1

#ifdef _DEBUG_
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif

using namespace std;

template <class T> inline void check_max(T& actual, T check) {
    if(actual < check) {
        actual = check;
    }
}

template <class T> inline void check_min(T& actual, T check) {
    if(actual > check) {
        actual = check;
    }
}

const double EPS = 1e-9;
const int IINF = 1000000000;
const double PI = acos(-1.0);
const long long LINF = 6000000000000000000LL;

bool U[10], USED[10];
vector<int> G[10];

bool can(int v, int dest) {
    if(U[v]) return false;
    if(v == dest) {
        return true;
    }
    USED[v] = true;
    bool ret = false;
    for(int to : G[v]) {
        if(!U[to] && !USED[to]) check_max(ret, can(to, dest));
    }
    return ret;
}



class OneEntrance {
public:
    int count(vector<int> a, vector<int> b, int s) {
        int n = SZ(a) + 1;
        for(int i = 0; i + 1 < n; ++i) {
            G[a[i]].pb(b[i]);
            G[b[i]].pb(a[i]);
        }
        int answer = 0;
        vector<int> idx;

        for(int i = 0; i < n; ++i) {
            idx.pb(i);
        }
        do {
            FILL(U, 0);
            bool ok = true;

            for ( auto k = idx.begin() ; k != idx.end() ; k++ )
            {
                cout << *k ;
            }
            cout << endl;
            for(int i = 0; i < n; ++i) {
                FILL(USED, 0);
                if(can(s, idx[i])) {
                    U[idx[i]] = 1;
                }
                else {
                    ok = false;
                    break;
                }
            }
            answer += ok;
        }while(next_permutation(ALL(idx)));
        return answer;
    }
};


// CUT begin
ifstream data("/Users/vishal/Cerebro/Algorithms/AlgorithmTutorials/TopCoder/Single Round Match 654/OneEntrance.sample");

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
        int T = time(NULL) - 1427333716;
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
