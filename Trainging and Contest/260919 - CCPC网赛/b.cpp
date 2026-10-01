#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int cnt = 0;
    bool f = 1;
    for (int i = 0; i < n; i++) {
        if (t[i] == '*') cnt++;
        else if (t[i] != s[i]) {
            cout << "No";
            return 0;
        }
    }
    if (!cnt && s != t) cout << "No";
    else cout << "Yes";
    return 0;
}