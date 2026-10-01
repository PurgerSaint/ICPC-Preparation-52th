#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    vector<int> st;
    st.push_back(0);
    int n; cin >> n;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    ll mx = a[0];
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > mx) {
            res = max(res, i - st.back());
            st.push_back(i);
            mx = a[i];
        }
    }
    cout << (st.size()) << " ";
    if ((int)st.size() < 2) cout << 0;
    else cout << res;
    return 0;
}