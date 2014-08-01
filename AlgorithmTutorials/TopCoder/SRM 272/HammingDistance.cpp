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

class HammingDistance {
    public:
    int minDistance(vector<string> numbers) {

        vector<int> arr;

        for ( int  i = 0 ; i < numbers.size() ; i++ )
        {
            int min = 999999;
            for ( int j = i + 1 ; j < numbers.size() ; j++ )
            {
                if ( i != j )
                {
                    int tempMin = hammingDistance(numbers[i], numbers[j]);
                    if ( tempMin < min )
                    {
                        min = tempMin;
                    }
                }
            }
            arr.push_back(min);
        }
        
        sort(arr.begin(), arr.end());
        return arr[0];
    }
    
    int hammingDistance(string &s, string& p)
    {
        int count = 0 ;
        if ( s.length() > p.length() )
        {
            count += (s.length() - p.length());
            for ( int i = (int) p.length() -1 ; i >=0 ; i-- )
            {
                if (p[i] != s[i])
                {
                    count ++;
                }
            }
        }
        else if (p.length() > s.length()  )
        {
            count += (p.length() - s.length());
            for ( int i = (int)s.length() -1 ; i >=0 ; i-- )
            {
                if (p[i] != s[i])
                {
                    count ++;
                }
            }
            
        }
        else
        {
            for ( int i = (int)s.length() -1 ; i >=0 ; i-- )
            {
                if (p[i] != s[i])
                {
                    count ++;
                }
            }
            
        }

        return count;
    }
};

//// CUT begin
//ifstream data("/Users/vishal 1/Algorithm/AlgorithmTutorials/TopCoder/SRM 272/HammingDistance.sample");
////ifstream data("HammingDistance.sample");
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
//bool do_test(vector<string> numbers, int __expected) {
//    time_t startClock = clock();
//    HammingDistance *instance = new HammingDistance();
//    int __result = instance->minDistance(numbers);
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
//        vector<string> numbers;
//        from_stream(numbers);
//        next_line();
//        int __answer;
//        from_stream(__answer);
//
//        cases++;
//        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
//            continue;
//
//        cout << "  Testcase #" << cases - 1 << " ... ";
//        if ( do_test(numbers, __answer)) {
//            passed++;
//        }
//    }
//    if (mainProcess) {
//        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
//        int T = time(NULL) - 1406782583;
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
//        cout << "HammingDistance (250 Points)" << endl << endl;
//    }
//    return run_test(mainProcess, cases, argv[0]);
//}
//// CUT end
