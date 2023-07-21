#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
//#include <cmath>
// #include <stack>
// #include <queue>
#include <deque>
// #include <priority_queue>
//#include <ctime>
//#include <chrono>
#include <random>
#include <set>
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

void solve() {
    int n; cin >> n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int largestscore = 0;
    int pos[n];
    for (int i=0; i<n; i++) {
        pos[a[i]-1] = i + 1;
    }
    int mn = n+1, mx = 0;
    for (int i=1; i<n; i++) {
        mn = min(mn, pos[n-i]); mx = max(mx, pos[n-i]);
        if (mx - mn + 1 == i){
            largestscore = max(largestscore, i);
        }
    }
    cout << largestscore << "\n";
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