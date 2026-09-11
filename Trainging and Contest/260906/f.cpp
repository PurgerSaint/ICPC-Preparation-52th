#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<int> sum(n + 1, 0);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            int t; cin >> t;
            sum[i] += t;
        }
        if (sum[i] < sum[i - 1]) cnt++;
    }
    cout << cnt;
    return 0;
}