#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<int> a(n, m / n);
    m %= n;
    for (int i = 0; i < n; i++) {
        if (m > 0) {
            a[i]++;
            m--;
        }
        cout << a[i] << (i < n - 1 ? "\n" : "");
    }
    return 0;
}