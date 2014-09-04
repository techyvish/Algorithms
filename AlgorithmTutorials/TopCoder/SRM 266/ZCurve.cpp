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

class ZCurve {
    public:
    int sum;
    int zValue(int N, int r, int c) {
        
        int n = pow(2,2*N);
        int a[500][500] = {0};
        cout << endl;
        recurse(N,r,c);
        return 0;
    }
    
    void recurse(int n,int r , int c)
    {
       if ( n == 0)
       {
           sum += 4 ;
           return;
       }
       else
       {
           int grid = 2 * pow(2,n);
        
           for ( int i = 0 ; i < grid ; i+= grid/2 )
           {
               for (int j = 0 ; j < grid ; j+= grid/2)
               {
                   
                   if ( (r == (grid/4 + i)) &&  (c == (grid/4 + j)) )
                   {
                       cout << "found";
                   }
                   recurse(n-1, r, c) ;
               }
           }
       }
    
       

    }
};

//// CUT begin
//ifstream data("/Users/Shared/Algorithms/AlgorithmTutorials/TopCoder/SRM 266/ZCurve.sample");
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
//bool do_test(int N, int r, int c, int __expected) {
//    time_t startClock = clock();
//    ZCurve *instance = new ZCurve();
//    int __result = instance->zValue(N, r, c);
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
//        int N;
//        from_stream(N);
//        int r;
//        from_stream(r);
//        int c;
//        from_stream(c);
//        next_line();
//        int __answer;
//        from_stream(__answer);
//
//        cases++;
//        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
//            continue;
//
//        cout << "  Testcase #" << cases - 1 << " ... ";
//        if ( do_test(N, r, c, __answer)) {
//            passed++;
//        }
//    }
//    if (mainProcess) {
//        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
//        int T = time(NULL) - 1409644906;
//        double PT = T / 60.0, TT = 75.0;
//        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
//        cout << "Score  : " << 900 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
//        cout << "ZCurve (900 Points)" << endl << endl;
//    }
//    return run_test(mainProcess, cases, argv[0]);
//}
//// CUT end
