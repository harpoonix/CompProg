#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
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

bool is_palindrome(int* arr, int n){
    for (int i=0; i<n; i++) {
        if (arr[i]!=arr[n-1-i]){
            return false;
        }
    }
    return true;
}

int getGCD(int a, int b)
{
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    if (a == 0) {
        return b;
    }
    return a;
}

int GcdOfArray(int* arr, int size)
{
    int gcd = 0;
    for (int i = 0; i < size; i++) {
        gcd = getGCD(gcd, arr[i]);
    }
    return gcd;
}

void solve() {
    int n; cin >>n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    if (is_palindrome(a, n)){
        cout << 0 << "\n"; return;
    }
    int diff[n/2];
    for (int i=0; i<n/2; i++) {
        diff[i] = abs(a[i] - a[n-1-i]);
    }
    if (n/2 == 1){
        cout << diff[0] << "\n"; return;
    }
    int hcf = GcdOfArray(diff, n/2);
    cout << hcf << "\n";

}

void precalc() {
    
}

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    // precalc()
    
    int t; cin>>t;
    while(t--) solve();
    
    
}