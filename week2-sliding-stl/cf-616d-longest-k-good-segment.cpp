#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stdio.h>
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
    int n, k; cin >> n >> k;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    map<int, int> unique; int card = 0, r = 0, max_range = 0, r_range = 0;
    for (int l=0; l<n; l++) {
        while (r < n){
            if (!unique.count(a[r])){
                if (card==k){
                    break;
                }
                card++;
                unique.insert(mp(a[r], 1));
            }
            else {
                unique[a[r]] = unique[a[r]] + 1;
            }
            r++;
        }
        if (r - l > max_range){
            max_range = r-l; r_range = r - 1;
        }
        if (unique[a[l]] > 1){
            unique[a[l]] = unique[a[l]] - 1 ;
        }
        else {
            unique.erase(a[l]); card--;
        }
    }
    cout << r_range - max_range + 1 + 1 << " " << r_range + 1<< "\n";
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