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

void solve() {
    int n, k; cin >> n >> k;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int delmin[n/2];
    for (int i=0; i<n; i+=2) {
        delmin[i/2] = a[i] + a[i + 1];
    }
    ll sum = 0;
    for (int i=2*k; i<n; i++) {
        // when only mins are removed
        sum+=(ll)(a[i]);
    }
    ll newsum = sum;
    for (int i=1; i<=k; i++) {
        newsum+= (ll)(delmin[k-i] - a[n-i]);
        sum = max(sum, newsum);
    }
    cout << sum << "\n";
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