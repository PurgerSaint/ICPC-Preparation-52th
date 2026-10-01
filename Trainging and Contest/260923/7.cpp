#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n; cin >> n;
    vector<int> a(n);
    for (int& t: a) cin >> t;
    sort(range(a));
    a.erase(unique(range(a)), a.end());
    cout << a.size() << "\n";
    for (auto it = a.begin(); it != a.end(); it++)
        cout << *it << (it + 1 != a.end() ? " " : "");
    return 0;
}