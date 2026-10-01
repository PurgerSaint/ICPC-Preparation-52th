#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    multiset<ll> st;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        ll t; cin >> t;
        st.insert(t);
        if (i >= 3) {
            cout << *(prev(prev(prev(st.end())))) << (i < n ? "\n" : "");
        }
    }
    return 0;
}