#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
//#include <cmath>
// #include <stack>
#include <queue>
#include <deque>
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

void solve() {
    
}

void precalc() {
    
}

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> slider; int n = nums.size();
        slider.resize(n-k+1);
        if (n==1){return nums;}
        deque<int> window;
        for (int i=0; i<k; i++) {
            while (!window.empty() && nums[i] > nums[window.back()]){
                window.pop_back();
            }
            window.push_back(i);
        }
        for (int i=0; i<n-k; i++) {
            slider.push_back(nums[window.front()]);
            if (!window.empty() && window.front() <= i){
                window.pop_front();
            }
            while (!window.empty() && nums[i + k] >= nums[window.back()]){
                window.pop_back();
            }
            window.push_back(i + k);
        }
        slider.pb(nums[window.front()]);
        return slider;
    }
};

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    // precalc()
    
    int t; cin>>t;
    while(t--) solve();
    
    
}