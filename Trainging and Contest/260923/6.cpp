#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<int> a(m);
    for (int& t: a) cin >> t;
    sort(range(a));
    for (int i = 0; i < m; i++)
        cout << a[i] << (i < m - 1 ? " " : "");
    return 0;
}