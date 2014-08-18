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

class AverageAverage {
    vector<int> q;
    vector<double> total;
    public:
  
    double average(vector<int> numList) {
        int a[10] = {0};
        q = numList;
        backtrack(a,-1, (int)numList.size());
        double sum = 0;
        for (int i = 0 ; i < total.size(); i++)
        {
            sum+= total[i];
        }
        return  (double) sum/ (double)(total.size());
    }
    
    bool is_a_solution( int a[], int k, int n)
    {
        return  ( k == n - 1 );
    }
    
    void process_solution( int a[] , int k , int n )
    {
        double sum = 0;
        double atotal = 0;
        for ( int i = 0 ; i < n ; i ++)
        {
            if ( a[i] )
            {
                sum += q[i];
                atotal++;
            }
        }
        if ( atotal != 0 )
            total.push_back(sum/atotal);
    }
    
    void construct_candidates(int a[] , int k , int  n , int c[], int *ncandidates)
    {
        c[0] = true;
        c[1] = false;
        *ncandidates = 2;
    }
    
    void backtrack(int a[], int k , int n )
    {
        int c[3] = {0} ;
        int ncandidates = 0 ;
        if ( is_a_solution(a, k, n ))
        {
            process_solution(a, k, n);
        }
        else
        {
            k = k + 1 ;
            construct_candidates(a, k, n, c, &ncandidates);
            for ( int i = 0 ; i < ncandidates ; i ++)
            {
                a[k] = c[i];
                backtrack(a, k, n);
            }
        }
    }
};

// CUT begin
ifstream data("/Users/vishal 1/Algorithm/AlgorithmTutorials/TopCoder/Member SRM 482/AverageAverage.sample");

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

bool double_equal(const double &a, const double &b) { return b==b && a==a && fabs(b - a) <= 1e-9 * max(1.0, fabs(a) ); }

bool do_test(vector<int> numList, double __expected) {
    time_t startClock = clock();
    AverageAverage *instance = new AverageAverage();
    double __result = instance->average(numList);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (double_equal(__expected, __result)) {
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
        vector<int> numList;
        from_stream(numList);
        next_line();
        double __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(numList, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1408276272;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 275 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "AverageAverage (275 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
