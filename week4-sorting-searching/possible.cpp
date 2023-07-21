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
    int n, b;
    cin >> n  >> b;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int binary[30] = {0}; set<int> zeros;
    int c = b;
    for (int i=0; i<30; i++) {
        binary[i] = (c)&1;
        if (binary[i] == 0){
            zeros.insert(i);
        }
        c = (c >> 1);
    }
    bool subsequence[n];
    for (int i=0; i<n; i++) {
        subsequence[i] = 1;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<30; j++) {
            if (binary[j] == 1){
                if (((a[i] >> j)&1)==0){
                    subsequence[i] = 0;
                    break;
                }
            }
        }
        if (subsequence[i] == 1){
            for (int j=0; j<30; j++) {
                if (binary[j] == 0){
                    if (((a[i] >> j)&1)==0){
                        zeros.erase(j);
                    }
                }
            }
            if (zeros.empty()){
                cout << "YES\n"; return;
            }
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