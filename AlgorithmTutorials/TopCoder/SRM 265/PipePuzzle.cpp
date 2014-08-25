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

//It turns out that as you follow the flow of water you only need to make a decision as to how to place the 'L' pipes. If you encounter either a '-' or a '+' then you can always place it such that the pipe is aligned along the direction that the water flows. Since there can be at most 20 'L' pipes there are at most 220 paths. This is small enough that you can follow each path and count the number of pipes used.
//
//First start off at the square that contains the water source and keep track of which direction the water is flowing. Then move to the next square based on what the current direction is. If you've moved off the grid or onto the source then you know that the path has ended. Otherwise check that you haven't used the current pipe and then mark it used unless it is a '+' (the only pipes you can use more than once are the '+' pipes). If the current pipe is a '+' then change it to a '-', since using one direction allows the other direction to be used (also note that you can never enter a pipe along the same direction since that would imply a cycle in the path, but there can't be a cycle since the source can never be entered). When the current pipe is '-' or '+' then the direction of the water doesn't change so the next pipe will be in that direction. If the current pipe is 'L' then the path will split; it can either change the direction to turn right or left. You can then add one to the current path length and recursively follow the path to the next pipe. Once the path has ended, retrace it backwards marking the pipes unused and following the other direction as you come back to each 'L'.

using namespace std;

class PipePuzzle {
    public:
    int longest(vector<string> pipes) {
        return 0;
    }
};

// CUT begin
ifstream data("/Users/vishal 1/Algorithm/AlgorithmTutorials/TopCoder/SRM 265/PipePuzzle.sample");

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

bool do_test(vector<string> pipes, int __expected) {
    time_t startClock = clock();
    PipePuzzle *instance = new PipePuzzle();
    int __result = instance->longest(pipes);
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
        vector<string> pipes;
        from_stream(pipes);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(pipes, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1408086234;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "PipePuzzle (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
