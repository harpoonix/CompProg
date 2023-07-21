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
    int n; cin >> n;
    int l[n];
    for (int i=0; i<n; i++) {
        cin >> l[i];
    }
    // vector<vector<bool>> lines;
    // for (int i=0; i<n; i++) {
    //     if (l[i] == 0){
    //         lines.push_back(vector<bool>(100, false));
    //         lines[lines.size() - 1][0] = 1;
    //     }
    //     else {
    //         bool placed = 0;
    //         for (auto line : lines){
    //             if (line[l[i]] == false){
    //                 line[l[i]] = true;
    //                 placed = 1;
    //                 break;
    //             }
    //         }
    //         if (!placed){
                
    //         }
    //     }
    // }

    int count[100] = {0};
    for (int i=0; i<n; i++) {
        count[l[i]]++;
    }
    for (int i=0; i<99; i++) {
        if (count[i] < count[i + 1]){
            cout << "NO\n"; return;
        }
    }
    cout << "YES\n";
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