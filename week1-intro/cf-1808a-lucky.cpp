#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
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

int score(int x) {
    int mx = 0, mn = 9;
    int dig = 0;
    while (x > 0){
        dig = x%10;
        mx = max(mx, dig); mn = min(mn, dig);
        x = x/10;
    }
    // cout << mx - mn << "\n";
    return mx - mn;
}

void solve() {
    int l, r;
    cin >> l >> r;
    int maxscore = -1, bestint = -1;
    for (int i=l; i<=r && i <= l + 99; i++) {
        // cout << i << " ";
        int sc = score(i);
        if (sc > maxscore){
            bestint = i;
            maxscore = sc;
        }
    }
    cout << bestint << "\n";
}

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    // precalc()
    
    int t; cin>>t;
    while(t--) solve();
    
    
}