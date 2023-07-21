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

int matryoshka(int * a, int n){
    sort(a, a+n);
    map<int, int> counts;
    for (int i=0; i<n; i++) {
        if (!counts.count(a[i])){
            counts.insert(mp(a[i], 1));
        }
        else {
            counts[a[i]]++;
        }
    }
    int prev = -1, prevcount = 0;
    int sets = 0;
    for (auto doll : counts){
        if (prev != doll.first - 1){
            sets+=doll.second;
        }
        else {
            if (doll.second > prevcount){
                sets+=doll.second - prevcount;
            }
        }
        prev = doll.first; prevcount = doll.second;
    }
    return sets;
}

void solve() {
    int n; cin >> n; 
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << matryoshka(a, n) << "\n";
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