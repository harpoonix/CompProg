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

bool possible(ll *a, ll *b, int n, int k, ll cookies){
    ll shortage = 0;
    for (int i=0; i<n; i++) {
        if ((cookies*a[i] - b[i] > 0)){
            shortage += cookies*a[i] - b[i];
            if (shortage > k){
                return false;
            }
        }
    }
    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;
    ll a[n], b[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }
    ll low = 0, high = INT32_MAX, mid;
    while (low < high){
        mid = 1+low+(high-low)/2;
        if (possible(a, b, n, k, mid)){
            low = mid;
        }
        else {
            high = mid - 1;
        }
    }
    cout << low << "\n";

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