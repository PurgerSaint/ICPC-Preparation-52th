#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int q; cin >> q;
    map<string, int> mp;
    int n = 1;
    while (q--) {
        string s; cin >> s;
        int ans = 0;
        if (mp.count(s)) 
            cout << mp[s] << (q ? "\n" : "");
        else {
            cout << n << (q ? "\n" : "");
            mp[s] = n++;
        }
    }
    return 0;
}