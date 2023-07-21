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

ll cost(ll * d, int x, int n){
    ll cost = 0;
    multiset<int> sticks;
    for (int i=0; i<n; i++) {
        sticks.insert(d[i]);
    }
    while (sticks.size() > 1){
        ll merge = 0;
        auto it = sticks.begin();
        merge+=*it;
        sticks.erase(it);
        merge+= *(sticks.begin());
        sticks.erase(sticks.begin());
        sticks.insert(merge); cost+=merge;
    }
    return cost;
}

void solve() { 
    ll x, n; cin >> x >> n;
    ll d[n];
    for (int i=0; i<n; i++) {
        cin >> d[i];
    }
    cout << cost(d, x, n) << "\n";
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