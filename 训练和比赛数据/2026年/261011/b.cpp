#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n; cin >> n;
    string s; cin >> s;
    vector<pair<char, int>> b;
    int ans = 0, t = 0;
    for (char c: s) {
        if (c == 'S') {
            t = 0;
            continue;
        }
        t++;
        ans = max(ans, t);
    }
    cout << ans;
    return 0;
}