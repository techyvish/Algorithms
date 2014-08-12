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

class LotteryTicket {
    public:
    bool finished = false;
    int b[4] = {0};
    int total;
    
    string buy(int price, int b1, int b2, int b3, int b4) {
    
        int a[4] = {0,0,0,0};
        b[0] = b1;
        b[1] = b2;
        b[2] = b3;
        b[3] = b4;
        total = price;
        backTrack(a, -1, 4);
        if ( finished )
        {
            return "POSSIBLE";
        }
        else
        {
            return "IMPOSSIBLE";
        }
    }
    
    bool is_a_solution(int a[],int k , int n )
    {
        return ( k == n - 1);
    }
    
    void process_solution(int a[],int k ,int n)
    {
        int sum = 0;
        for ( int i = 0 ; i < n ; i++ )
        {
            if ( a[i] )
            {
                sum += b[i];
            }
        }
        
        if ( sum == total )
        {
            finished = true;
        }
    }
    
    void construct_candidates(int a[],int k,int n , int c[], int *ncandidates)
    {
        c[0] = true;
        c[1] = false;
        *ncandidates = 2;
    }
    
    void backTrack(int a[],int k,int n)
    {
        int ncandidates = 0;
        int c[4] = {0};
        
        if ( is_a_solution(a,k,n))
        {
            process_solution(a,k,n);
        }
        else
        {
            k = k + 1 ;
            construct_candidates(a,k,n,c,&ncandidates);
            for ( int i = 0 ; i < ncandidates ; i++ )
            {
                a[k] = c[i];
                backTrack(a,k,n);
            }
        }
    }
};

// CUT begin
ifstream data("/Users/vishal 1/Algorithm/AlgorithmTutorials/TopCoder/SRM 466/LotteryTicket.sample");
//ifstream data("LotteryTicket.sample");

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

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int price, int b1, int b2, int b3, int b4, string __expected) {
    time_t startClock = clock();
    LotteryTicket *instance = new LotteryTicket();
    string __result = instance->buy(price, b1, b2, b3, b4);
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
        int price;
        from_stream(price);
        int b1;
        from_stream(b1);
        int b2;
        from_stream(b2);
        int b3;
        from_stream(b3);
        int b4;
        from_stream(b4);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(price, b1, b2, b3, b4, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1407801576;
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
        cout << "LotteryTicket (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
