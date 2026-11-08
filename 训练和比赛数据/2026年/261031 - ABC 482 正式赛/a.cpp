#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    string s; cin >> s;
    int cnt = 0;
    for (char c: s) cnt += c == 'o';
    cout << ((cnt % 2 == 0) ? "even" : "odd");
    return 0;
}