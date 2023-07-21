#include <iostream>
#include <iomanip>
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

double probability(int *a, int* r, double* p, int n, int m){
    vvi prefix; prefix.resize(n, vi(0));
    for (int i=0; i<m; i++) {
        prefix[r[i] - 1].push_back(i);
    }
    bool permpossible[n] = {0};
    int mx = 0;
    for (int i=0; i<n; i++) {
        mx = max(a[i], mx);
        if (mx == i + 1){
            permpossible[i] = 1;
        }
    }
    double prob[n];
    prob[0] = permpossible[0];
    for (int i=1; i<n; i++) {
        if (!permpossible[i]){
            prob[i] = 0; continue;
        }
        double prod = 1;
        for (auto k : prefix[i]){
            prod*=(1-p[k]);
        }
        prob[i] = 1 - prod;
        if (a[i] == i + 1 && permpossible[i-1]){
            prob[i] += prob[i-1] - prob[i-1]*prob[i];
        }
    }
    return prob[n-1];
}

void solve() {
    int n, m; cin >> n >> m;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int r[m]; double p[m];
    for (int i=0; i<m; i++) {
        cin >> r[i] >> p[i];
    }
    cout << fixed << setprecision(6) << probability(a, r, p, n, m) << "\n";
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