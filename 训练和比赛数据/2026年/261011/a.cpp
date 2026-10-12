#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n; cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        if (i % 2) sum += t;
    }
    cout << sum;
    return 0;
}