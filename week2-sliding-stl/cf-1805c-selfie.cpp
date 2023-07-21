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

int binary_search(ll *k, int &n, ll &a, ll &b, ll &c){
    int l = 0, r = n-1, mid;
    while (l <= r){
        mid = l + (r-l)/2;
        if ((k[mid] - b)*(k[mid] - b) < 4*a*c){
            return k[mid];
        }
        else {
            if (k[mid] > b){
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
    }
    return INT32_MIN;
}

void solve() {
    int n, m; cin >>n >>m;
    ll k[n];
    for (int i=0; i<n; i++) {
        cin >> k[i];
    }
    ll a[m], b[m], c[m];
    for (int i=0; i<m; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    sort(k, k + n);
    int coeff;
    for (int i=0; i<m; i++) {
        coeff = binary_search(k, n, a[i], b[i], c[i]);
        if (coeff==INT32_MIN){
            cout << "NO\n";
        }
        else {
            cout << "YES\n" << coeff << "\n";
        }
    }
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