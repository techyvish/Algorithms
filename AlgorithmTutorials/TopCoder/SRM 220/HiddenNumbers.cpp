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


struct greaterNumber : public std::binary_function<string,string,bool>
{
    inline bool operator()(const string& a, const string& b)
    {
        unsigned long na = 0,nb = 0;
        stringstream ss1;
        ss1 << a;
        ss1 >> na ;
        stringstream ss2;
        ss2 << b ;
        ss2 >> nb;
        //cout << na << "  ,  " << nb << endl;
        if ( na == nb )
        {
            return b.length() > a.length();
        }
        return  nb > na ;
        
        //return a > b;
    }
};

class HiddenNumbers {
    public:
    vector<string> findAll(vector<string> String) {
        int n = (int)String.size();
        vector<string> numList;
        vector<string > aVector(n);
        aVector.push_back("TEST");
        for ( int j = 0 ; j < n ; j ++ )
        {
            int i = 0 ;
            string numString ;
            
            
            string str = String[j];
            while ( str[i] != '\n' ) {
                if  (str[i]- '0' >= 0 && str[i] - '0' <= 9 )
                {
                    numString += str[i];
                }
                else
                {
                    if ( numString !=  "")
                    {
                        numList.push_back(numString);
                        numString = "";
                    }
                }
                if ( i == str.length() )
                    break;
                
                i++;
            }
        }
        
        
        sort(numList.begin(), numList.end(),  greaterNumber());
        
        if ( numList.size() )
        {
            if ( numList.size() /2  != 0 )
            {
                vector<string> v2;
                
                int  i =  0 ;
                i =  (int)numList.size() / 2;
                for ( ; i  <  (int)numList.size() ; i++ )
                {
                    v2.push_back(numList[i]);
                }
                return v2;
            }
            else
            {
                
                vector<string> v2;
                
                int  i =  0 ;
                i =  (int) numList.size() -1 / 2;
                for ( ; i  <  (int)numList.size() ; i++ )
                {
                    v2.push_back(numList[i]);
                }
                return v2;
                
                
            }
        }
        return vector<string>();
    }
};

/*
// CUT begin
ifstream data("/Users/vishal/Cerebro/Algorithms/AlgorithmTutorials/TopCoder/SRM 220/HiddenNumbers.sample");

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

bool do_test(vector<string> text, vector<string> __expected) {
    time_t startClock = clock();
    HiddenNumbers *instance = new HiddenNumbers();
    vector<string> __result = instance->findAll(text);
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
        vector<string> text;
        from_stream(text);
        next_line();
        vector<string> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(text, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1425194263;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 550 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "HiddenNumbers (550 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
*/
