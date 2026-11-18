#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

string solve() {
    int n; cin >> n;
    
    vector<int> a(n);
    for (int& t: a) cin >> t;
    auto check = [&](vector<int>& b) -> bool {
        pair<int, bool> c = {1, 1};
        int mx = 0;
        for (int i = 1; i < n; i++) {
            if (c.second == b[i] > b[i - 1]) c.first++;
            else c.first = 2, c.second = !c.second;
            mx = max(mx, c.first);
        }
        return mx < 5;
    };
    if (check(a)) return string(n, 'L');

    string s1 = "L", s2 = "R";
    vector<int> ans1, ans2;
    int l = 0, r = n - 1;

    auto p = [&](string& s, vector<int>& ans) -> void {
        bool f = 1;
        while (l <= r) {
            if (f) {
                if (ans.back() < a[l] && ans.back() < a[r]) {
                    ans.push_back(max(a[l], a[r]));
                    s += a[l] > a[r] ? 'L' : 'R';
                    a[l] > a[r] ? l++ : r--;
                } else if (ans.back() < a[l]) {
                    ans.push_back(a[l++]), s += 'L';
                } else {
                    ans.push_back(a[r--]), s += 'R';
                }
            } else {
                if (ans.back() > a[l] && ans.back() > a[r]) {
                    ans.push_back(min(a[l], a[r]));
                    s += a[l] < a[r] ? 'L' : 'R';
                    a[l] < a[r] ? l++ : r--;
                } else if (ans.back() > a[l]) {
                    ans.push_back(a[l++]), s += 'L';
                } else {
                    ans.push_back(a[r--]), s += 'R';
                }
            }
            f = !f;
        }
    };
    ans1.push_back(a[l++]);
    p(s1, ans1);
    // for (int i = 0; i < n; i++)
    //   cout << ans1[i] << (i < n - 1 ? " " : "\n");
    if (check(ans1)) return s1;

    l = 0, r = n - 1;
    ans2.push_back(a[r--]);
    p(s2, ans2);
    // for (int i = 0; i < n; i++)
    //    cout << ans2[i] << (i < n - 1 ? " " : "\n");
    return s2;
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