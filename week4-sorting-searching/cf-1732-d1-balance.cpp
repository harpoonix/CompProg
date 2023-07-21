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

ll mex(set<ll> &s, ll k, map<ll, ll> &mem){
    auto it = mem.find(k); bool exist = 0;
    if (it != mem.end()){
        exist = 1;
    }
    for (ll i=(exist ? it->second : k); 1; i+=k) {
        if (!s.count(i)){
            if (exist){
                it->second = i;
            }
            else {
                mem.insert(mp(k, i));
            }
            return i;
        }
    }
    cout << "something went wrong\n";
}

void solve() {
    int q; cin >>  q;
    char c; ll x, k;
    set<ll> s;
    map<ll, ll> memory;
    while(q--){
        cin >> c;
        if (c=='+'){
            cin >> x;
            s.insert(x);
        }
        if (c == '?'){
            cin >> k;
            cout << mex(s, k, memory) << "\n";
        }
    }
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