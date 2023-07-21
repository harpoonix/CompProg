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

int water(int *h, int n){
    if (n < 3){return 0;}
    int water = 0;
    int left = 0, right = 0; bool open = false;
    for (int i=0; i<n; i++) {
        if (open){
            right = (h[right] > h[i] ? right : i);
            if (h[right] > h[left]){
                open = false;
                for (int j=left + 1; j<right; j++) {
                    water += h[left] - h[j];
                }
            }
        }
        else {
            if (i==n-1) {continue;}
            if (h[i+1] < h[i]){
                open = true;
                left = i;
                right = left + 1;
            }
        }
    }
    if (open){
        for (int i=left + 1; i<right; i++) {
            water+=h[right] - h[i];
        }
    }
    return water;
}

void solve() {
    int n; cin >>n ;
    int h[n]; 
    for (int i=0; i<n; i++) {
        cin >> h[i];
    }
    cout << water(h, n) << "\n";
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