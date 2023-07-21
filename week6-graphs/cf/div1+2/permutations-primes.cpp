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

void sieve(vi & primes, int n){
    if (n == 2 || n==3){
        primes.push_back(n); return;
    }
    bool prime[n+1] = {0};
    for (int i=0; i<n+1; i++) {
        prime[i] = 1;
    }
    for (int i=2; i*i<=n; i++) {
        if (prime[i]){
            for (int j=i*i; j<=n; j+=i) {
                prime[j] = 0;
            }
        }
    }
    for (int i=2; i<=n; i++) {
        if (prime[i]){
            primes.push_back(i);
        }
    }
}

void solve() {
    int n; cin >> n;
    if (n == 1){
        cout << 1 << "\n"; return;
    }
    int a[n] = {0};
    bool done[n+1] = {0};
    vi primes; sieve(primes, n);
    int l = 0, r = n-1;
    for (int i=0; i<primes.size(); i++) {
        if (i%2==0){
            a[l] = primes[i]; l++; 
        }
        else {
            a[r] = primes[i]; r--;
        }
        done[primes[i]] = 1;
    }
    a[n/2] = 1; int ind = 1; done[1] = 1;
    for (int i=0; i<n; i++) {
        if (a[i]!=0){
            continue;
        }
        while (done[ind]){
            ind++;
        }
        a[i] = ind; done[ind] = 1;
    }
    for (int i=0; i<n; i++) {
        cout << a[i] << " ";
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
    
    int t; cin>>t;
    while(t--) solve();
    
    
}