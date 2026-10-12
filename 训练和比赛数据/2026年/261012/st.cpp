#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    for (int i = 1; i <= 32; i++) {
        bitset<8> b = bitset<8>(i);
        cout << i << " " << b.to_string() << "\n";
    }
    return 0;
}