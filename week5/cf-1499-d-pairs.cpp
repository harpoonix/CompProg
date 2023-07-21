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

#define SIZE int(2e7 + 1e-3) + 1

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;

// int numberOfPrimeFactors(int n){
//     if (n == 2 || n == 3){
//         return 1;
//     }
//     int count = 0;
//     for (int i=2; i<=sqrt(n) + 1e-5; i++) {
//         if (n%i == 0){
//             count++;
//             while(n%i==0){
//                 n/=i;
//             }
//         }
//     }
//     if (n > 2){
//         count++;
//     }
//     return count;
// }

void sieve(int* minDivisor, int* factorCount, int n){
    minDivisor[1] = 1;
    for (ll i=2; i<n; i++) {
        if (minDivisor[i] == 0){
            minDivisor[i] = i;
            for (ll j=i*i; j<n; j+=i) {
                if (minDivisor[j] == 0){
                    minDivisor[j] = i;
                }
            }
        }
    }
    factorCount[1] = 0;
    for (int i=2; i<n; i++) {
        if (i == minDivisor[i]){
            factorCount[i] = 1;
        }
        else {
            factorCount[i] = factorCount[i/minDivisor[i]] + (minDivisor[i] != minDivisor[i/minDivisor[i]]);
        }
    }
    
}

ll fastexp(ll a, ll b){
    ll mult = a, ans = 1;
    while (b > 0){
        if (b&1){
            ans*=mult;
        }
        mult*=mult;
        b = (b >> 1);
    }
    return ans;
}

int pairs (int &c, int &d, int &x, int* numberOfPrimeFactors){
    ll count = 0, prod;
    for (int g=1; g<=sqrt(x) + 1e-8; g++) {
        if (x%g == 0){
            if ((x/g + d)%c == 0){
                prod = (x/g + d)/c;
                if (prod == 1){
                    count += 1;
                }
                else {
                    int n = numberOfPrimeFactors[prod];
                    count+=fastexp(2, n);
                }
            }
            if ((g + d)%c == 0 && g*g != x){
                prod = (g + d)/c;
                if (prod == 1){
                    count += 1;
                }
                else {
                    int n = numberOfPrimeFactors[prod];
                    count+=fastexp(2, n);
                }
            }
        }
    }
    return count;
}

void solve(int * numberOfPrimeFactors) {
    int c, d, x; cin >> c >> d >> x;
    cout << pairs(c, d, x, numberOfPrimeFactors) << "\n";
}

void precalc() {
    
}

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    // precalc()

    int* minPrimeDivisor = new int[SIZE]{0};
    int* numberOfPrimeFactors = new int[SIZE]{0};
    sieve(minPrimeDivisor, numberOfPrimeFactors, SIZE);
    int t; cin>>t;
    while(t--) {solve(numberOfPrimeFactors);}
    delete[] minPrimeDivisor;
    delete[] numberOfPrimeFactors;
    
}