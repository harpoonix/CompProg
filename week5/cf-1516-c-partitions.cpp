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

#define BOUND 2000

bool isGood (bool** dp, int * a, int n){
    dp[1][n*BOUND + a[0]] = 1; dp[1][n*BOUND - a[0]] = 1;
    // for (int i=0; i<n; i++) {
    //     dp[1][n*BOUND + a[i]] = 1; dp[1][n*BOUND - a[i]] = 1;
    // }
    for (int i=2; i<=n; i++) {
        for (int j=0; j<=2*n*BOUND; j++) {
            dp[i][j] = ((j - a[i-1] < 0 ? 0 : dp[i-1][j - a[i - 1]]) || (j+  a[i-1] > 2*n*BOUND ? 0 : dp[i-1][j + a[i - 1]]));
        }
    }
    return !dp[n][n*BOUND];
}

void solve() {
    int n; cin >> n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    bool** dp = new bool*[n+1];
    for (int i=0; i<n+1; i++) {
        dp[i] = new bool[2*n*BOUND + 1]();
    }
    if (isGood(dp, a, n)){
        cout << 0 << "\n";
    }
    else {
        // remove odd element, or divide by 2 until an element becomes odd
        cout << 1 << "\n";
        bool found = 0;
        while (!found){
            for (int i=0; i<n; i++) {
                if (a[i]%2){
                    cout << i + 1 << "\n";
                    found = 1;
                    break;
                }
                a[i]/=2;
            }
        }
    }
    for (int i=0; i<n+1; i++) {
        delete[] dp[i];
    }
    delete[] dp;
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