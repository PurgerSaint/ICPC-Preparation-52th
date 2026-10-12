#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, k; cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(range(b));
    int l = 1, r = n;
    while (l <= n && a[l] == b[l]) l++;
    while (r >= 0 && a[r] == b[r]) r--;
    if (l > r || r - l + 1 <= k) cout << "Yes";
    else cout << "No";
    return 0;
}