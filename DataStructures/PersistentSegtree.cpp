#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;
const int LOGN = 17;
const int SEGSIZE = 4*MAXN + LOGN*MAXN;

int root[SEGSIZE];
int seg[SEGSIZE];
int l[SEGSIZE];
int r[SEGSIZE];
int v[MAXN];
int notUsed = 1;
int n;

int build(int a, int b){
    int no = notUsed;
    notUsed++;

    if(a == b){
        seg[no] = v[a];
    }else{
        int m = (a+b)/2;

        l[no] = build(a, m);
        r[no] = build(m+1, b);
    }

    return no;
}

int update(int no, int a, int b, int i, int x){
    int new_no = notUsed;
    notUsed++;

    if(a == b){
        seg[new_no] = x;//seg[no] + x;
    }else{
        int m = (a+b)/2;

        if(i <= m){
            l[new_no] = update(l[no], a, m, i, x);
            r[new_no] = r[no];
        }else{
            l[new_no] = l[no];
            r[new_no] = update(r[no], m+1, b, i, x);
        }

        seg[new_no] = seg[l[new_no]] + seg[r[new_no]];
    }

    return new_no;
}

int query(int no, int a, int b, int i, int f){
    if(b < i || f < a) return 0;

    if(a <= i && f <= b) return seg[no];

    int m = (a+b)/2;

    return query(l[no], a, m, i, f) + query(r[no], m+1, b, i, f);
}

int main(){
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> v[i];
    }

    root[0] = build(1, n);



    return 0;
}