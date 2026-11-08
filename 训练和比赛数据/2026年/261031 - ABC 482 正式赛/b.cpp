#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    vector<string> s(5);
    for (string& t: s) cin >> t;
    int ans = 100;
    int cnt = 0;
    for (int i = 0; i < 5; i++) cnt += s[i][i] != 'o';
    ans = min(ans, cnt);
    cnt = 0;
    for (int i = 0; i < 5; i++) cnt += s[i][4 - i] != 'o';
    ans = min(ans, cnt);
    cnt = 0;
    for (int i = 0; i < 5; i++) {
        cnt = 0;
        for (int j = 0; j < 5; j++)
            cnt += s[i][j] != 'o';
        ans = min(ans, cnt);
    }
    for (int j = 0; j < 5; j++) {
        cnt = 0;
        for (int i = 0; i < 5; i++)
            cnt += s[i][j] != 'o';
        ans = min(ans, cnt);
    }
    cout << ans;
    return 0;
}