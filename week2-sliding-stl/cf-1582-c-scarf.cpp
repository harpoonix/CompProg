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

int make_palindrome(string& s, int n, bool left){
    int l = 0, r = n-1; int count = 0;
    char remove = NULL;
    while (l <= r){
        if (s[l] == s[r]){
            l++; r--; continue;
        }
        if (remove == NULL){
            remove = s[(left ? l : r)];
            continue;
        }
        else if (remove!=s[l] && remove != s[r]){
            return INT32_MAX;
        }
        else if (remove == s[l]){
            l++;
        }
        else if (remove == s[r]){
            r--;
        }
        count++;
    }
    return count;
}

void solve() {
    int n; cin >> n; cin.ignore();
    string s; getline(cin , s);
    int ans = min(make_palindrome(s, n, 1), make_palindrome(s, n, 0));
    cout << (ans != INT32_MAX ? ans : -1) << "\n";
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