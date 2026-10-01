#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        int t; cin >> t;
        sum += t;
    }
    cout << sum;
    return 0;
}