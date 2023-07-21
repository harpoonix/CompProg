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
    int n; cin >>n;
    int l = 0, r = n-1, mid;
    int whole, half;
    while (l < r){
        mid = (l+r)/2;
        cout << "? " << l + 1<< " " << r + 1<< endl;
        cin >> whole; whole--;
        if (r == l+1){
            l = (l+r-whole); break;
        }
        if (whole <= mid){
            cout << "? " << l+1 << " " << mid +1<< endl;
            cin >> half; half--;
            if (whole == half){
                // largest is in the first half
                r = mid;
            }
            else {
                // other half
                l = mid + 1;
            }
        }
        else {
            cout << "? " << mid+1 << " " << r +1<< endl;
            cin >> half; half--;
            if (whole == half){
                // largest is in the second half
                l = mid;
            }
            else {
                // other half
                r = mid - 1;
            }
        }
    }
    cout << "! " << l + 1<< endl;
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