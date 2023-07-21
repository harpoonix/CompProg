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

bool answer(int &n, int &m){
    if (n==1 || m==1){return true;}
    if (n%m==0 || n <= m){
        return false;
    }
    int q_min = n/m + 1, q_max = n/2;
    for (int k=2; k<n; k++) {
        if (n%k==0){
            // k is a divisor
            // for (int q=q_min; q<= q_max; q++) {
            //     if (k*q<=n){
            //         if (m*(q-1) + k >= n){
            //             // found it!
            //             return false;
            //         }
            //     }
            //     else {
            //         break;
            //     }
            // }
            return (k > m);
        }
    }
    return true;
}

void solve() {
    int n, m; cin >> n >>m;
    cout << (answer(n, m) ? "YES" : "NO") << "\n";
}

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    // precalc()
    
    int t; cin>>t;
    while(t--) solve();
    
    
}