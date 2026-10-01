#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios;
    vector<bool> f(31, 1);
    for (int i = 2; i <= 30; i++) {
        if (f[i]) {
            for (int j = i * 2; j <= 30; j += i)
                f[j] = 0;
        }
    }
    f[2] = 0;
    int n; cin >> n;
    int cnt_a = 0, cnt_b = 0;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt_a += f[a[i]];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        cnt_a += f[b[i]];
    }
    if (cnt_b == n || cnt_a == n) {
        cout << "Bob";
        return 0;
    }
    int cnt = 0;
    for (int& i: b) {
        for (int& j: a) {
            if (gcd(i, j) > 1) {
                cnt++;
                break;
            }
        }
    }
    if (cnt == 0) cout << "Bob";
    else cout << "Alice";
    return 0;
}