// Codeforces 1791 F
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

set<int>::iterator binary_search(set<int> & active, int l){
    auto it = active.begin();
    int start = 0, end = active.size() - 1;
    while (start < end){
        int mid = (start + end)/2;
        it = active.begin();
        advance(it, mid);
        if (*it >= l){
            end = mid;
        }
        else {
            start = mid + 1;
        }
    }
    it = active.begin(); advance(it, start);
    return (*it >= l ? it : active.end());
}

int sum_digit(int x, int times){
    int sum = 0;
    for (int i=0; i<times; i++) {
        while (x > 0){
            sum += x%10;
            x = x/10;
        }
        x = sum; sum = 0;
    }
    return x;
}

void solve() {
    int n, q; cin >> n>>q;
    int a[n];
    set<int> active;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i] >= 10){
            active.insert(i);
        }
    }
    int command, l, r;
    for (int i=0; i<q; i++) {
        cin >> command;
        if (command == 2){
            cin >> l;
            cout << a[l - 1] << "\n";
        }
        else {
            cin >> l >> r; l--; r--;
            while(!active.empty()){
                auto itr = active.lower_bound(l);
                if (*itr > r || itr == active.end()){
                    break;
                }
                a[*itr] = sum_digit(a[*itr], 1);
                l = *itr + 1;
                if (a[*itr] < 10){
                    active.erase(itr);
                }
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
    
    int t; cin>>t;
    while(t--) solve();
    
    
}