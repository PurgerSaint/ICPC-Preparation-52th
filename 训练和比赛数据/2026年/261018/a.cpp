#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, x; cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (t % 2) x--;
        else x++;
    }
    cout << x;
    return 0;
}