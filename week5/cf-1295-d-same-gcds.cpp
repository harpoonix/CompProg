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

void prime_factors(vector<ll> &factors, ll m){
    if (m == 2 || m == 3){
        factors.push_back(m); return;
    }
    for (ll i=2; i*i<=m; i++) {
        if (m%i == 0){
            factors.push_back(i);
            while (m%i == 0){
                m/=i;
            }
        }
    }
    if (m > 2){
        factors.push_back(m);
    }
}

void solve() {
    ll a, m; cin >> a >> m;
    ll g = __gcd(a, m);
    a/=g; m/=g;
    vector<ll> primes;
    prime_factors(primes, m);
    ll denom = 1, num = 1;
    for (auto p : primes){
        denom*=p;
        num*=p-1;
    }
    cout << m/denom*num << "\n";

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