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

int mex(int* a, int n){
    set<int> nums;
    for (int i=0; i<n; i++) {
        nums.insert(a[i]);
    }
    int m = n;
    for (int i=0; i<n; i++) {
        if (!nums.count(i)){
            m = i;
            break;
        }
    }
    return m;
}

int mex(set<int> &nums, int n){
    int m = n;
    for (int i=0; i<n; i++) {
        if (!nums.count(i)){
            m = i;
            break;
        }
    }
    return m;
}

void solve() {
    int n; cin >> n;
    int a[n];
    set<int> nums;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        nums.insert(a[i]);
    }
    int m = mex(a, n);
    if (m == n){
        cout << "NO\n"; return;
    }
    // if m+1 is in set
    if (nums.count(m+1)){
        int l = n, r = 0;
        for (int i=0; i<n; i++) {
            if (a[i] == m+1){
                l = min(l, i); r = max(r, i);
            }
        }
        for (int i=l; i<=r; i++) {
            a[i] = m;
        }
        int m_ = mex(a, n);
        cout << (m_ == m+1 ? "YES\n":"NO\n"); return;
    }
    for (int i=0; i<n; i++) {
        if (a[i] > m+1){
            cout << "YES\n"; return;
        }
    }
    // look for pair, should exist because m is not n
    cout << "YES\n";
}

void precalc() {
    
}

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    // precalc()
    
    int t; cin>>t;
    while(t--) solve();
    
    
}