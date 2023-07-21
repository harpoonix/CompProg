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

void snowflake(set<int> &flakes){
    for (int k=2; k<1000; k++) {
        int s = 0;
        ll tot = 0, power = 1;
        while (tot+power <= 1e6 + 1){
            tot += power;
            if (s >= 2){
                flakes.insert(tot);
                // cout << tot << "\n";
            }
            power*=ll(k); s++;
        }
    }
}

void solve() {
    int n; cin >> n;
    set<int> flakes;
    snowflake(flakes);
    cout << (flakes.count(n) ? "YES\n" : "NO\n");
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