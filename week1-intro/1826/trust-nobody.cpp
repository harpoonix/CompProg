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
    int n;
    cin >> n;
    int lies[n];
    for (int i=0; i<n; i++) {
        cin >> lies[i];
    }
    sort(lies, lies + n);

    if (lies[0]==n){
        cout << -1 << "\n"; return;
    }
    // no one lying
    if (lies[n-1] == 0){cout << 0 << "\n"; return;}


    // some people lying
    for (int i=0; i<n-1; i++) {
        if (lies[i] <= n - i - 1 && lies[i+1] > n-1-i){
            cout << n-1-i << "\n"; return;
        }
    }
    cout << -1 << "\n";
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