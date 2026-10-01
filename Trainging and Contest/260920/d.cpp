#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n; char ch; cin >> n >> ch;
    ll cnt = 0;
    char x = ch;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        // cout << cnt << " : ";
        cnt *= 2;
        cnt += (c == x) * 2;
        // cout << cnt << "\n";
    }
    cout << cnt;
    return 0;
}