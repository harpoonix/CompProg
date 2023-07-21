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

int rounds(int *arr , int * pos, int n, int m, pii* swaps){
    int round = 1, currentpos = pos[0];
    int drop[n] = {0};
    for (int i=1; i<n; i++) {
        if (pos[i] < currentpos){
            round++;
            drop[i-1] = 1;
        }
        currentpos = pos[i];
    }
    int a, b;
    // round is the number of rounds with no swaps
    for (int i=0; i<m; i++) {
        a = swaps[i].first; b = swaps[i].second;
        pos[arr[a] - 1] = b; pos[arr[b] - 1] = a;
        swap(arr[a-1], arr[b-1]); 
        if (b > pos[arr[a]]){
            if (drop[arr[a] - 1]){}
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    int a[n], pos[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
        pos[a[i] - 1] = i;
    }
    pii swap[m];
    for (int i=0; i<m; i++) {
        cin >> swap[i].first >> swap[i].second;
    }
    cout << rounds(a, pos, n, m, swap) << "\n";
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