#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    vector<string> a(2);
    cin >> a[0] >> a[1];
    if (abs(a[0][0] - a[0][1]) == 3 || abs(a[0][0] - a[1][0]) == 3 || abs(a[0][1] - a[1][1]) == 3 || abs(a[1][0] - a[1][1]) == 3)
        cout << "Yes";
    else cout << "No";
    return 0;
}