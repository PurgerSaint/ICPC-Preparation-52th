#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(range(a), [&](ll& x, ll& y){
        int cnt_x = x ? __builtin_popcountll(x) : 0, cnt_y = y ? __builtin_popcountll(y) : 0;
        if (cnt_x != cnt_y) return cnt_x < cnt_y;
        int dep_x = x ? __builtin_ctzll(x) : 0, dep_y = y ? __builtin_ctzll(y) : 0;
        if (dep_x != dep_y) return dep_x < dep_y;
        return x < y;
    });
    cout << a[k - 1];
    return 0;
}