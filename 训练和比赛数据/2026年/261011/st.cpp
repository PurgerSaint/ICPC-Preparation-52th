#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    ll a = 1, b = 2;
    cout << "1: " << a << "\n";
    cout << "2: " << b << "\n";
    for (int i = 1; i <= 50; i++) {
        ll c = a + b;
        cout << i << ": " << c << "\n";
        a = b, b = c;
    }

    return 0;
}