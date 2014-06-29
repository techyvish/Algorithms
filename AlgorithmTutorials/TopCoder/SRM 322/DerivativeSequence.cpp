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

class DerivativeSequence {
    
    vector<int> *finalVector;
    
    public:
    
    DerivativeSequence()
    {
        finalVector = new vector<int>(5,0);
    }
    
    vector<int> derSeq(vector<int> a, int order) {
        if ( order == 0 ) {
            return *finalVector;
        }
        else
        {
            order --;
            int counter = 0;
            vector<int> result;
            if ( allZero(a))
            {
                return vector<int>();
            }
            
            for ( int i = 0 ; i < a.size() ; i++ )
            {
                if ( i < a.size() - 1) {
                    result.push_back(a[i+1] - a[i]);
                    std::cout << result[i] <<" " << endl;
                    counter ++;
                }
            }
            copy(result.begin(), result.end(), finalVector->begin());
            finalVector->resize(result.size());
            derSeq(result, order);
            return *finalVector;
        }
        
        //return a;
    }
    
    bool allZero(vector<int> arr)
    {
        bool zero = true  ;
        for ( int i = 0  ; i < arr.size() ; i++ )
        {
            zero &= ( arr[i] == 0);
            if ( !zero )
                break;
        }
        return zero;
    }

};

// CUT begin
ifstream data("/Users/vishal/Algorithms/AlgorithmTutorials/TopCoder/TestCases/DerivativeSequence.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(vector<int> a, int n, vector<int> __expected) {
    time_t startClock = clock();
    DerivativeSequence *instance = new DerivativeSequence();
    vector<int> __result = instance->derSeq(a, n);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<int> a;
        from_stream(a);
        int n;
        from_stream(n);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(a, n, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1404012588;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "DerivativeSequence (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
