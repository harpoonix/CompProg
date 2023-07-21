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

ll beauty(int *b, int n){
    ll prefix[n], suffix[n];
    for (int i=0; i<n; i++) {
        prefix[i] = b[i] + i+1;
    }
    for (int i=1; i<n; i++) {
        prefix[i] = max(prefix[i-1], prefix[i]);
    }
    for (int i=n-1; i>=0; i--) {
        suffix[i] = b[i] - (i+1);
    }
    for (int i=n-2; i>=0; i--) {
        suffix[i] = max(suffix[i], suffix[i+1]);
    }
    ll best = 0;
    for (int m = 1; m < n-1; m++){
        best = max(best, b[m] + prefix[m-1] + suffix[m+1]);
    }
    return best;
}

void solve() {
    int n; cin >> n;
    int b[n];
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }
    cout << beauty(b, n) << "\n";
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