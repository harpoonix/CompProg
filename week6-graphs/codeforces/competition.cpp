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

struct score{
    int points;
    int penalty;
    int index;
    bool operator<(const score &b){
        if (points > b.points){
            return true;
        }
        else if ( points == b.points){
            if (penalty < b.penalty){
                return true;
            }
            else if (penalty == b.penalty){
                return index < b.index;
            }
            else{
                return false;
            }
        }
        else {
            return false;
        }
    }
};

int place(vvi& t, int &n, int &m, int &h){
    for (int i=0; i<n; i++) {
        sort(t[i].begin(), t[i].end());
        for (int j=1; j<m; j++) {
            t[i][j] += t[i][j-1];
        }
    }
    // now times are cumulative
    score scores[n];
    for (int i=0; i<n; i++) {
        auto it = upper_bound(t[i].begin(), t[i].end(), h);
        scores[i].penalty = 0;
        for (auto ite=t[i].begin(); ite!=it; ite++) {
            scores[i].penalty += *ite;
        }
        it--;
        scores[i].points = (it - t[i].begin());
        scores[i].index = i + 1;
        // cout << scores[i].index << " penalty " << scores[i].penalty << "\n";
    }
    sort(scores, scores + n);
    for (int i=0; i<n; i++) {
        if (scores[i].index == 1){
            return i + 1;
        }
    }
    return INT32_MAX;

}

void solve() {
    int n, m, h; cin >> n >> m >> h;
    vvi t;
    t.resize(n, vi(m, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> t[i][j];
        }
    }
    cout << place(t, n, m, h) << "\n";

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