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
#define input(a, n) ll a[n]; for (int i=0; i<n; i++) { \
    cin >> a[i]; \
}

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;

void solve() {
    int n; cin >> n;
    input(a, n);
    input (b, n);
    ll demand[n];
    demand[n-1] = b[n-1];
    for (int i=n-2; i>=0; i--) {
        demand[i] = demand[i+1] + b[i];
    }
    vvi supplyend; supplyend.resize(n, vi(0));
    for (int i=0; i<n; i++) {
        if (demand[i] <= a[i]){
            continue;
        }
        ll * ending = upper_bound(demand + i, demand + n, demand[i] - a[i], greater<ll>()) - 1;
        supplyend[ending - demand].push_back(i);
    }
    ll drink[n]; int ended = 0;
    for (int i=0; i<n; i++) {
        drink[i] = (i + 1 - ended)*b[i];
        if (supplyend[i].size() > 0){
            for(auto j : supplyend[i]){
                ended++; drink[i]-=b[i];
                drink[i]+=a[j] - (demand[j] - demand[i]);
            }
        }
    }
    for (int i=0; i<n; i++) {
        cout << drink[i] << " ";
    } 
    cout << "\n";

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