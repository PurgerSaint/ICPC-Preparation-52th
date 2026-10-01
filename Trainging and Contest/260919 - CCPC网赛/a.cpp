#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    string s; cin >> s;
    cout << s;
    if (s.back() == 'e') cout << "r";
    else cout << "er";
    return 0;
}