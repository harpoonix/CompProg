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
    int n, t; cin >> n >> t;
    int k; cin >>k;
    int left = 0, right = n-1, mid, sum, target = k;
    while (left < right){
        mid = (left + right)/2;
        cout << "? " << left + 1 << " " << mid + 1 << endl;
        cin >> sum;
        if (-sum + (mid - left + 1) >= target){
            right = mid;
        }
        else if (-sum + (mid - left + 1) < target){
            target -= -sum + (mid - left + 1);
            left = mid + 1;
        }
    }
    cout << "! " << left + 1 << endl;
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