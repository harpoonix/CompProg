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

#define MOD 1000000007
ll* a = new ll[int(1e6 + 1 + 1e-3)];
ll* b = new ll[int(1e6 + 1 + 1e-3)];

void solve() {
    int n; cin >> n;
    cout << (a[n] + b[n])%MOD << "\n";
}

void precalc() {
    a[1] = 1; b[1] = 1;
    for (int i=2; i<=1e6 + 1e-5; i++) {
        a[i] = 2*a[i-1] + b[i-1];
        b[i] = 4*b[i-1] + a[i-1];
        a[i]%=MOD; b[i]%=MOD;
    }
}

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    precalc();

    int t; cin>>t;
    while(t--) solve();
    
    
}