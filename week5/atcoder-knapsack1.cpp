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
    ll dp[n][weight + 1];
    for (int i=0; i<n; i++) {
        dp[i][0] = 0;
    }
    for (int i=1; i<=weight; i++) {
        dp[0][i] = (w[0] > i ? 0 : v[0]);
    }
    for (int i=1; i<n; i++) {
        for (int j=1; j<=weight; j++) {
            dp[i][j] = max(dp[i-1][j], (j - w[i] < 0 ? 0 : dp[i-1][j - w[i]] + v[i]));
        }
    }
    cout << dp[n-1][weight] << "\n";

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