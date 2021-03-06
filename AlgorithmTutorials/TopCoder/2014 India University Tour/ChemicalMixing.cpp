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

class ChemicalMixing {
    public:
    double closestBlend(vector<int> volume, vector<int> solute, int minVolume, double desiredStrength) {
        int n = (int)volume.size();
        std::vector<int> v(n);
        std::fill(v.begin() + n - (n/2), v.end(), 1);
        
        double minStrength = 9999.0 ;
        int minVol = 999;
        
        float totalSolvent  = 0.0;
        float totalVolume = 0.0;
        float mindiff = 9999.0;
        float minstrendght = 999999.0;
        do {
            totalSolvent = 0.0;
            totalVolume = 0.0;
            for (int i = 0; i < n; ++i) {
                if (v[i]) {
                    //cout << volume[i] << endl;
                    totalVolume += volume[i];
                    //cout << solute[i] << endl;
                    totalSolvent += solute[i];
                }
            }
            //cout << endl;
            double finalStrenth = totalSolvent / totalVolume;
            if ( totalVolume >= minVolume &&
                ( abs(finalStrenth-desiredStrength) < mindiff  ))
            {
                mindiff =      abs(finalStrenth-desiredStrength);
                minVol = totalVolume;
                
            }
           
        } while (std::next_permutation(v.begin(), v.end()));
        
        totalSolvent = 0.0;
        totalVolume = 0.0;
        
        for (int i = 0; i < n; ++i)
        {
            totalVolume += volume[i];
            totalSolvent += solute[i];
        }
        double finalStrenth = totalSolvent / totalVolume;
        if ( totalVolume >= minVolume &&
            ( abs(finalStrenth-desiredStrength) < mindiff  ))
        {
            mindiff =  abs(finalStrenth-desiredStrength);
            minVol = totalVolume;
            
        }
        
        return mindiff ;//abs( finalStrenth - desiredStrength);
    }
};

//// CUT begin
//ifstream data("/Users/Shared/Algorithms/AlgorithmTutorials/TopCoder/2014 India University Tour/ChemicalMixing.sample");
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
//bool double_equal(const double &a, const double &b) { return b==b && a==a && fabs(b - a) <= 1e-9 * max(1.0, fabs(a) ); }
//
//bool do_test(vector<int> volume, vector<int> solute, int minVolume, double desiredStrength, double __expected) {
//    time_t startClock = clock();
//    ChemicalMixing *instance = new ChemicalMixing();
//    double __result = instance->closestBlend(volume, solute, minVolume, desiredStrength);
//    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
//    delete instance;
//
//    if (double_equal(__expected, __result)) {
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
//        vector<int> volume;
//        from_stream(volume);
//        vector<int> solute;
//        from_stream(solute);
//        int minVolume;
//        from_stream(minVolume);
//        double desiredStrength;
//        from_stream(desiredStrength);
//        next_line();
//        double __answer;
//        from_stream(__answer);
//
//        cases++;
//        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
//            continue;
//
//        cout << "  Testcase #" << cases - 1 << " ... ";
//        if ( do_test(volume, solute, minVolume, desiredStrength, __answer)) {
//            passed++;
//        }
//    }
//    if (mainProcess) {
//        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
//        int T = time(NULL) - 1409981048;
//        double PT = T / 60.0, TT = 75.0;
//        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
//        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
//        cout << "ChemicalMixing (1000 Points)" << endl << endl;
//    }
//    return run_test(mainProcess, cases, argv[0]);
//}
//// CUT end
