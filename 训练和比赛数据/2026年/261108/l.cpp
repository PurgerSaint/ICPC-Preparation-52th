#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

struct state {
    string name;
    int problem;
    bool f;
    int time;
};

int main() {
    ios;
    int n, m, q; cin >> n >> m >> q;
    vector<state> a(q);
    for (auto& [name, problem, f, time]: a) {
        string s, w; char c; int t;
        cin >> s >> c >> w >> t;
        name = s;
        problem = c - 'A';
        f = w == "AC" ? 1 : 0;
        time = t;
    }
    sort(range(a), [](state& x, state& y){
        return x.time < y.time;
    });
    vector<bool> ans(n, 0), show(n, 0);
    vector<set<string>> submit(n), accept(n);
    for (auto& [name, problem, f, time]: a) {
        // if (time >= 240) continue;
        submit[problem].insert(name);
        if (f) accept[problem].insert(name);

        int e = submit[problem].size(), s = accept[problem].size();
        if (time >= 240 || (e > 0 && s >= 0.2 * e) || s >= 50) show[problem] = 1;
        else {
            if (show[problem]) {
                // cout << s << " " << e << "\n";
                ans[problem] = 1;
            }
            show[problem] = 0;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (ans[i]) {
            cnt++;
            cout << char('A' + i);
        }
    if (!cnt) cout << "-";
    return 0;
}