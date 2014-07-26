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

typedef vector<char> VI;

using namespace std;

class ColorfulTilesEasy {
public:
    
    int theMin(string room) {
        VI v(4);
        v[0] = 'R';
        v[1] = 'G';
        v[2] = 'B';
        v[3] = 'Y';
        
        int count = 0 ;
        for ( int i = 1 ; i < room.size() ; i++ )
        {
            for ( int j = 0 ; j < v.size() ; j++ )
            {

                if ( i != room.size() - 1 )
                {
                    if ((room[i] == room[i-1]) && (room[i] == room[i+1]) && v[j] != room[i] )
                    {
                        room[i] = v[j];
                        count ++;
                        break;
                    }
                    
                    if ((room[i] == room[i-1]) && (room[i] != room[i+1]) && ( v[j] != room[i] || v[j] != room[i-1] || v[j] != room[i+1] )  )
                    {
                        room[i] = v[j];
                        count ++;
                        break;
                    }
                }
                else
                {
                    if ((room[i] == room[i-1]) && v[j] != room[i] )
                    {
                        room[i] = v[j];
                        count ++;
                        break;
                    }
                }
            }
        }
        cout << room << endl;
        return count ;
    }
};

//// CUT begin
//ifstream data("/Users/vishal 1/Algorithm/AlgorithmTutorials/TopCoder/SRM 472/ColorfulTilesEasy.sample");
////ifstream data("ColorfulTilesEasy.sample");
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
//bool do_test(string room, int __expected) {
//    time_t startClock = clock();
//    ColorfulTilesEasy *instance = new ColorfulTilesEasy();
//    int __result = instance->theMin(room);
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
//        string room;
//        from_stream(room);
//        next_line();
//        int __answer;
//        from_stream(__answer);
//
//        cases++;
//        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
//            continue;
//
//        cout << "  Testcase #" << cases - 1 << " ... ";
//        if ( do_test(room, __answer)) {
//            passed++;
//        }
//    }
//    if (mainProcess) {
//        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
//        int T = time(NULL) - 1405813426;
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
//        cout << "ColorfulTilesEasy (250 Points)" << endl << endl;
//    }
//    return run_test(mainProcess, cases, argv[0]);
//}
//// CUT end
