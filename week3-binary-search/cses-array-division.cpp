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

bool possible(ll *x, ll sum, ll n, ll k){
    ll subarrays = 0, currentsum = 0;
    for (ll i=0; i<n; i++) {
        if (x[i] > sum){
            return false;
        }
        if (currentsum + x[i] > sum){
            subarrays+=1;
            currentsum = x[i];
        }
        else {
            currentsum += ll(x[i]);
        }
    }
    subarrays+=1;
    return (subarrays <= k);
}

void solve() {
    ll n, k, total;
    cin >> n >> k;
    ll x[n];
    for (int i=0; i<n; i++) {
        cin >> x[i];
        total += x[i];
    }
    ll l = 1, r = total, mid;
    while (l < r){
        mid = l + (r-l)/2;
        if (possible(x, mid, n, k)){
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << l << "\n";

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