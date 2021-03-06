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

typedef enum {
    Low = 0,
    high = 1,
}heights;

class FloodRelief {
    public:
    set<char> mapSet;
    heights previousLandscape;
    heights currentLandscape;
    
    
    int minimumPumps(vector<string> heights) {
        
        char a[500][500] = {0};
        for ( int i = 0 ; i < heights.size() ; i++ )
        {
            for ( int j = 0 ; j < heights[i].size() ; j++)
            {
                a[i][j] = heights[i][j];
            }
        }
        
        previousLandscape = Low;
        currentLandscape = high;
        
        printMatrix(a,(int)heights.size(),(int)heights[0].size());
        mapSet.insert(a[0][0]);
        int count = 0;
        if ( !mapSet.empty() )
        {
            char b = *(mapSet.begin());
            floodfill(a,0,0,(int)heights.size(),(int)heights[0].size(),b);
            mapSet.erase(mapSet.find(b));
            count ++;
        }
        return count ;
    }
    
    void floodfill(char a[][500],int x , int y,int maxX,int maxY,char startChar)
    {
        if ( x < 0 || y < 0 )
            return;
        if ( x > maxX-1 || y > maxY-1  )
            return;

//        if ( a[x][y] >= startChar && a[x][y] != '1' )
//        {
//        }
//        
//        if ( a[x][y] < startChar && a[x][y] != '1' )
//        {
//        }
        
        if ( a[x][y] > startChar && a[x][y] != '1' )
        {
            mapSet.insert(a[x][y]);
            return;
        }
        else if ( a[x][y] <= startChar && a[x][y] != '1' )
        {
            a[x][y] = '1';
        }
        
        printMatrix(a,maxX,maxY);
        if ( a[x+1][y] != '1' )
            floodfill(a, x+1, y, maxX,maxY,startChar);
        
        if ( a[x][y+1] != '1')
            floodfill(a, x, y+1, maxX,maxY,startChar);
        
        if ( a[x-1][y] != '1')
            floodfill(a, x-1, y, maxX,maxY,startChar);
        
        if ( a[x][y-1] != '1')
            floodfill(a, x, y-1, maxX,maxY,startChar);
            
    }
                    
    void printMatrix(char a[][500],int maxX, int maxY)
    {
        for ( int i = 0 ; i < maxX ; i++ )
        {
            for ( int j = 0 ; j < maxY ; j++ )
            {
                cout << a[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
};

//// CUT begin
//ifstream data("/Users/Shared/Algorithms/AlgorithmTutorials/TopCoder/SRM 371/FloodRelief.sample");
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
//bool do_test(vector<string> heights, int __expected) {
//    time_t startClock = clock();
//    FloodRelief *instance = new FloodRelief();
//    int __result = instance->minimumPumps(heights);
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
//        vector<string> heights;
//        from_stream(heights);
//        next_line();
//        int __answer;
//        from_stream(__answer);
//
//        cases++;
//        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
//            continue;
//
//        cout << "  Testcase #" << cases - 1 << " ... ";
//        if ( do_test(heights, __answer)) {
//            passed++;
//        }
//    }
//    if (mainProcess) {
//        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
//        int T = time(NULL) - 1409365537;
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
//        cout << "FloodRelief (1000 Points)" << endl << endl;
//    }
//    return run_test(mainProcess, cases, argv[0]);
//}
//// CUT end
