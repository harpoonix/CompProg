#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
//#include <cmath>
// #include <stack>
// #include <queue>
#include <deque>
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

ll g(ll k, ll * a, ll *b, const int &n){
    ll count = 0;
    deque<int> arange;
    deque<int> brange;
    int l = 0, r = 0, f; bool goingOn = false;
    for (int r = 0; r < n; r++){
        while (!arange.empty() && a[arange.back()] <= a[r]){
            arange.pop_back();
        }
        arange.push_back(r);
        while (!brange.empty() && b[brange.back()] >= b[r]){
            brange.pop_back();
        }
        brange.push_back(r);
        f = a[arange.front()] - b[brange.front()];
        while (f > k && l < n){
            if (arange.front() <= l){
                arange.pop_front();
            }
            if (brange.front() <= l){
                brange.pop_front();
            }
            l++;
            if (l > n || arange.empty() || brange.empty()){
                break;
            }
            f = a[arange.front()] - b[brange.front()];
        }
        if (l > r){continue;}
        count+=r-l+1;
    }
    return count;
}

ll mink(ll u, ll *a, ll*b, const int &n){
    ll low = 1, high = 1e7 + 1e-5, mid;
    while (low < high){
        mid = (low+high)/2;
        if (g(mid, a, b, n) < u){
            low = mid+1;
        }
        else {
            high = mid;
        }
    }
    return (g(low, a, b, n) == u ? low:-1);
}

void solve() {
    ll n, u; cin >> n >> u;
    ll a[n], b[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }
    cout << mink(u, a, b, n) << "\n";
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