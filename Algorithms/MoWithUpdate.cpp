#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pii pair<int, ll>

struct query{
    int l, r, t, id;

    query(int l_, int r_, int t_, int id_){
        l = l_;
        r = r_;
        t = t_;
        id = id_;
    }
};

struct update{
    int pos, prev, next;

    update(int pos_, int prev_, int next_){
        pos = pos_;
        prev = prev_;
        next = next_;
    }
};

const int MAXN = 50010;
const int MAXQ = 100010;
const int B = 1715; // B = (2(n^2))^(1/3)

vector <int> adj[MAXN];
vector <int> tree;
int n, q;
int v[MAXN];
int v2[MAXN];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> v[i];
    }

    cin >> q;

    vector <query> querys;
    vector <update> updates;
    for(int i=0; i<q; i++){
        char c;
        int x, y;
        cin >> c >> x >> y;


        if(c == 'Q'){
            querys.push_back(query(x, y, updates.size()-1, i));
        }else if(c == 'U'){
            updates.push_back(update(x, v2[x], y));

            v2[x] = y;
        }

    }

    sort(querys.begin(), querys.end(), [](query a, query b){
        int a_ = a.l/B;
        int b_ = b.l/B;

        if(a_ != b_) return a_ < b_;

        a_ = a.r/B;
        b_ = b.r/B;

        if(a_ != b_) return a_ < b_;

        return a.t < b.t;
    });

    ll sum = 0;

    auto add = [&](int x){
    };

    auto rem = [&](int x){
    };

    auto upd = [&](update u, int l, int r){
        if(l <= u.pos && u.pos <= r){
            rem(u.prev);

            add(u.next);
        }
        v[u.pos] = u.next;
    };

    auto undo = [&](update u, int l, int r){
        if(l <= u.pos && u.pos <= r){
            rem(u.next);

            add(u.prev);
        }
        v[u.pos] = u.prev;
    };

    vector <pii> ans;

    int l=1, r=0, t=-1;
    for(int i=0; i<querys.size(); i++){
        while(r < querys[i].r) add(v[++r]);
        while(r > querys[i].r) rem(v[r--]);
        while(l < querys[i].l) rem(v[l++]);
        while(l > querys[i].l) add(v[--l]);
        while(t < querys[i].t) upd(updates[++t], l, r);
        while(t > querys[i].t) undo(updates[t--], l, r);

        ans.push_back(mp(querys[i].id, sum));
    }

    sort(ans.begin(), ans.end());

    for(int i=0; i<ans.size(); i++){
        cout << ans[i].se << "\n";
    }
}