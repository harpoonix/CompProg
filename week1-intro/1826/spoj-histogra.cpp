#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
//#include <cmath>
#include <stack>
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

ll pop_stack(stack<pair<ll, ll>> &bars, ll* h, int &n, int i, ll* max_till_now){
    ll area = 0;
    pair<ll, ll> top = bars.top();
    int last_popped_x;
    while (top.second > h[i]){
        area = max(area, top.second*(i - top.first));
        if (bars.size() > 1){
            last_popped_x = top.first;
            bars.pop();
            top = bars.top();
        }
        else {
            bars.top().second = h[i];
            break;
        }
    }
    *max_till_now = max(*max_till_now, area);
    return last_popped_x;
}

ll empty_stack(stack<pair<ll, ll>> &bars, ll* h, int &n){
    int x_right = bars.top().first + 1;
    pair<ll, ll> top;
    ll area = 0;
    while (!bars.empty()){
        top = bars.top();
        area = max(area, top.second*(x_right - top.first));
        bars.pop();
    }
    return area;
}

ll largest_area(ll* h, int &n){
    ll max_area = 0;
    stack<pair<ll, ll>> bars;
    bars.push(make_pair(0, h[0]));
    for (ll i=1; i<n; i++) {
        int last_popped_x;
        if (bars.top().second > h[i]){
            last_popped_x = pop_stack(bars, h, n, i, &max_area);
            bars.push(mp(last_popped_x, h[i])); 
        }
        bars.push(mp(i, h[i]));
    }
    max_area = max(max_area, empty_stack(bars, h, n));
    return max_area;
}

void solve(int &n) {
    ll h[n];
    for (int i=0; i<n; i++) {
        cin >> h[i];
    }
    cout << largest_area(h, n) << "\n";
}

void precalc() {
    
}

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    // precalc()
    
    int n; cin>>n;
    while(n){
        solve(n); cin >> n;
    }
    
}