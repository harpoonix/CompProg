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

bool covered(int* a, int* b, int n, int m, int r){
    int city = 0, tower = 0;
    while (city < n){
        if (abs(b[tower] - a[city]) <= r){
            city++;
        }
        else {
            if (b[tower] > a[city]){
                return false;
            }
            else {
                tower++;
                if (tower == m){
                    return false;
                }
            }
        }
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<m; i++) {
        cin >> b[i];
    }
    int small = 0, large = INT32_MAX, mid;
    while (small < large){
        mid = small + (large - small)/2;
        if (covered(a, b, n, m, mid)){
            large = mid;
        }
        else{
            small = mid + 1;
        }
    }
    cout << small << "\n";
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