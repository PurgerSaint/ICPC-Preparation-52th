#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, m; cin >> n >> m;
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        mp[s] = 0;
    }
    while (m--) {
        string s; cin >> s;
        if (!mp.count(s)) cout << "WRONG";
        else if (mp[s] > 0) cout << "REPEAT";
        else {
            cout << "OK";
            mp[s] = 1;
        }
        if (m) cout << "\n";
    }
    return 0;
}