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

int finddigit(string &s, int start, char dig, int m, int n){
    for (int i=start; i<n; i++) {
        if (s[i] == dig){
            return i;
        }
    }
    return INT32_MAX/2;
}

void print(char *pass, int m){
    for (int i=0; i<m+1; i++) {
        cout << pass[i];
    }
    cout << "\n";
}

void solve() {
    string _;
    getline(cin, _);
    int s[_.size()];
    for (int i=0; i<_.size(); i++) {
        s[i] = _[i] - '0';
    }
    int m; cin >> m;
    char a[m+1];
    char b[m+1];
    cin.ignore(); cin.getline(a, m+1);
    cin.getline(b, m+1);
    int l[m], r[m];
    for (int i=0; i<m; i++) {
        l[i] = a[i] - '0'; r[i] = b[i] - '0';
    }
    int start = 0;
    for (int i=0; i<m; i++) {
        int pos = -1;
        for (int j=a[i] - '0'; j<=b[i] - '0'; j++) {
            // cout << "finding " << j;
            pos = max(pos, finddigit(_, start, j + '0', m, _.size()));
            start = pos + 1;
        }
        if (pos == INT32_MAX/2){
            cout << "YES\n"; return;
        }
        // cout << "starting from " << start;
    }
    cout << "NO\n";
}

void precalc() {
    
}

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    // precalc()
    
    int t; cin>>t; cin.ignore();
    while(t--) solve();
    
    
}