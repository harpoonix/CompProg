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

struct element{
    int accesses; 
    int number;
    bool operator<(element const & e){
        return (accesses > e.accesses);
    }
};

void solve() {
    int n, s1, s2; cin >> n >> s1 >> s2;
    element r[n];
    for (int i=0; i<n; i++) {
        cin >> r[i].accesses;
        r[i].number = i+1;
    }
    int a[n], b[n]; int i = 0, j = 0;
    sort(r, r + n);
    while(i + j < n){
        if (s1*(i+1) < s2*(j+1)){
            a[i] = r[i+j].number; i++;
        }
        else {
            b[j] = r[i+j].number; j++;
        }
    }
    cout << i;
    for (int k=0; k<i; k++) {
        cout<< " " << a[k] ;
    }
    cout << "\n" << j;
    for (int k=0; k<j; k++) {
        cout << " " << b[k];
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