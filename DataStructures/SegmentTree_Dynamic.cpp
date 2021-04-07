#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define fi first
#define se second

struct Node{
    ll s;
    Node *L, *R;

    Node(){
        s = 0LL;
        L = NULL;
        R = NULL;
    }

    void update(int l, int r, int y, ll v){
        if(l == r){
            s = v;
        }else{
            int m = (l+r)/2;

            if(y <= m){
                if(L == NULL) L = new Node;

                L->update(l, m, y, v);
            }else if(m < y){
                if(R == NULL) R = new Node;

                R->update(m+1, r, y, v);
            }

            s = (L == NULL ? 0:L->s) + (R == NULL ? 0:R->s);
        }
    }

    ll query(int l, int r, int a, int b){
        if(a <= l && r <= b) return s;

        ll ans = 0;

        if(l != r){
            int m = (l+r)/2;

            if(b <= m && L != NULL){
                ans += L->query(l, m, a, b);
            }else if(m < a && R != NULL){
                ans += R->query(m+1, r, a, b);
            }else{
                if(L!= NULL) ans += L->query(l, m, a, b);
                if(R!= NULL) ans += R->query(m+1, r, a, b);
            }
        }

        return ans;
    }
};

int main(){
    Node *seg = new Node;

    int v[] = {2, 5, -3, 12, 0, 3, 7, 1};
    
    for(int i=0; i<8; i++){
        seg->update(1, 8, i+1, v[i]);
    }

    cout << seg->query(1, 8, 2, 6) << "\n";
    
    return 0;
}