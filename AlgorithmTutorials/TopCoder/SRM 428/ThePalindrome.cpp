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

class ThePalindrome {
    public:
    
    bool temp = true;
    
    int find(string s) {
        
        int maxLength = 999999;
        string revString(s);
        reverse(revString.begin(), revString.end());
        int length = 0 ;
        bool res = isPalindrom(s,0,s.length()-1,&length);
        if ( res )
            return length;
        for ( int i = 0 ; i < revString.length(); i++ )
        {
            length = 0;
            string newStr =  revString.substr(i,revString.length());
            string finalStr = s + newStr;
            if (isPalindrom(finalStr, 0, finalStr.length() - 1, &length))
            {
                if ( length < maxLength )
                    maxLength = length;
            }
        }
        return maxLength;
    }
    
    bool isPalindrom(string str, unsigned long i , unsigned long j,int *length )
    {
        if ( (str[i] == str[j]) && ((i == j) || (j == (i + 1))) )
        {
            if ( i == j )
                *length = *length + 1;
            if ( j == (i+1))
                *length = *length + 2;
            return true;
        }
        
        if ( str[i] == str[j] )
        {
            i++;
            j--;
            *length = (*length + 2 );
            return temp & isPalindrom(str,i,j,length);
        }
        else
        {
            *length = 0;
            return false;
        }
    }
};

//// CUT begin
//ifstream data("/Users/vishal 1/Algorithm/AlgorithmTutorials/TopCoder/SRM 428/ThePalindrome.sample");
////ifstream data("ThePalindrome.sample");
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
//bool do_test(string s, int __expected) {
//    time_t startClock = clock();
//    ThePalindrome *instance = new ThePalindrome();
//    int __result = instance->find(s);
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
//        int __answer;
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
//        int T = time(NULL) - 1406164020;
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
//        cout << "ThePalindrome (250 Points)" << endl << endl;
//    }
//    return run_test(mainProcess, cases, argv[0]);
//}
//// CUT end
