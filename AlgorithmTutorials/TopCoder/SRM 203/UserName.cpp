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

class UserName {
    public:
    int buffer[500] = {0};
    string newMember(vector<string> existingNames, string newName) {
        sort(existingNames.begin(), existingNames.end());
        for ( int i = 0 ; i < existingNames.size() ; i++)
        {
            //cout << existingNames[i] << endl;
            if ( existingNames[i].length() > newName.length())
            {
                if ( newName == existingNames[i].substr(0,newName.length()))
                {
                    string str = existingNames[i].substr(newName.length(),existingNames[i].length());
                    istringstream stream(str);
                    int value ;
                    stream >> value;
                    if ( value >= 1 && value <= 99999999)
                    {
                        buffer[value] = 1;
                    }
                }
            }
            else if ( existingNames[i].length() == newName.length() )
            {
                if ( existingNames[i] == newName )
                {
                    buffer[0] = 1 ;
                }
            }
            else
            {
                
            }
        }
        
        for ( int i = 0 ; ; i++ )
        {
            if ( !buffer[i] )
            {
                if ( i != 0 )
                {
                    stringstream ss;
                    ss << i;
                    newName = newName + ss.str();
                }
                break;
            }
        }
        return newName;
    }
};

//// CUT begin
//ifstream data("/Users/vishal 1/Algorithm/AlgorithmTutorials/TopCoder/SRM 203/UserName.sample");
////ifstream data("UserName.sample");
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
//bool do_test(vector<string> existingNames, string newName, string __expected) {
//    time_t startClock = clock();
//    UserName *instance = new UserName();
//    string __result = instance->newMember(existingNames, newName);
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
//        vector<string> existingNames;
//        from_stream(existingNames);
//        string newName;
//        from_stream(newName);
//        next_line();
//        string __answer;
//        from_stream(__answer);
//
//        cases++;
//        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
//            continue;
//
//        cout << "  Testcase #" << cases - 1 << " ... ";
//        if ( do_test(existingNames, newName, __answer)) {
//            passed++;
//        }
//    }
//    if (mainProcess) {
//        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
//        int T = time(NULL) - 1406243215;
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
//        cout << "UserName (250 Points)" << endl << endl;
//    }
//    return run_test(mainProcess, cases, argv[0]);
//}
//// CUT end
