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
    int n; cin >> n;
    int a[n];
    bool keep[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
        keep[i] = 1;
    }
    bool allsame = 1;
    for (int i=1; i<n; i++) {
        if (a[i]!=a[0]){
            allsame = false;
            break;
        }
    }
    if (allsame){
        cout << 1 << "\n"; return;
    }
    int l = 0, c = 1, r = 2, left = n;
    while (r < n){
        if ((a[c] <= a[l] && a[c] >= a[r]) || (a[c] >= a[l] && a[c] <= a[r])){
            // cout << l << " " << c <<" " << r << "\n";
            left--;
            keep[c] = 0;
        }
        else {
            do {
                l++;
            } while (keep[l] == 0);
        }
        c++; r++;
    }
    cout << left << "\n";
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