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

class TwiceString {
    public:
    string getShortest(string s) {
        
        string p(s);
        int j = 0;
        string temp;
        int k  = 0 , d = 0 ;
        bool found = false ;
        for ( int i = 1 ; i < s.length() ; i++ )
        {
            d = 0;
            if ( s[i] == p[j] )
            {
                k = j;
                int j = 0;
                int c = i;
                for (  ; c < s.length() ; j++,c++ )
                {
                    if ( j != s.length() && s[c] != p[j] )
                    {
                        break;
                    }
                    else
                    {
                        d++;
                    }
                    
                }
                if ( c == s.length() )
                {
                    found = true;
                    temp =  p.substr(d,p.length());
                    i = (int)s.length();
                }
            }
        }
        
        if ( !found )
            s+= p;
        else
            s += temp;
        
        return s;
    }
};

//// CUT begin
////ifstream data("TwiceString.sample");
//ifstream data("/Users/vishal 1/Algorithm/AlgorithmTutorials/TopCoder/SRM 518/TwiceString.sample");
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
//bool do_test(string s, string __expected) {
//    time_t startClock = clock();
//    TwiceString *instance = new TwiceString();
//    string __result = instance->getShortest(s);
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
//        string s;
//        from_stream(s);
//        next_line();
//        string __answer;
//        from_stream(__answer);
//
//        cases++;
//        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
//            continue;
//
//        cout << "  Testcase #" << cases - 1 << " ... ";
//        if ( do_test(s, __answer)) {
//            passed++;
//        }
//    }
//    if (mainProcess) {
//        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
//        int T = time(NULL) - 1406588284;
//        double PT = T / 60.0, TT = 75.0;
//        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
//        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
//        cout << "TwiceString (250 Points)" << endl << endl;
//    }
//    return run_test(mainProcess, cases, argv[0]);
//}
//// CUT end
