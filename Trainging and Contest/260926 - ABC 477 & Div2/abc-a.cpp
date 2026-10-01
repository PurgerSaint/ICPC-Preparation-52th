#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    vector<char> next(26, ' ');
    next['B' - 'A'] = 'Y';
    next['Y' - 'A'] = 'R';
    next['R' - 'A'] = 'B';
    char c; cin >> c;
    cout << next[c - 'A'];
    return 0;
}