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

bool possible(const int &t, int* a, int n, int m){
    int time[n] = {0};
    int notdone = 0;
    for (int i=0; i<m; i++) {
        if (time[a[i] - 1] < t){
            time[a[i] - 1]++;
        }
        else{
            notdone++;
        }
    }
    int worker = 0;
    while(notdone > 0){
        while (time[worker] + 2 <= t){
            time[worker]+=2;
            notdone--;
            if (notdone == 0){
                return true;
            }
        }
        worker++;
        if (worker == n){
            return false;
        }
    }
    return true;
}

int mintime(int* a, int n, int m){
    int l = 1, r = m, mid;
    while (l < r){
        mid = (l + r)/2;
        if (possible(mid, a, n, m)){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    return l;
}

void solve() {
    int n, m; cin >> n >> m;
    int a[m];
    for (int i=0; i<m; i++) {
        cin >> a[i];
    }
    cout << mintime(a, n, m) << "\n";
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