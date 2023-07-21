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

#define NUM 1000000007

void solve() {
    ll n, m;
    cin >> n >> m;
    ll ans = ((n%NUM)*(m%NUM))%NUM;
    ll s = 0;
    m = min(m, n);
    for (ll i=1; i*i<=n && i<=m; i++) {
        s+=(ll(n/i)*i)%NUM;
        s%=NUM;
    }
    for (ll k=max(n/m, ll(1)); (ll(sqrt(n))*ll(sqrt(n)) == n ? k < ll(sqrt(n)) : k <= sqrt(n)); k++) {
        ll l = (n/(k+1)) + 1;
        ll r = min(m, n/k);
        if (l > r){
            continue;
        }
        s+=((((r-l+1)*((l+r)/2))%NUM)*((k)%NUM))%NUM;
        s%=NUM;
    }
    ans = (ans-s)%NUM;
    cout << (ans%NUM >= 0 ? ans%NUM : NUM + ans%NUM) << "\n";
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