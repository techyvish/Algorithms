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
#include <iterator>

using namespace std;

class NumberMagicEasy {
public:
    int theNumber(string answer) {
        
        int t[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 ,13 ,14 ,15 ,16};
        int dec1[] = { 1, 2, 3, 4, 5,  6,  7,  8 };
        int dec2[] = { 1, 2, 3, 4, 9, 10, 11, 12 };
        int dec3[] = { 1, 2, 5, 6, 9, 10, 13, 14 };
        int dec4[] = { 1, 3, 5, 7, 9, 11, 13, 15 };
        
        int size1 = sizeof( dec1 ) / sizeof ( dec1[ 0 ] );
        int size2 = sizeof( dec2 ) / sizeof ( dec2[ 0 ] );
        int size3 = sizeof( dec3 ) / sizeof ( dec3[ 0 ] );
        int size4 = sizeof( dec4 ) / sizeof ( dec4[ 0 ] );
        
        std::vector<int> total( t , t+ sizeof(t)/sizeof(t[0]));
        std::vector<int> v1( dec1, dec1 + size1 );
        std::vector<int> v2( dec2, dec2 + size2 );
        std::vector<int> v3( dec3, dec3 + size3 );
        std::vector<int> v4( dec4, dec4 + size4 );
        
        vector<int> vt1;
        vector<int> vt2;
        vector<int> vt3;
        vector<int> vt4;
        
        vector<int> vt5;
        vector<int> vt6;
        vector<int> vt7;
        
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        sort(v3.begin(),v3.end());
        sort(v4.begin(),v4.end());
        
        if ( answer[0] == 'N')
        {
            std::set_symmetric_difference(total.begin(), total.end(),
                                          v1.begin(), v1.end(),
                                          std::back_inserter(vt1));
        }
        else
        {
            copy(v1.begin(), v1.end(), std::back_inserter(vt1));
        }
        
        if ( answer[1] == 'N' )
        {
            std::set_symmetric_difference(total.begin(), total.end(),
                                          v2.begin(), v2.end(),
                                          std::back_inserter(vt2));
        }
        else
        {
            copy(v2.begin(), v2.end(), std::back_inserter(vt2));
        }
        
        
        if ( answer[2] == 'N' )
        {
            std::set_symmetric_difference(total.begin(), total.end(),
                                          v3.begin(), v3.end(),
                                          std::back_inserter(vt3));
        }
        else
        {
            copy(v3.begin(), v3.end(), std::back_inserter(vt3));
        }
        
        
        if ( answer[3] == 'N' )
        {
            std::set_symmetric_difference(total.begin(), total.end(),
                                          v4.begin(), v4.end(),
                                          std::back_inserter(vt4));
        }
        else
        {
            copy(v4.begin(), v4.end(),std::back_inserter(vt4));
        }
        
        std::set_intersection(vt1.begin(), vt1.end(),
                              vt2.begin(), vt2.end(),
                              std::back_inserter(vt5));
        
        std::set_intersection(vt5.begin(), vt5.end(),
                              vt3.begin(), vt3.end(),
                              std::back_inserter(vt6));
        
        std::set_intersection(vt6.begin(), vt6.end(),
                              vt4.begin(), vt4.end(),
                              std::back_inserter(vt7));
        
        return vt7[0];
    }
};

//// CUT begin
//ifstream data("/Users/vishal 1/Algorithm/AlgorithmTutorials/TopCoder/SRM 484/NumberMagicEasy.sample");
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
//bool do_test(string answer, int __expected) {
//    time_t startClock = clock();
//    NumberMagicEasy *instance = new NumberMagicEasy();
//    int __result = instance->theNumber(answer);
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
//        string answer;
//        from_stream(answer);
//        next_line();
//        int __answer;
//        from_stream(__answer);
//
//        cases++;
//        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
//            continue;
//
//        cout << "  Testcase #" << cases - 1 << " ... ";
//        if ( do_test(answer, __answer)) {
//            passed++;
//        }
//    }
//    if (mainProcess) {
//        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
//        int T = time(NULL) - 1408423883;
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
//        cout << "NumberMagicEasy (250 Points)" << endl << endl;
//    }
//    return run_test(mainProcess, cases, argv[0]);
//}
//// CUT end
