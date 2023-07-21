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
    int n, k, x; cin >> n >> k >> x;
    if (x!=1){
        cout << "YES\n" << n << "\n";
        for (int i=0; i<n; i++) {
            cout << "1 ";
        }
        // int q = n/k, r = n%k;
        // cout << q + r << "\n";
        // for (int i=0; i<q; i++) {
        //     cout << k << " ";
        // }
        // for (int i=0; i<r; i++) {
        //     cout << "1 ";
        // }
    }
    else {
        if (k==1){
            cout << "NO\n"; return;
        }
        else {
            if (n%2==0){
                cout << "YES\n" << n/2 << "\n";
                for (int i=0; i<n/2; i++) {
                    cout << "2 ";
                }
            }
            else {
                if (k==2){
                    cout << "NO\n";return;
                }
                else {
                    cout << "YES\n" << 1 + (n-3)/2 << "\n3 ";
                    for (int i=0; i<(n-3)/2; i++) {
                        cout << "2 ";
                    }
                }
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