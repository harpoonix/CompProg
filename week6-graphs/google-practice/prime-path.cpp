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

int SPF[int(1e6 + 1e-3) + 1] = {0};

bool canMove(const int &i1,const int &j1,const int &i2,const int &j2, const int &p){
    return (abs(i1-i2) + abs(j1-j2) <= p);
}

void solve() {
    int n; cin >> n;
    int** grid = new int*[n];
    for (int i=0; i<n; i++) {
        grid[i] = new int[n];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }
    
}

void sieve(int n){
    SPF[2] = 2; SPF[3] = 3;
    for (int i=2; i*i<=n; i++) {
        if (SPF[i] == 0 || i == 2 || i==3) {
            SPF[i] = i;
            for (int j=i*i; j<=n; j+=i) {
                if (SPF[j] == 0){
                    SPF[j] = i;
                }
            }
        }
    }
}

int numberOfPrimeFactors(int n){
    int count = 0, lowest;
    while (n > 1){
        count++;
        lowest = SPF[n];
        while (n%lowest == 0){
            n/=lowest;
        }
    }
    return count;
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