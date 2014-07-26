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

class NumbersChallenge {
    public:
    
    int p = 0;
    vector<int > v;
    vector<int > arr;
    
    bool finished = false;
    
    bool is_a_solution(int a[],int k, int n)
    {
        return ( k == n -1 );
    }
    
    void process_solution(int a[],int k , int n)
    {
       // cout << " { ";
        int sum = 0;
        for ( int i = 0 ; i < n ; i++ )
        {
            if ( a[i] != 0 )
            {
                //cout << v[i] << " ";
                sum += v[i];
            }
        }
        //cout << " } " << endl;
        arr.push_back(sum);
    }
    
    void construct_candidates(int a[],int k, int n, int c[], int *ncandidates)
    {
        c[0] = 1 ;
        c[1] = 0 ;
        *ncandidates = 2;
    }
    
    void backtrack(int a[],int k , int  n)
    {
        int c[3];
        int ncandidates;
        int i ;
        
        if ( is_a_solution(a,k,n))
            process_solution(a,k,n);
        else
        {
            k = k+1;
            construct_candidates(a,k,n,c,&ncandidates);
            for ( i = 0 ; i < ncandidates ; i++ )
            {
                a[k] = c[i];
                backtrack(a,k,n);
                if ( finished )
                    return;
            }
        }
    }
    
    int MinNumber(vector<int> S) {
        int a[50] = {0};
        v = S;
        backtrack(a,-1,(int)S.size());
        sort(arr.begin(), arr.end());
        int ans = arr[arr.size()-1] + 1;
        for ( int i = 0 ; i < arr.size() - 1 ; i++ )
        {
            if ( (arr[i] + 1 == arr[i+1]) ||  (arr[i] == arr[i+1]))
            {
                continue;
            }
            else
            {
                ans = arr[i]+1;
                break;
            }
        }
        return ans;
    }

};

//// CUT begin
//ifstream data("/Users/vishal 1/Algorithm/AlgorithmTutorials/TopCoder/SRM 621/NumbersChallenge.sample");
////ifstream data("NumbersChallenge.sample");
//
//string next_line() {
//    string s;
//    getline(data, s);
//    return s;
//}
//
//template <typename T> void from_stream(T &t) {
//    stringstream ss(next_line());
//    ss >> t;
//}
//
//void from_stream(string &s) {
//    s = next_line();
//}
//
//template <typename T> void from_stream(vector<T> &ts) {
//    int len;
//    from_stream(len);
//    ts.clear();
//    for (int i = 0; i < len; ++i) {
//        T t;
//        from_stream(t);
//        ts.push_back(t);
//    }
//}
//
//template <typename T>
//string to_string(T t) {
//    stringstream s;
//    s << t;
//    return s.str();
//}
//
//string to_string(string t) {
//    return "\"" + t + "\"";
//}
//
//bool do_test(vector<int> S, int __expected) {
//    time_t startClock = clock();
//    NumbersChallenge *instance = new NumbersChallenge();
//    int __result = instance->MinNumber(S);
//    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
//    delete instance;
//
//    if (__result == __expected) {
//        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
//        return true;
//    }
//    else {
//        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
//        cout << "           Expected: " << to_string(__expected) << endl;
//        cout << "           Received: " << to_string(__result) << endl;
//        return false;
//    }
//}
//
//int run_test(bool mainProcess, const set<int> &case_set, const string command) {
//    int cases = 0, passed = 0;
//    while (true) {
//        if (next_line().find("--") != 0)
//            break;
//        vector<int> S;
//        from_stream(S);
//        next_line();
//        int __answer;
//        from_stream(__answer);
//
//        cases++;
//        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
//            continue;
//
//        cout << "  Testcase #" << cases - 1 << " ... ";
//        if ( do_test(S, __answer)) {
//            passed++;
//        }
//    }
//    if (mainProcess) {
//        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
//        int T = time(NULL) - 1406180582;
//        double PT = T / 60.0, TT = 75.0;
//        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
//        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
//    }
//    return 0;
//}
//
//int main(int argc, char *argv[]) {
//    cout.setf(ios::fixed, ios::floatfield);
//    cout.precision(2);
//    set<int> cases;
//    bool mainProcess = true;
//    for (int i = 1; i < argc; ++i) {
//        if ( string(argv[i]) == "-") {
//            mainProcess = false;
//        } else {
//            cases.insert(atoi(argv[i]));
//        }
//    }
//    if (mainProcess) {
//        cout << "NumbersChallenge (500 Points)" << endl << endl;
//    }
//    return run_test(mainProcess, cases, argv[0]);
//}
//// CUT end
