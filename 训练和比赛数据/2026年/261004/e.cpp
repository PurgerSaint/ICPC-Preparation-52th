#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, k; cin >> n >> k;

    if (k > (n + 1) / 2) {
        cout << "No";
        return 0;
    }

    vector<int> ans;
    vector<int> f(n + 1, 1);

    int t = n;
    for (int i = 0; i < k; i++) {
        ans.push_back(t);
        f[t] = 0, t -= 2;
    }
    for (int i = n; i >= 1; i--)
        if (f[i]) ans.push_back(i);

    cout << "Yes" << "\n";
    for (int i = 0; i < n; i++)
        cout << ans[i] << (i < n - 1 ? " " : "");
    return 0;
}