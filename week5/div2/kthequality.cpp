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
    int A, B, C; ll k; cin >> A >> B >> C >> k;
    int cdigit = pow(10, C-1) + 1e-3;
    int bdigit = pow(10, B-1) + 1e-3;
    int adigit = pow(10, A-1) + 1e-3;
    int a, b, c, amin, amax, bmin, bmax, cmax, cmin;
    cmin = cdigit; cmax = 10*cdigit - 1;
    ll equalities = 0, addition = 0;
    amin = max(cmin - (10*bdigit - 1), adigit);
    amax = min(cmax - bdigit, 10*adigit - 1);
    bmin = max(bdigit, cmin - amax); bmax = min(10*bdigit - 1, cmax - amin);
    // cout << amin << " " << amax << " " << bmin << " " << bmax << " " << "\n";
    a = amin;
    bool crossed = false;
    while (a <= amax) {
        addition = min(cmax - a, bmax) - max(cmin - a, bmin) + 1;
        // cout << addition << " "; 
        if (equalities + addition >= k){
            crossed = true;
            break;
        }
        equalities+=addition;
        a++;
    }
    if (!crossed){
        cout << -1 << "\n"; return;
    }
    b = max(cmin - a, bmin) + (k - equalities) - 1;
    cout << a << " + " << b << " = " << a + b << "\n";

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