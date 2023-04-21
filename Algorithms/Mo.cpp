#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define fi first
#define se second
#define mp make_pair
#define pii pair<int, ll>

struct query{
    int l, r, id;

    query(int l_, int r_, int id_){
        l = l_;
        r = r_;
        id = id_;
    }
};

const int MAXN = 200010;
const int B = 450;

int n, q;
ll v[MAXN];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> n >> q;

    for(int i=1; i<=n; i++){
        cin >> v[i];
    }

    vector <query> querys;
    for(int i=0; i<q; i++){
        int a, b; cin >> a >> b;
        querys.push_back(query(a, b, i));
    }

    sort(querys.begin(), querys.end(), [](query a, query b){
        int a_ = a.l/B;
        int b_ = b.l/B;
        if(a_ != b_) return a_ < b_;

        return a.r < b.r;
    });

    int total = 0;

    auto add = [&](int x){
    };

    auto rem = [&](int x){
    };

    vector <pii> ans;

    int l=0, r=0;
    for(int i=0; i<q; i++){
        while(r < querys[i].r) add(v[++r]);
        while(r > querys[i].r) rem(v[r--]);
        while(l < querys[i].l) rem(v[l++]);
        while(l > querys[i].l) add(v[--l]);

        ans.push_back(mp(querys[i].id, total));
    }

    sort(ans.begin(), ans.end());

    for(int i=0; i<ans.size(); i++){
        cout << ans[i].se << "\n";
    }
}