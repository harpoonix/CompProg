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

pii two_sum(int *a, const int &target, const int &n){
    int l = 0, r = n-1;
    do {
        if (a[l] + a[r] == target){
            return mp(l, r);
        }
        else if (a[l] + a[r] > target){
            r--;
        }
        else {
            l++;
        }
    } while (l < r);
    return mp(-1, -1);
}

void fail(){
    cout << "IMPOSSIBLE\n";
}

void solve() {
    int n, x; cin >> n >> x;
    if (n<=3) {fail(); return;}
    int t[n];
    for (int i=0; i<n; i++) {
        cin >> t[i];
    }
    int a[n*n - n], ind = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i==j) continue;
            a[ind] = a[i] + a[j];
            ind++;
        }
    }
    sort(a, a + n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (j==i) continue;
            pii possible = two_sum(a, x - a[i] - a[j], i, j, n);
            if (possible!= pii(-1, -1)){
                int p = find(b, b + n, a[possible.F]) - b; b[p] = -1;
                int q = find(b, b + n, a[possible.S]) - b; b[q] = -1;
                int r = find(b, b + n, a[i]) - b; b[r] = -1;
                int s = find(b, b + n, a[j]) - b; b[s] = -1;
                // cout << p+1 << " " << q+1 << " " << r+1 << " " << s+1 << "\n";
                printf("%d %d %d %d\n", p+1, q+1, r+1, s+1);
                return;
            }
        }
    }
    fail();
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