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
    int n, k; cin >> n >> k;
    int a;
    vi plants;
    for (int i=0; i<n; i++) {
        cin >> a;
        if (a){
            plants.push_back(i);
        }
    }
    bool taken[plants.size()] = {0};
    int i = 0, j = 0;
    while (j < n){
        if (i >= n){
            cout << "-1\n"; return;
        }
        if (plants[i] >= j + k){
            cout << "-1\n"; return;
        }
        if (i!=plants.size() - 1 && plants[i+1] < j + k && !taken[i]){
            // cout << j << " maybe taken under next plant at " << plants[i+1] << "\n";
            i++;
        }
        else if(plants[i] <= j - k) {
            // cout << plants[i] << "cannot provide to " << j << "\n";
            i++; 
        }
        else {
            // cout << plants[i] << " providing to " << j << "\n";
            j++; taken[i] = 1; 
        }
    }
    int total = 0;
    for (int i=0; i<plants.size(); i++) {
        total+=taken[i];
    }
    cout << total << "\n";
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