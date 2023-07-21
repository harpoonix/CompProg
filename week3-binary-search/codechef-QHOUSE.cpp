#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
//#include <cmath>
// #include <stack>
// #include <queue>
// #include <deque>
// #include <priority_queue>
//#include <ctime>
//#include <chrono>
#include <random>
using namespace std;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// Usage: rng(), rng.min(), rng.max()

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i=a; i<b; i++)

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;

inline bool inquire(const int & x, const int &y, string &s){
    cout << "? " << x << " " << y << endl;
    getline(cin, s);
    return (s[0] == 'Y');
}

int findLength(bool x, const int fixed, int min){
    int l = min, r = 1000, mid;
    string s;
    while (l<r){
        mid = 1 + (l+r)/2;
        if ((x ? inquire(mid, fixed, s) : inquire(fixed, mid, s))){
            l = mid;
        }
        else {
            r = mid-1;
        }
    }
    return l;
}

void solve() {
    int a = findLength(true,  0, 0);
    // cout << "side length is " << a << endl;
    int h = findLength(false, 0, 0);
    // cout << "height of triangle is " << h-2*a << endl;
    int b = findLength(true, 2*a, a);
    cout << "! " << 4*a*a + b*(h - 2*a) << endl;
}

void precalc() {
    
}

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    // precalc()
    solve();
    
    
}