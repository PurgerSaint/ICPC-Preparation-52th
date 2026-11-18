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
    
    int l = 0, r = n - 1;
    string ans = "";
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (a[l] < a[r]) {
                ans += 'L', l++;
            } else {
                ans += 'R', r--;
            }
        } else {
            if (a[l] > a[r]) {
                ans += 'L', l++;
            } else {
                ans += 'R', r--;
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