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

class PunctuationCleaner {
    public:
    string clearExcess(string document) {
        
        char a[500] = {0};
        char buffer[500] = {0};
        int k = 0;
        for ( int i = 0 ; i < document.length() ; i++ )
        {
            if ( document[i] == '?' || document[i] == '!' )
            {
                a[document[i]] ++ ;
                int j = i+1;
                for (  ; j < document.length() ; j++ )
                {
                    if ( document[j] == '?' || document[j] == '!' )
                    {
                        a[document[j]] ++ ;
                    }
                    else
                    {
                        if ( a['?'] > 0 )
                            buffer[k++] = '?';
                        else
                            buffer[k++] = '!';
                        buffer[k++] = document[j];
                        memset(a, 0, 500);
                        i = j;
                        break;
                    }
                }
                
                if ( j == document.length())
                {
                    if ( a['?'] > 0 )
                        buffer[k++] = '?';
                    else
                        buffer[k++] = '!';
                    i = j + 1;
                }
            }
            else
            {
                buffer[k++] = document[i];
            }
        }
        char buffer2[500] = {'\n'};
        sprintf(buffer2, "%s",buffer);
        string str(buffer2);
        return str;
    }
};

//// CUT begin
//ifstream data("/Users/vishal 1/Algorithm/AlgorithmTutorials/TopCoder/SRM 376/PunctuationCleaner.sample");
//
////ifstream data("PunctuationCleaner.sample");
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
//bool do_test(string document, string __expected) {
//    time_t startClock = clock();
//    PunctuationCleaner *instance = new PunctuationCleaner();
//    string __result = instance->clearExcess(document);
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
//        string document;
//        from_stream(document);
//        next_line();
//        string __answer;
//        from_stream(__answer);
//
//        cases++;
//        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
//            continue;
//
//        cout << "  Testcase #" << cases - 1 << " ... ";
//        if ( do_test(document, __answer)) {
//            passed++;
//        }
//    }
//    if (mainProcess) {
//        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
//        int T = time(NULL) - 1406508166;
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
//        cout << "PunctuationCleaner (250 Points)" << endl << endl;
//    }
//    return run_test(mainProcess, cases, argv[0]);
//}
//// CUT end
