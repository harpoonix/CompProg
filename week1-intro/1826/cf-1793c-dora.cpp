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

void subsegment(int * a, int n){
    int l = 0, r = n-1, mini = 1, maxi = n;
    while (l < r){
        if (a[l]==mini || a[r] == mini){
            if (a[l]==mini) {l++;}
            else {r -- ;}
            mini++;
        }
        else if (a[l]==maxi || a[r] == maxi){
            if (a[l]==maxi){l++;}
            else {r--;}
            maxi --;
        }
        else {
            cout << l + 1 << " " << r + 1 << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

void solve() {
    int n; cin >> n;
    int a[n]; 
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    subsegment(a, n);
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