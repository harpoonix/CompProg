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

ll cost(int median, int * a, int ind, int k){
    ll dist = 0;
    for (int i=ind; i<ind+k; i++) {
        dist+=ll(abs(median - a[i]));
    }
    return dist;
}

void solve() {
    int n, k; cin >> n >> k;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    multiset<int> window;
    for (int i=0; i<k; i++) {
        window.emplace(a[i]);
    }
    auto med = window.begin();
    ll dist;
    advance(med, (k-1)/2);
    dist = cost(*med, a, 0, k);
    cout << dist << " ";
    for (int i=k; i<n; i++) {
        bool skip = false;
        if (a[i]==a[i-k]){
            cout << dist << " "; continue;
        }
        if (k == 1){
            cout << 0 << " "; continue;
        }
        dist-= abs(*med - a[i-k]);
        if (a[i-k] < *med){
            if (k%2==0){
                dist-=abs(*(med) - *(++med));
            }
        }
        else if (a[i-k] == *med){
            skip = true;
            auto it = med;
            if (k%2){
                med--;
                window.erase(it);
            }
            else {
                dist-=abs(*med - *(++med));
                window.erase(it);
            }
        }
        else {
            if (k%2){
                med--; 
            }
        }
        if (!skip) {window.erase(window.find(a[i-k]));}
        window.emplace(a[i]); 
        if (a[i] < *med){
            if (k%2 == 0){
                dist+=ll(abs(*med - *(--med)));
            }
        }
        else if (a[i] >= *med){
            if (k%2){
                med++; 
            }
        }
        dist+= ll(abs(*med - a[i]));
        cout << dist << " ";
    }
    cout << "\n";
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