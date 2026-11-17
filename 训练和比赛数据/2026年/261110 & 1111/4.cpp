#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

struct state {
    int idx;
    ll data;
    state* next;
    state* pre;
    state(): idx(0), data(0), next(NULL), pre(NULL) {}
};

void solve() {
    int n;
    
    cin >> n;
    
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    
    vector<pair<ll, int>> b;
    
    for (int i = 0; i < n; i++)
        b.push_back({i, a[i]});
    
        sort(range(b), [](pair<ll, int>& x, pair<ll, int>& y){
        return x.second < y.second;
    });
    
    ll s = 0;
    for (int i = 0; i < n - 2; i++)
        s += b[i].second;
    cout << s << "\n";
    
    state temp = state();
    state* head = &temp;
    state* p = head;

    vector<state*> star(n, NULL);

    // cout << "1\n";   // [赛后标记]这个是赛中我打出的断点，想查看程序在哪里停止

    for (int i = 0; i < n; i++) {
        star[i] = new state();
        p->next = star[i];
        star[i]->pre = p;
        p = p->next;
        p->data = a[i];
        p->idx = i + 1;
        // cout << star[i]->idx << " " << (i + 1) << "\n";
    }

    // for (int i = 0; i < n; i++)
    //    cout << star[i]->idx << " " << star[i]->data << "\n";

    // cout << "2\n";

    star[n - 1]->next = star[0];
    star[0]->pre = star[n - 1];

    int cnt = 0;
    for (auto& [i, _]: b) {
        if (!star[i] || !star[i]->pre || !star[i]->next) {
            cout << "WA";
            return;
        }
        cnt++;
        if (cnt > n - 2) break;
        state* pre = star[i]->pre;
        state* next = star[i]->next;
        cout << (pre->idx) << " " << (star[i]->idx) << " " << (next->idx);
        if (cnt < n - 2) cout << "\n";
        // star[i]->pre = star[i]->next = NULL;
        pre->next = next;
        next->pre = pre;
    }
}

int main() {
    ios;
    ll T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        ll a[n],m[n];
        ll mx=0,mxpos=0;
        for(ll i=0;i<n;i++){
            cin >> a[i] >> m[i];
            mx=max(mx,m[i]);
            if(mx==m[i])mxpos=a[i]%mx;
        }
        bool f=0;
        for(ll i=0;i<n;i++){
            if(gcd(mx,m[i])!=min(mx,m[i])){
                cout << "NO" << endl;
                f = 1; break;
            }
        }
        if(f==1)continue;
        for(ll i=0;i<n;i++){
            ll rem = a[i]%m[i];
            if(mxpos%m[i]!=rem){
                cout << "NO" << endl;
                f = 1; break;
            }
        }
        if(f==1)continue;
        cout << "YES" << endl;
    }
    return 0;
}

