#include <cmath>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <set>

using namespace std;

#define bit(x, i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb, n) asm ("bsrl %1,%0" : "=r" (msb) : "r" (n)) //get the highest bit of x, maybe the fastest

#define max(a, b)                           (a < b ? b : a)
#define abs(x)                              (x < 0 ? (-x) : x) // big bug here if "-x" is not surrounded by "()"

#define IN(i, l, r)                         (l < i && i < r) //the next for are for checking bound
#define LINR(i, l, r)                       (l <= i && i <= r)
#define LIN(i, l, r)                        (l <= i && i < r)
#define INR(i, l, r)                        (l < i && i <= r)

#define FOR(i, L, R)                        for (int i = L; i < R; i++) //next four are for "for loops"
#define FOREQ(i, L, R)                      for (int i = L; i <= R; i++)
#define FORBACK(i, L, R)                    for (int i = L; i > R; i--)
#define FORBACKEQ(i, L, R)                  for (int i = L; i >= R; i--)

#define getI(a)                             scanf("%d", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define getII(a, b)                         scanf("%d%d", &a, &b)
#define getIII(a, b, c)                     scanf("%d%d%d", &a, &b, &c)
#define wez(n) int (n);                     scanf("%d", &(n)) //handy if the input is right after the definition of a variable
#define wez2(n, m) int (n), (m);            scanf("%d %d", &(n), &(m))
#define wez3(n, m, k) int (n), (m), (k);    scanf("%d %d %d", &(n), &(m), &(k))

#define TESTS wez(testow)                   while (testow--) //for multilple cases problems
#define whileZ int T;                       getI(T); while (T--) // the same as above

#define getS(x)                             scanf("%s", x) //get a char* string
#define clr(a, x)                           memset(a, x, sizeof(a)) //set elements of array to some value

#define char2Int(c)                         (c-'0')

#define lastEle(vec)                        vec[vec.size()-1]
#define SZ(x)                               ((int)((x).size()))
#define REMAX(a, b)                         (a) = max((a), (b)) // set a to the maximum of a and b
#define REMIN(a, b)                         (a) = min((a), (b));
#define LN(x)                               ((int)((x).length()))

#define FOREACH(i, t)                       for (typeof(t.begin())i = t.begin(); i != t.end(); i++) // traverse an STL data structure
#define ALL(c)                              (c).begin(), (c).end() //handy for function like "sort()"

#define PRESENT(c, x)                       ((c).find(x) != (c).end())
#define CPRESENT(c, x)                      (find(ALL(c), x) != (c).end())

#define ll                                  long long //data types used often, but you don't want to type them time by time
#define ull                                 unsigned long long
#define ui                                  unsigned int
#define us                                  unsigned short
#define IOS                                 ios_base::sync_with_stdio(0); //to synchronize the input of cin and scanf
#define INF                                 1001001001
#define PI                                  3.1415926535897932384626
//for map, pair
#define mp                                  make_pair
#define fi                                  first
#define se s                                econd
// for debug
inline void pisz(int n)
{
    printf("%d\n", n);
}

#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define printA(a, L, R) FE(i, L, R) cout << a[i] << (i == R ? '\n' : ' ')
#define printV(a) printA(a, 0, a.size()-1)
#define MAXN 10000
//for vectors
#define pb push_back
typedef int elem_t;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
// directions
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
template<typename T, typename TT> ostream& operator <<(ostream &s, pair<T, TT> t)
{
    return s<<"("<<t.first<<","<<t.second<<")";
}

template<typename T> ostream& operator <<(ostream &s, vector<T> t)
{
    FOR(i, 0, SZ(t)) s<<t[i]<<" "; return s;
}

using namespace std;

class DNAString {
    public:
    int minChanges(int maxPeriod, vector<string> dna) {
        
        FOR(i, 0, SZ(dna))
        {
            
        }
        
        return 0;
    }
};

// CUT begin
ifstream data("/Users/vishal/Cerebro/Algorithms/AlgorithmTutorials/TopCoder/SRM 396/DNAString.sample");

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

bool do_test(int maxPeriod, vector<string> dna, int __expected) {
    time_t startClock = clock();
    DNAString *instance = new DNAString();
    int __result = instance->minChanges(maxPeriod, dna);
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
        int maxPeriod;
        from_stream(maxPeriod);
        vector<string> dna;
        from_stream(dna);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(maxPeriod, dna, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1426160945;
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
        cout << "DNAString (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
