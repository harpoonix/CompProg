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
    int n; cin >> n;
    char s[n+1];
    cin.ignore();
    cin.getline(s, n+1);
    int sub4[n], sub04[n], sub404[n];
    sub4[n-1] = (s[n-1] != '0' ? 1 : 0);
    for (int i=n-2; i>=0; i--) {
        sub4[i] = sub4[i + 1];
        if (s[i]=='*'){
            sub4[i]+=sub4[i+1];
        }
        sub4[i]+= (s[i] != '0');
        sub4[i]%=1000000007;
    }
    sub04[n-1] = 0;
    for (int i=n-2; i>=0; i--) {
        sub04[i] = sub04[i + 1];
        if (s[i]=='*'){
            sub04[i]+=sub04[i+1];
        }
        sub04[i]+= (s[i] != '4' ? sub4[i+1] : 0);
        sub04[i]%=1000000007;
        cout << "sub04 " << i << " " << sub04[i] << "\n";
    }
    sub404[n-1] = 0; sub404[n-2] = 0;
    for (int i=n-3; i>=0; i--) {
        sub404[i] = sub404[i + 1];
        if (s[i]=='*'){
            sub404[i]+=sub404[i+1];
        }
        sub404[i]+= (s[i] != '0' ? sub04[i+1] : 0);
        sub404[i]%=1000000007;
    }

    cout << sub404[0] << "\n";

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