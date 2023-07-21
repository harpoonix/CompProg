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
    int n; cin >> n; cin.ignore();
    string s;
    getline(cin, s);
    string r; r.resize(n); reverse_copy(s.begin(), s.end(), r.begin());
    int lcs[n][n]; lcs[0][0] = (s[0] == r[0]);
    for (int i=1; i<n; i++) {
        lcs[0][i] = (lcs[0][i-1] || (s[0] == r[i]));
        lcs[i][0] = (lcs[i-1][0] || (s[i] == r[0]));
    }
    for (int i=1; i<n; i++) {
        for (int j=1; j<n; j++) {
            if (s[i] == r[j]){
                lcs[i][j] = 1 + lcs[i-1][j-1];
            }
            else {
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
    }
    int maxlcs = 0;
    for (int i=0; i<n-1; i++) {
        maxlcs = max(maxlcs, lcs[i][n-i-2]);
    }
    cout << maxlcs << "\n";
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