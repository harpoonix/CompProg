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

bool fixed_point_here(int l, int r){
    cout << "? " << l + 1 << " " << r + 1 << endl;
    int a[r-l+1];
    for (int i=0; i<r-l+1; i++) {
        cin >> a[i];
    }
    int parity = 0;
    for (int i=0; i<r-l+1; i++) {
        if (a[i] <= r + 1 && a[i] >= l + 1){
            parity = parity ^ 1;
        }
    }
    return parity;
}

void solve() { 
    int n; cin >> n;
    int low = 0, high = n-1, mid;
    while (low < high){
        mid = (low + high)/2;
        if (fixed_point_here(low, mid)){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    cout << "! " << low + 1 << endl;
}

void precalc() {
    
}

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    // precalc()
    
    int t; cin>>t;
    while(t--) solve();
    
    
}