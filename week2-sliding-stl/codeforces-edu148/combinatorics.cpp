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

#define NUM (ll)(998244353)

void solve() {
    ll n, a1, x, y, m, k; cin >> n >> a1 >> x >> y >> m >> k;
    ll a[n];
    for (int i=1; i<n; i++) {
        a[i] = (a[i-1]*x + y)%m;
    }
    ll b[k+1][n];
    b[0][0] = a[0]%NUM;
    for (int i=1; i<n; i++) {
        b[0][i] = (b[0][i-1] + a[i])%NUM;
    }
    for (int j=1; j<=k; j++) {
        b[j][0] = (j==1 ? a[0]%NUM : 0);
        for (int i=1; i<n; i++) {
            b[j][i] = (b[j-1][i-1] + b[j][i-1])%NUM;
        }
    }
    // now b[k] is our array b
    ll c[n];
    for (ll i=0; i<n; i++) {
        c[i] = (i+1)*b[k][i];
    }
    ll ans = c[0];
    for (int i=1; i<n; i++) {
        ans = ans^c[i];
    }
    cout << ans << "\n";
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