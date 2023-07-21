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

void solve() {
    ll n, weight; cin >> n>> weight;
    ll w[n], v[n];
    for (int i=0; i<n; i++) {
        cin >> w[i] >> v[i];
    }
    ll dp[n][1 + n*1000]; // to make value of v, how much least weight do I need?
    for (int i=0; i<n; i++) {
        dp[i][0] = 0; // zero value zero weight
    }
    for (int i=1; i<=1000*n; i++) {
        dp[0][i] = (v[0] != i ? INT64_MAX/2 : w[0]);
    }
    for (int i=1; i<n; i++) {
        for (int j=1; j<=1000*n; j++) {
            dp[i][j] = min(dp[i-1][j], (j - v[i] < 0 ? INT64_MAX/2 : dp[i-1][j - v[i]] + w[i]));
        }
    }
    int maxval = 0;
    for (int i=1; i<=1000*n; i++) {
        if (dp[n-1][i]<=weight){
            maxval = i;
        }
    }
    cout << maxval << "\n";

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