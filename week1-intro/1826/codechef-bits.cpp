#include <iostream>
using namespace std;

void solve(){
    int m; cin >> m;
    int ones = 0;
    for (int i = 1; i <= m; i++){
        int n = i;
        while (n > 0){
            ones+=(n & 1);
            n = (n >> 1);
        }
    }
    cout << ones << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
}
