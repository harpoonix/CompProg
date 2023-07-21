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

struct project{
    int a, b, price;
    bool operator<(const project & p){
        return a < p.a;
    }
};

bool operator<(const int & n, const project & p){
    return (n < p.a);
}

void solve() {
    int n; cin >> n;
    project p[n];
    for (int i=0; i<n; i++) {
        cin >> p[i].a >> p[i].b >> p[i].price;
    }
    sort(p, p+n);
    ll dp[n] = {0};
    dp[n-1] = p[n-1].price;
    for (int i=n-2; i>=0; i--) {
        auto j = upper_bound(p + i + 1, p + n, p[i].b);
        // if (p[i].price + (j!=p+n ? dp[j - p] : 0) > dp[i+1]){
        //     cout << "for " << i << " take this project and then continue from " << j-p <<"\n";
        // }
        // else {
        //     cout << "for " << i << " don't take this project, same as " << i+1 << "\n";
        // }
        dp[i] = max(ll(p[i].price) + (j!=p+n ? dp[j - p] : 0), dp[i+1]);
    }
    cout << dp[0] << "\n";
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