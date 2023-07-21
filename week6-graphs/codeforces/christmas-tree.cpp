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

double area(double *y, int &n , double &d, double& h){
    double total = 0; double x;
    for (int i=0; i<n; i++) {
        x = h*d/2;
        if (i!=n-1 && y[i + 1] < y[i] + h){
            x -= (1-(y[i+1] - y[i])/h)*(1-(y[i+1] - y[i])/h)*x;
        }
        total += x;
    }
    return total;
}

void solve() {
    int n;
    double d, h; cin >> n >> d >> h;
    double y[n];
    for (int i=0; i<n; i++) {
        cin >> y[i];
    }
    cout << fixed << setprecision(6) << area(y, n, d, h) << "\n";
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