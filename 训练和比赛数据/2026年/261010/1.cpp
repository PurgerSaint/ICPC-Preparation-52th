#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

string add(string& a, string& b) {
    string ans = "";
    int f = 0;
    int n = a.length(), m = b.length();
    for (int i = 0; i < max(n, m); i++) {
        char c1 = '0', c2 = '0';
        if (i < n) c1 = a[i];
        if (i < m) c2 = b[i];

        int x = c1 - '0', y = c2 - '0', t = x + y + f;
        ans += '0' + (t % 10);
        f = t / 10; 
    }
    if (f) ans += '0' + f;
    return ans;
}

int main() {
    ios;
    int n; cin >> n;
    string a = "1", b = "2";
    if (n == 1) {
        cout << a;
        return 0;
    }
    for (int i = 3; i <= n; i++) {
        string c = add(a, b);
        a = b;
        b = c;
    }
    reverse(range(b));
    cout << b;
    return 0;
}