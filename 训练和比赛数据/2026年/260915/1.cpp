#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

string solve() {
    int n; cin >> n;
    deque<int> q;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        q.push_back(t);
    }
    string ans = "";
    for (int i = 1; i <= n; i++) {
        if (q.size() == 1) {
            ans += 'L';
            q.pop_back();
            break;
        }
        if (i % 2) {
            if (ans.empty() || q.back() > q.front()) {
                ans += 'R';
                q.pop_back();
            } else {
                ans += 'L';
                q.pop_front();
            }
        } else {
            if (q.back() < q.front()) {
                ans += 'R';
                q.pop_back();
            } else {
                ans += 'L';
                q.pop_front();
            }
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