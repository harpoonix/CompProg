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

struct pump{
    ll petrol;
    ll distance;
    pump(){};
    pump(ll p, ll d) : petrol(p), distance(d) {};
};


void solve() {
    int n; cin >> n;
    pump pumps[n];
    for (int i=0; i<n; i++) {
        cin >> pumps[i].petrol >> pumps[i].distance;
    }
    int j = 0; ll fuel = 0;
    while (true){
        bool complete = true;
        for (int i=0; i<n; i++) {
            if (fuel + pumps[(j + i)%n].petrol >= pumps[(j+i)%n].distance){
                fuel+=pumps[(j + i)%n].petrol - pumps[(j+i)%n].distance;
            }
            else{
                // cannot make it through
                j = (j + i + 1)%n;
                fuel = 0;
                complete = false;
                break;
            }
        }
        if (complete){
            break;
        }
    }
    cout << j << "\n";
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