#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n; cin >> n;
    cout << __builtin_ctz(n) << " " << __builtin_clz(n) << " " << __builtin_popcount(n) << "\n";
    return 0;
}