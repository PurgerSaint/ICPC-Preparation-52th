#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(range(a));
    cout << a[k];
    return 0;
}