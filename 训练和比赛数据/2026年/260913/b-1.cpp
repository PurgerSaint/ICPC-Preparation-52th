#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

vector<pair<string, int>> st;

string solve() {
    int n, p; cin >> n >> p;
    int ans = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s == "UnreasonableProblemArrangement") {
            ans += 10;
            continue;
        }
        char c = s.back();
        s.pop_back();
        if ('A' <= c && c <= 'L') {
            for (auto& [rs, r]: st) {
                if (s == rs) {
                    ans += r;
                    break;
                }
            }
        }
    }
    // cout << ans << " " << p << "\n";
    return ans > p ? "Joker" : "Judger";
}

int main() {
    ios;
    st.emplace_back("WrongProblem", 100);
    st.emplace_back("SameProblem", 30);
    st.emplace_back("UnreasonableLimitForProblem", 5);
    st.emplace_back("WeakTestsForProblem", 3);
    st.emplace_back("BadProblem", 1);

    int t; cin >> t;
    while (t--) {
        cout << solve();
        if (t) cout << "\n";
    }
    return 0;
}