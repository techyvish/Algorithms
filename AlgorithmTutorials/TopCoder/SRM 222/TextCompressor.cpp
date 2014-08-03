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
#include <map>




//typedef std::pair<MyKey, MyValue> MyPair;
//struct CompareByKey {
//    bool operator() (const MyPair& a, const MyPair& b) const {
//        return a.first < b.first;
//    };
//};
//struct CompareByValue {
//    bool operator() (const MyPair& a, const MyPair& b) const {
//        return a.second < b.second;
//    };
//};
//Then either you use std::vector and std::sort, or use two sets.
//
//int main() {
//    std::vector< MyPair > v;
//    //... push all the elements into v.
//    std::sort(v.begin(), v.end(), CompareByKey());
//    //now you have a vector sorted by keys and can be accessed by binary_search.
//    std::sort(v.begin(), v.end(), CompareByValue());
//    //now you have the same vector but sorted by values.
//    //with two sets:
//    std::set< MyPair, CompareByKey> sk;
//    //insert all the elements into sk and you have a sorted set according to key.
//    std::multiset<MyPair, CompareByValue> sv;
//    std::copy(sk.begin(), sk.end(), std::back_inserter(sv));
//    //now you have another set with the values sorted by value.
//    
//};


using namespace std;

//struct CompareDates : public std::binary_function <map<string,int> ,  map<string,int>,bool >
//{
//    bool operator() (const  map<string,int,CompareDates> & lhs, const  map<string,int,CompareDates> & rhs)
//    {
//        //return  lhs.second < rhs.second;
//        // return true if lhs < rhs
//        // return false otherwise
//        
//        // step 1:  compare years.  if lhs.year < rhs.year, return true.  else, continue
//        // step 2: compare months.  if lhs.month < rhs.month, return true.  else, continue.
//        //    note:  don't just compare the strings, else "AUG" < "JAN" etc
//        // step 3: compare days.  if lhs.day < rhs.day, return true.  else, return false.
//        return true;
//    }
//};

class TextCompressor {
    public:
//    string longestRepeat(string sourceText)
//    {
//        map<string,int,CompareDates> m;
//        for ( int i =  0 ; i < sourceText.length() ; i ++ )
//        {
//            
//            for ( int j = i + 2  ; j < sourceText.length() ; j ++ )
//            {
//                string searchString = sourceText.substr(i,j);
//                //string longest =  findlongest(sourceText,searchString,m);
//            }
//        }
//        
//        sort(m.begin(), m.end(),CompareDates());
//        return "";
//        //return m[m.size()-1];
//    }
//    
    
//    string findlongest(string& source, string& searchStr, map<string,int,CompareDates>& m)
//    {
//        int c = 0;
//        for ( int i = 0 ; i < source.length() - searchStr.length(); i++ )
//        {
//            c = i;
//            int j = 0 ;
//            bool found = true ;
//            for (  ; j < searchStr.length() ; j++ )
//            {
//                if ( source[c++] != searchStr[j])
//                {
//                    found = false;
//                    break;
//                }
//            }
//            if ( found )
//            {
//                int val = m[searchStr];
//                val++;
//                m[searchStr] = val;
//            }
//        }
//        return searchStr;
//    }
};

//// CUT begin
//ifstream data("/Users/vishal 1/Algorithm/AlgorithmTutorials/TopCoder/SRM 222/TextCompressor.sample");
////ifstream data("TextCompressor.sample");
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
//bool do_test(string sourceText, string __expected) {
//    time_t startClock = clock();
//    TextCompressor *instance = new TextCompressor();
//    string __result = instance->longestRepeat(sourceText);
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
//        string sourceText;
//        from_stream(sourceText);
//        next_line();
//        string __answer;
//        from_stream(__answer);
//
//        cases++;
//        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
//            continue;
//
//        cout << "  Testcase #" << cases - 1 << " ... ";
//        if ( do_test(sourceText, __answer)) {
//            passed++;
//        }
//    }
//    if (mainProcess) {
//        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
//        int T = time(NULL) - 1406867652;
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
//        cout << "TextCompressor (250 Points)" << endl << endl;
//    }
//    return run_test(mainProcess, cases, argv[0]);
//}
//// CUT end
