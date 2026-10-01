#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n; ll m; cin >> n >> m;
    string s; cin >> s;
    ll v = 0;   // 初始值 % m
    ll r = 0;   // 全1的权值之和 % m
    ll p = 1;   // 当前位的位权
    vector<ll> w(10, 0);

    for (int i = n - 1; i >= 0; i--) {
        int d = s[i] - '0';
        
        v = (v + d * p) % m;
        r = (r + p) % m;
        w[d] = (w[d] + p) % m;

        p = (p * 10) % m;
    }

    int ans = 0;
    for (int x = 0; x <= 9; x++) {
        ll cur = (v + x * r) % m;

        ll of = 0;
        for (int k = 10 - x; k <= 9; k++) {
            of = (of + w[k]) % m;
        }

        cur = (cur - of * 10) % m;
        cur = (cur % m + m) % m;
        if (cur == 0) ans++;
    }
    cout << ans;
    return 0;
}