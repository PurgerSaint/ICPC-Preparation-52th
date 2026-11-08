#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n; cin >> n;
    vector<int> a(n + 1, 0), s(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    int cnt = 0;
    for (int i = 1; i + 1 <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] * a[j] == (s[j - 1] - s[i]))
                cnt++;
        }
    }
    cout << cnt;
    return 0;
}