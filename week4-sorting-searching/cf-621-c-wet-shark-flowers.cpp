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

double dollars(int *l, int *r, int p, int n){
    double prob[n]; int first, last;
    for (int i=0; i<n; i++) {
        first = l[i] - l[i]%p + (l[i]%p == 0 ? 0 : p);
        last = r[i] - r[i]%p;
        double times = (last-first)/p + 1;
        prob[i] = (times)/(r[i] - l[i] + 1);
    }
    double exp[n];
    for (int i=0; i<n; i++) {
        exp[i] = prob[i] + prob[(i+1)%n] - prob[i]*prob[(i+1)%n];
        exp[i]*=2000;
    }
    for (int i=1; i<n; i++) {
        exp[0] += exp[i];
    }
    return exp[0];
}

void solve() {
    int n, p; cin >> n >> p;
    int l[n], r[n];
    for (int i=0; i<n; i++) {
        cin >> l[i] >> r[i];
    }
    cout << fixed << setprecision(6) << dollars(l, r, p, n) << "\n";
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