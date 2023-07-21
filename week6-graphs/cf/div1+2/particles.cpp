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
    int n; cin >> n;
    ll c[n];
    bool negative = 1;
    for (int i=0; i<n; i++) {
        cin >> c[i];
        if (c[i] > 0){
            negative = 0;
        }
    }
    if (negative){
        ll charge = INT32_MIN;
        for (int i=0; i<n; i++) {
            charge = max(charge, c[i]);
        }
        cout << charge << "\n";
        return;
    }
    ll odd = 0; ll even = 0;
    for (int i=0; i<n; i++) {
        if (i%2){
            odd+=max(c[i], ll(0));
        }
        else {
            even+=max(c[i],  ll(0));
        }
    }
    cout << max(odd, even) << "\n";

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