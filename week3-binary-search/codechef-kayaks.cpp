#include <iostream>
#include <vector>
#include <iomanip>
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

struct person{
    int weight; int strength;
};

bool possible(person* p, int n, int s){
    double speed = s/1e6;
    double arr[n];
    for (int i=0; i<n; i++) {
        arr[i] = p[i].strength - speed*p[i].weight;
    }
    sort(arr, arr + n);
    for (int i=0; i<n/2; i++) {
        if (arr[i] + arr[n-1-i] < 20*speed){
            return false;
        }
    }
    return true;
}

double maxspeed(person * p, int n){
    int l = 0, r = 2*1e6 + 1e-5, mid;
    while (l<r){
        mid = 1 + (l+r)/2;
        if (possible(p, n, mid)){
            l = mid;
        }
        else{
            r = mid-1;
        }
    }
    return double(l/1e6);
}

void solve() {
    int n; cin >> n;
    person peep[n];
    for (int i=0; i<n; i++) {
        cin >> peep[i].weight >> peep[i].strength;
    }
    cout << fixed << setprecision(6) << maxspeed(peep, n) << "\n";
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