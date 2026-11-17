#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> cnt(26, 26);
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[(n - 1) - i]) {
            int l = min(s[i], s[(n - 1) - i]) - 'a', r = max(s[i], s[(n - 1) - i]) - 'a';
            cnt[r] = min(cnt[r], l);
        }
    vector<int> buk;
    for (int i = 0; i < 26; i++)
        if (cnt[i] != 26)
            buk.push_back(i);
    int ans = 0;
    for (int i = 25; i > 0;) {
        while (!buk.empty() && buk.back() >= i) buk.pop_back();
        if (cnt[i] == 26) {
            i--; continue;
        } else {
            int next = cnt[i];
            if (!buk.empty()) next = max(next, buk.back());
            ans += i - next; i = next; 
        }
    }
    return ans;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << solve();
        if (t) cout << "\n";
    }
    return 0;
}