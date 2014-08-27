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
#define MAX 3

class MNS {
    public:
    
    int count = 0;
    
    int** convert2Darray(vector<int> numbers)
    {
        int **a = new int *[MAX];
        int k = 0;
        for ( int i = 0 ; i < MAX ; i ++ )
        {
            a[i] = new int[3];
            for (int j =0 ; j < MAX ; j++)
            {
                a[i][j] = numbers[k++];
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return  a;
    }
    
    bool convertAndCheckMagicNumber(vector<int> numbers)
    {
        int **a = convert2Darray(numbers);
        return isMaginSqure(a);
    }
    
    bool isMaginSqure(int **a)
    {
        int r1 = a[0][0]+ a[0][1]+ a[0][2] ;
        int r2 = a[1][0]+ a[1][1]+ a[1][2] ;
        int r3 = a[2][0]+ a[2][1]+ a[2][2] ;
        
        int c1 = a[0][0]+ a[1][0]+ a[2][0] ;
        int c2 = a[0][1]+ a[1][1]+ a[2][1] ;
        int c3 = a[0][2]+ a[1][2]+ a[2][2] ;
        
        return  ( (r1 == r2) && ( r2 == r3 ) && ( r3 == r1) ) &&
                ( (c1 == c2 ) && (c2 == c3 ) &&  (c3 == c1) );
    }
    
    bool is_a_solutions(vector<int> numbers, int k ,int n )
    {
        return ( k == n - 1);
    }
    
    void process_solution(vector<int> numbers,int k ,int n )
    {
        
        
//        for ( int i = 0 ; i < numbers.size() ; i++ )
//        {
//            cout << numbers[i] << " ";
//        }
//        cout << endl;
        if ( convertAndCheckMagicNumber(numbers))
        {
            count ++;
        }
    }
    
    void construct_candidates(vector<int> numbers,int k ,int n , int c[],int *ncandidates)
    {
        int p = 0;
        int **a = convert2Darray(numbers);
        for ( int i = 0 ; i < MAX ; i++)
        {
            for ( int j = 0 ; j < MAX ; j++)
            {
                if ( k != i && j != k )
                {
                    c[p++] = (MAX*i) + j;
                }
            }
        }
        
        *ncandidates = p;
    }
    
    void backtrack(vector<int> numbers,int k ,int n )
    {
        int c[9] = {0};
        int ncandidates = 0;
        if ( convertAndCheckMagicNumber(numbers) )
        {
            count++;
        }
//        if ( is_a_solutions(numbers, k, n) )
//        {
//            process_solution(numbers, k, n);
//        }
//        else
        {
            for ( int k = 0 ; k < numbers.size() ; k++ )
            {
                construct_candidates(numbers, k, n, c, &ncandidates);
                //backtrack(numbers, k, n);
                for (int j = 0 ; j < ncandidates ; j++)
                {
                    if (  numbers[k] != numbers[c[j]])
                    {
                        int temp = numbers[k] ;
                        numbers[k]= numbers[c[j]];
                        numbers[c[j]] = temp;
                        
                        if ( convertAndCheckMagicNumber(numbers) )
                        {
                            count++;
                        }
                        
                        int temp1 = numbers[k] ;
                        numbers[k]= numbers[c[j]];
                        numbers[c[j]] = temp1;
                    }
                }
                memset(c, 0, 9);
            }
        }
        
    }
    
    int combos(vector<int> numbers) {
        backtrack(numbers, 0, 9);
        return count;
    }
};

// CUT begin
ifstream data("/Users/vishal 1/Algorithm/AlgorithmTutorials/TopCoder/SRM 148/MNS.sample");

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

bool do_test(vector<int> numbers, int __expected) {
    time_t startClock = clock();
    MNS *instance = new MNS();
    int __result = instance->combos(numbers);
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
        vector<int> numbers;
        from_stream(numbers);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(numbers, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1409006930;
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
        cout << "MNS (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
