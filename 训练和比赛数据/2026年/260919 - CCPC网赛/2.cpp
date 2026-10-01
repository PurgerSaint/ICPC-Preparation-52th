#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n;
    string s;
    cin >> s >> n;
    if (s == "first") {
        vector<int> p(n);
        for (int& t: p) cin >> t;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = p[j];
        for (int i = 1; i < n; i++)
            swap(a[i][i], a[i][i - 1]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << a[i][j] << (j < n - 1 ? " " : "");
            if (i < n - 1) cout << "\n";
        }
    } else {
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            map<int, int> mp;
            for (int j = 0; j < n; j++)
                mp[a[j][i]]++;
            vector<pair<int, int>> b;
            for (auto& [c, m]: mp)
                b.push_back({c, m});
            sort(range(b), [](pair<int, int>& x, pair<int, int>& y){
                return x.second > y.second;
            });
            p[i] = b[0].first;
        }
        for (int i = 0; i < n; i++)
            cout << p[i] << (i < n - 1 ? " " : "");
    }
    return 0;
}