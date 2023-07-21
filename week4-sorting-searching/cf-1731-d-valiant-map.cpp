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

#define array(i, j) (i < 0 || j < 0 ? 0 : cumsum[i][j])

bool cube(vvi &heights, int n, int m, int side){
    bool taller[n][m];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            taller[i][j] = (heights[i][j] >= side);
        }
    }
    int cumsum[n][m]; cumsum[0][0] = taller[0][0];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cumsum[i][j] = taller[i][j] + array(i-1, j) + array(i, j-1) - array(i-1, j-1);
        }
    }
    for (int i=0; i<=n-side; i++) {
        for (int j=0; j<=m-side; j++) {
            if (cumsum[i + side-1][j + side-1] + array(i-1, j-1) - array(i+side-1, j-1) - array(i-1, j + side - 1) >= side*side ){
                return true;
            }
        }
    }
    return false;

}

int square(vvi& heights, int n, int m){
    int low = 1, high = min(n, m), mid;
    while (low < high){
        mid = 1 + (high + low)/2;
        if (cube(heights, n, m, mid)){
            low = mid;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

void solve() {
    int n, m; cin >> n >> m;
    vvi heights; heights.resize(n, vi(m, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> heights[i][j];
        }
    }
    cout << square(heights, n, m) << "\n";
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