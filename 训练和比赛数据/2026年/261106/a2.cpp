#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

vector<ll> fact;

ll solve() {
    int n; cin >> n;
    vector<ll> cnt(25, 0);
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        cnt[t]++;
    }
    vector<ll> s(25, 0);
    s[0] = cnt[0] * fact[0];
    for (int i = 1; i <= 24; i++)
        s[i] = s[i - 1] + cnt[i] * fact[i];
    ll a = 0, b = 0;
    for (int i = 24; i >= 0; i--) {
        if (cnt[i] == 0) continue;
        a += (cnt[i] / 2) * fact[i];
        b += (cnt[i] / 2) * fact[i];
        if (cnt[i] % 2 == 1) {
            if (i > 0 && s[i - 1] > fact[i]) {
                ll nd = fact[i];
                for (int j = i - 1; j >= 0; j--) {
                    ll t = cnt[j] * fact[j];
                    if (nd >= t) {
                        cnt[j] = 0;
                        nd -= t;
                        for (int k = j; k < i; k++)
                            s[k] -= t;
                    } else if (nd / fact[j] <= cnt[j]) {
                        ll ct = nd / fact[j];
                        if (ct % 2 != cnt[j] % 2 && j > 0 && s[j - 1] >= fact[j] + (nd - ct * fact[j])) ct--;
                        cnt[j] -= ct;
                        ll g = ct * fact[j];
                        nd -= g;
                        for (int k = j; k < i; k++)
                            s[k] -= g;
                    }
                    if (nd == 0) break;
                }
                a += fact[i], b += fact[i];
            } else {
                if (a < b) {
                    a += fact[i];
                    b += i > 0 ? s[i - 1] : 0;
                } else {
                    a += i > 0 ? s[i - 1] : 0;
                    b += fact[i];
                }
                break;
            }
        }
    }
    return a * b;
}

int main() {
    ios;
    int t; cin >> t;
    fact.push_back(1);
    for (int i = 1; i <= 24; i++)
        fact.push_back(fact.back() * 2);
    while (t--) {
        cout << solve();
        if (t) cout << "\n";
    }
    return 0;
}