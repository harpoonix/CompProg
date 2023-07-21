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
    int n, q; cin >> n >> q;
    ll ** rect = new ll*[1001];
    for (int i=0; i<1001; i++) {
        rect[i] = new ll[1001]();
    }
    int h, w;
    for (int i=0; i<n; i++) {
        cin >> h >>w;
        rect[h][w] += ll(h*w);
    }
    for (int i=2; i<=1000; i++) {
        rect[1][i] += rect[1][i-1];
        rect[i][1] += rect[i-1][1];
    }
    for (int i=2; i<=1000; i++) {
        for (int j=2; j<=1000; j++) {
            rect[i][j] += rect[i][j-1] + rect[i-1][j] - rect[i-1][j-1];
        }
    }
    int hs, ws, hb, wb;
    while (q--){
        cin >> hs>> ws>> hb>> wb;
        cout << rect[hb-1][wb-1] - rect[hb-1][ws]- rect[hs][wb - 1] + rect[hs][ws] << "\n";
    }
    for (int i=0; i<1001; i++) {
        delete[] rect[i];
    }
    delete[] rect;
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