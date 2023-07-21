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

struct Node {
    int i = -1; int j = -1; char c = NULL;
};

void solve() {
    string s, t; getline(cin, s); getline(cin, t);
    int lcs[s.size()][t.size()];
    Node helper[s.size()][t.size()];
    lcs[0][0] = (s[0] == t[0]);
    helper[0][0].c = (s[0] == t[0] ? s[0] : NULL);
    for (int i=1; i<t.size(); i++) {
        if((lcs[0][i-1] == 1) || (t[i] == s[0])){
            lcs[0][i] = 1;
            helper[0][i].c = s[0];
        }
        else {
            lcs[0][i] = 0;
        }
    }
    for (int i=1; i<s.size(); i++) {
        if((lcs[i-1][0] == 1) || (s[i] == t[0])){
            lcs[i][0] = 1;
            helper[i][0].c = t[0];
        }
        else {
            lcs[i][0] = 0;
        }
    }
    for (int i=1; i<s.size(); i++) {
        for (int j=1; j<t.size(); j++) {
            lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            if (lcs[i-1][j] > lcs[i][j-1]){
                helper[i][j].i = i-1; helper[i][j].j = j;
            }
            else {
                helper[i][j].i = i; helper[i][j].j = j-1; 
            }
            helper[i][j].c = NULL;
            if (s[i] == t[j]){
                lcs[i][j] = max(lcs[i][j], 1 + lcs[i-1][j-1]);
                if (lcs[i][j] <= 1 + lcs[i-1][j-1]){
                    helper[i][j].i = i-1; helper[i][j].j = j-1; 
                    helper[i][j].c = s[i];
                }
            }
        }
    }
    int a = s.size()-1, b = t.size() - 1, tmp;
    string ans;
    while (a!=-1 && b!=-1){
        // cout << a << " " << b << "\n";
        if (helper[a][b].c != NULL){
            ans.push_back(helper[a][b].c);
        }
        tmp = helper[a][b].i;
        b = helper[a][b].j;
        a = tmp;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
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