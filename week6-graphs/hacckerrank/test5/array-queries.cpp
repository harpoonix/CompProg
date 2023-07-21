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
    int n, m; cin >> n >> m;
    int a[n], b[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int type, i, j;
    while (m--){
        cin >> type >> i >> j;
        if (type == 1){
            for (int k=0; k<j-i+1; k++) {
                b[k] = a[i + k];
            }
            for (int k=0; k<i; k++) {
                a[j-i+1 + k] = a[k];
            }
            for (int k=0; k<j-i+1; k++) {
                a[k] = b[k];
            }
        }
        
    }
    cout << abs(a[0] - a[n-1]) << "\n";
    for (int i=0; i<n; i++) {
        cout << a[i] << " ";
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
    solve();
    
    
}