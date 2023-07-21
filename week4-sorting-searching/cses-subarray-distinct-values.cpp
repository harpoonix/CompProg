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
    int n, k; cin >> n >> k;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    ll l = 0, r = 0;
    ll total = 0, distinct = 0;
    map<ll, ll> elements;
    while (l < n){
        if (elements.find(a[r]) != elements.end() && elements[a[r]]!=0){
            elements[a[r]]++;
            // cout << a[r] << "count is now " << elements[a[r]] << "\n";
        }
        else {
            elements.insert(mp(a[r], 1)); distinct++;
            // cout << "insert new " << a[r] << "\n";
        }
        if (distinct > k){
            total += r-l;
            // cout << "add " << r-l << "\n";
            while (true){
                if (elements[a[l]] > 1){
                    elements[a[l]]--; l++; total+=r-l;
                }
                else {
                    elements.erase(a[l]); l++; distinct = k; break;
                }
            }
        }
        r++;
        if (r==n){
            total+=(n-l)*(n-l+1)/2;
            // cout << "add " << (n-l)*(n-l+1)/2 << " when l is " << l << "\n";
            break;
        }
    }
    cout << total << "\n";
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