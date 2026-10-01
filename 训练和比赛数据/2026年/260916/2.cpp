#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = i;
    cout << (lower_bound(range(a), 2) - a.begin());
    return 0;
}