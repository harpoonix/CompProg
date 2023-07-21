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
    int q, ev; cin >> q;
    ll a, b, n;
    ll low = 1, high = INT64_MAX, l, r;
    while (q--){
        cin >> ev;
        if (ev == 1){
            cin >> a >> b >> n;
            l = (a-b)*(n-2) + a; r = l + a - b; l += 1;
            if (n==1){
                l = 1;
            }
            if (l > high || r < low){
                cout << "0 ";
                continue;
            }
            low = max(low, l); high = min(high, r);
            // cout << " low " << low << "high " << high << "\n";
            cout << "1 ";
        }
        else {
            cin >> a >> b;
            if (low <= a && high <= a){
                cout << 1 << " ";
                continue;
            }
            double f1 = double(low - a)/double(a - b) - 1e-11, f2 = double(high - a)/double(a - b) - 1e-11;
            if (ceil(f1) == ceil(f2)){
                cout << ll(ceil(f1)) + 1 << " ";
            }
            else {
                cout << -1 << " ";
            }
        }
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