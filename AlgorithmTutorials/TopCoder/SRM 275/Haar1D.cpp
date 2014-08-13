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

class Haar1D {
public:
    vector<int > v;
    
    vector<int> transform(vector<int> data, int L) {
        
        return transformWithPart(data,L,(int)data.size());
        
    }
    
    vector<int> transformWithPart(vector<int> data,int L,int elements)
    {
        vector<int > temp(data.size());
        if ( L == 0 )
        {
            return  data;
        }
        else
        {
            temp = data;
            int k = 0;
            for ( int i = 0 ; i < elements ; i+=2 )
            {
                temp[k++] = data[i]+data[i+1];
            }
            
            for ( int i = 0 ; i < elements ; i+=2 )
            {
                temp[k++] = data[i] - data[i+1];
            }
            
            //            temp = v;
            //            // demonstrate delete in range.
            //            v.erase(v.begin() /* first you want delete */,
            //                      v.begin() + v.size() /* 1 beyond the last you want to delete */);
            //            // or if you have to erase all elements:
            //            v.clear();
        }
        return transformWithPart(temp, L - 1, elements/2 );
        
    }
};

//// CUT begin
//ifstream data("/Users/vishal 1/Algorithm/AlgorithmTutorials/TopCoder/SRM 275/Haar1D.sample");
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
//template <typename T> string to_string(vector<T> ts) {
//    stringstream s;
//    s << "[ ";
//    for (int i = 0; i < ts.size(); ++i) {
//        if (i > 0) s << ", ";
//        s << to_string(ts[i]);
//    }
//    s << " ]";
//    return s.str();
//}
//
//bool do_test(vector<int> data, int L, vector<int> __expected) {
//    time_t startClock = clock();
//    Haar1D *instance = new Haar1D();
//    vector<int> __result = instance->transform(data, L);
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
//        vector<int> data;
//        from_stream(data);
//        int L;
//        from_stream(L);
//        next_line();
//        vector<int> __answer;
//        from_stream(__answer);
//
//        cases++;
//        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
//            continue;
//
//        cout << "  Testcase #" << cases - 1 << " ... ";
//        if ( do_test(data, L, __answer)) {
//            passed++;
//        }
//    }
//    if (mainProcess) {
//        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
//        int T = time(NULL) - 1407885745;
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
//        cout << "Haar1D (500 Points)" << endl << endl;
//    }
//    return run_test(mainProcess, cases, argv[0]);
//}
//// CUT end
