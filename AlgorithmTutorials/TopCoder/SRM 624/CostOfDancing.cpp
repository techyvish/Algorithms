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

struct data {
    int min;
    int realData;
public:

};

bool sortthisshit(data const& a, data const& b)  {
    if ( a.min < b.min)
        return true;
    else
        return false;
}

class CostOfDancing {
    public:
    
    vector<data> minCost;
    int minimum(int K, vector<int> danceCost) {
        sort(danceCost.begin(), danceCost.end());
        int sum = 0 ;
        for (int i = 0 ; i < K ; i ++ )
        {
            sum += danceCost[i];
        }
        return sum;
    }
    
    
//    int minimum1(int K, vector<int> danceCost) {
//        
//        for ( int i = 0 ; i < danceCost.size() ; i ++ )
//        {
//            int min = INT_MAX;
//            bool found = false;
//            data d;
//            for (int  j = 0 ; j < i ; j ++ )
//            {
//                if ( (danceCost[i] + danceCost[j]) < min)
//                {
//                    min = (danceCost[i] + danceCost[j]);
//                    found = true;
////                    d.min = min;
////                    d.realData = danceCost[i];
//                }
//            }
//            if ( !found && i!=0) {
//                min = danceCost[i] + danceCost[i-1];
//                d.min = min;
//                d.realData = danceCost[i];
//                
//            }
//            if ( i == 0 )
//            {
//                min = danceCost[0];
//                d.min = min;
//                d.realData = danceCost[i];
//            }
//            d.min = min;
//            d.realData = danceCost[i];
//            minCost.push_back(d);
//        }
//        
//        std::sort(minCost.begin(), minCost.end(), sortthisshit);
//        int sum = 0;
//        for ( int i = 0 ; i < K ; i++ )
//        {
//            sum += minCost[i].realData;
//        }
//        return sum;
//    }
};

//// CUT begin
//ifstream data("/Users/vishal 1/Algorithm/AlgorithmTutorials/TopCoder/SRM 624/CostOfDancing.sample");
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
//bool do_test(int K, vector<int> danceCost, int __expected) {
//    time_t startClock = clock();
//    CostOfDancing *instance = new CostOfDancing();
//    int __result = instance->minimum(K, danceCost);
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
//        int K;
//        from_stream(K);
//        vector<int> danceCost;
//        from_stream(danceCost);
//        next_line();
//        int __answer;
//        from_stream(__answer);
//
//        cases++;
//        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
//            continue;
//
//        cout << "  Testcase #" << cases - 1 << " ... ";
//        if ( do_test(K, danceCost, __answer)) {
//            passed++;
//        }
//    }
//    if (mainProcess) {
//        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
//        int T = time(NULL) - 1405657719;
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
//        cout << "CostOfDancing (250 Points)" << endl << endl;
//    }
//    return run_test(mainProcess, cases, argv[0]);
//}
//// CUT end
