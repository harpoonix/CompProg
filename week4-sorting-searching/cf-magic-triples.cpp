// Codeforces G1 1822
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
#include <set>
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

const int MAX = 1e6;
int numbers[1 + MAX] = {0};

void solve() {
    int n; cin >> n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
        numbers[a[i]]++;
    }
    ll pairs = 0;
    for (int i=0; i<n; i++) {
        pairs += ll(numbers[a[i]] - 1)*ll(numbers[a[i]] - 2);
        // for other factors
        for (int j=2; a[i]*j*j<=MAX; j++) {
            pairs += ll(numbers[j*a[i]])*ll(numbers[j*j*a[i]]);
        }
    }
    cout << pairs << "\n";
    for (int i=0; i<n; i++) {
        numbers[a[i]]--;
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