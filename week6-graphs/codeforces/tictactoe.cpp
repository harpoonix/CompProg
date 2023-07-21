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
    char grid[3][3];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cin >> grid[i][j];
        }
    }
    // horizontal
    for (int i=0; i<3; i++) {
        if (grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2]){
            if (grid[i][0] != '.'){
                cout << grid[i][0] << "\n"; return;
            }
        }
    }
    // vertical
    for (int i=0; i<3; i++) {
        if (grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i]){
            if (grid[0][i] != '.'){
                cout << grid[0][i] << "\n"; return;
            }
        }
    }
    // diagonal
    if (grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2]){
        if (grid[0][0] != '.'){
            cout << grid[0][0] << "\n"; return;
        }
    }
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]){
        if (grid[1][1] != '.'){
            cout << grid[1][1] << "\n"; return;
        }
    }
    cout << "DRAW\n";
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