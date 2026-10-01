#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

mt19937_64 rng(time(0)); 
ll rnd(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}

vector<int> solve(int n) {
    ll s = 1LL * n * (n + 1) / 2, r = sqrt(s);
    ll s_back = r * r;
    if (s_back == s) {
        cout << -1;
        return {};
    }
    vector<int> buk;
    for (int i = n; i >= 1; i--) buk.push_back(i);
    vector<int> ans;
    while (!buk.empty()) {
        if (buk.size() == 1) {
            ans.push_back(buk.back());
            break;
        }
        int t = buk.back();
        buk.pop_back();
        if (s - t != s_back) {
            ans.push_back(t);
        } else {
            int t2 = buk.back();
            buk.pop_back();
            ans.push_back(t2);
            buk.push_back(t);
        }
        s -= ans.back();
        r = sqrt(s);
        s_back = r * r;
    }
    // reverse(range(buk));
    return buk;
}

int main() {
    ios;
    int t = rnd(1, 100);
    int cnt = 0;
    while (1) {
        cnt++;
        int n = rnd(1, 100);
        vector<int> ans = solve(n);
        bool f = 0;
        ll s = 0;
        for (int& a: ans) {
            s += a;
            ll r = sqrt(s);
            if (r * r == s) {
                f = 1;
                break;
            }
        }
        if (!ans.empty() && f) {
            cout << "Test " << cnt << " Wrong! n is " << n << "\n";
            cout << "seq: ";
            for (int& a: ans) cout << a << " ";
            break;
        } else cout << "Test " << cnt << " is OK!";
        cout << "\n";
    }
    return 0;
}