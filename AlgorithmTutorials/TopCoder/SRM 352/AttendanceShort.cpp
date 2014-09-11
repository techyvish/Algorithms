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

class AttendanceShort {
    public:
    vector<string> shortList(vector<string> names, vector<string> attendance)
    {
        vector<string> studentNames;
        
        vector<int> attendence;
        for ( int i = 0 ; i < names.size() ; i++ )
        {
            string record = attendance[i];
            float c = (float)record.length();
            float sum = 0.0;
            for ( int  i = 0 ; i < c ; i++ )
            {
                if ( record[i] == 'M')
                {
                    c--;
                }
                
                if ( record[i] == 'P' )
                {
                    sum++;
                }
            }
            float finalScore = (float) sum/c * 100;
            if ( finalScore < 75.0 )
                studentNames.push_back(names[i]);
        }

        return studentNames;
    }
};

//// CUT begin
//ifstream data("/Users/Shared/Algorithms/AlgorithmTutorials/TopCoder/SRM 352/AttendanceShort.sample");
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
//bool do_test(vector<string> names, vector<string> attendance, vector<string> __expected) {
//    time_t startClock = clock();
//    AttendanceShort *instance = new AttendanceShort();
//    vector<string> __result = instance->shortList(names, attendance);
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
//        vector<string> names;
//        from_stream(names);
//        vector<string> attendance;
//        from_stream(attendance);
//        next_line();
//        vector<string> __answer;
//        from_stream(__answer);
//
//        cases++;
//        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
//            continue;
//
//        cout << "  Testcase #" << cases - 1 << " ... ";
//        if ( do_test(names, attendance, __answer)) {
//            passed++;
//        }
//    }
//    if (mainProcess) {
//        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
//        int T = time(NULL) - 1409975517;
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
//        cout << "AttendanceShort (250 Points)" << endl << endl;
//    }
//    return run_test(mainProcess, cases, argv[0]);
//}
//// CUT end
