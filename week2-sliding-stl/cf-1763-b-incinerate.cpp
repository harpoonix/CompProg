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

struct monster{
    int h; int p;
    bool operator<(monster const & m){
        return h < m.h;
    }
};

bool operator<(const int & k, const monster & m){
    return k < m.h;
}

void solve() {
    int n, k; cin >> n >> k;
    monster mons[n];
    for (int i=0; i<n; i++) {
        cin >> mons[i].h;
    }
    for (int i=0; i<n; i++) {
        cin >> mons[i].p;
    }
    sort(mons, mons+n); int start = 0;
    int weak[n]; weak[n-1] = mons[n-1].p;
    for (int i=n-2; i>=0; i--) {
        weak[i] = min(weak[i+1], mons[i].p);
    }
    int damage = 0;
    while (k > 0){
        monster* it = upper_bound(mons + start, mons + n, damage + k);
        damage+=k;
        // cout << "with k = " << k << " can kill " << (it - mons) << "\n";
        if (it == mons + n){
            cout << "YES\n"; return;
        }
        else {
            start = it - mons;
            k-=weak[start];
        }
    }
    cout << "NO\n";
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