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

struct _node
{
    _node *left;
    _node *rigiht;
    int data;
    
};
typedef struct _node Node ;

class CellRemoval {
    public:
    float s = 0;
    void createGraph(int a,Node *parent,vector<int > &b,int deletedCell)
    {
        vector<int> c;
        for ( int i = 0 ; i < b.size() ; i++)
        {
            if ( b[i] == a)
            {
                c.push_back(i);
            }
        }
        
        if ( c.size() == 1 )
        {
            parent->data = c[0];
            parent->left = NULL;
            parent->rigiht = NULL;
            createGraph(c[0], parent, b,deletedCell);
        }
        
        if ( c.size() == 2 )
        {
            Node *left = new Node;
            Node *right = new Node;
            parent->left = left;
            parent->rigiht = right;
            left->data = c[0];
            right->data = c[1];
            createGraph(c[0], left, b, deletedCell);
            createGraph(c[1], right, b, deletedCell);
        }
        
        if ( c.size() == 0 )
        {
            return;
        }

    }
    
    int runDFS(Node *node,int deletedCell)
    {
   
        if ( node == NULL )
            s += .5;
        if ( node != NULL && node->data != deletedCell  )
        {
            runDFS(node->left, deletedCell);
            runDFS(node->rigiht, deletedCell);
        }
        return s;
    }
    
    int cellsLeft(vector<int> parent, int deletedCell) {
        
        Node *node = new Node;
        node->left = NULL;
        node->rigiht = NULL;
        node->data = -1;
        
        createGraph(-1,node,parent,deletedCell);
        
        int cnt = runDFS(node,deletedCell);
        
        return cnt;
    }

};


// CUT begin
ifstream data("/Users/Shared/Algorithms/AlgorithmTutorials/TopCoder/SRM 435/CellRemoval.sample");

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

bool do_test(vector<int> parent, int deletedCell, int __expected) {
    time_t startClock = clock();
    CellRemoval *instance = new CellRemoval();
    int __result = instance->cellsLeft(parent, deletedCell);
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
        vector<int> parent;
        from_stream(parent);
        int deletedCell;
        from_stream(deletedCell);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(parent, deletedCell, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1421198141;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "CellRemoval (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
