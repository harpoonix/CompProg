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
    int n, q; cin >> n >> q;
    int t, x, y, x2, y2;
    set<int> freerows, freecols;
    for (int i=1; i<=n; i++) {
        freerows.insert(i); freecols.insert(i);
    }
    int row[n+1] = {0};
    int col[n+1] = {0};
    while (q--){
        cin >> t >> x >> y;
        if (t == 1){
            row[x]++; col[y]++;
            if (row[x] == 1){
                freerows.erase(x); 
            }
            if (col[y] == 1){
                freecols.erase(y);
            }
        }
        if (t==2){
            row[x]--; col[y]--;
            if (row[x]==0){
                freerows.insert(x);
            }
            if (col[y] == 0){
                freecols.insert(y);
            }
        }
        if (t==3){
            cin >> x2 >> y2;
            auto firstrow = freerows.lower_bound(x);
            auto firstcol = freecols.lower_bound(y);
            if (firstrow == freerows.end() || *firstrow > x2 || firstcol == freecols.end() || *firstcol > y2){
                // well covered
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        }
    }
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