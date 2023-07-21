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

bool possible(ll * t, ll n, ll time, ll k){
    ll total = 0;
    for (ll i=0; i<n; i++) {
        total += (time/(t[i]));
        if (total >= k){
            return true;
        }
    }
    return false;
}

ll mintime(ll * t, ll n, ll k){
    ll l = 1, r = ll(INT64_MAX >> 3), mid;
    while (l < r){
        mid = l + (r-l)/2;
        if (possible(t, n, mid, k)){
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    return l;
}

void solve() {
    ll n, k; cin >> n >> k;
    ll t[n];
    for (int i=0; i<n; i++) {
        cin >> t[i];
    }
    cout << mintime(t, n, k) << "\n";
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