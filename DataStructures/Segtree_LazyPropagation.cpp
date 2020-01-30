#include <bits/stdc++.h>

using namespace std;

int segtree[400040];
int lazy[400040];

void prop(int no, int i, int f){
    int l = 2 * no, r = 2 * no + 1;

    segtree[no] += lazy[no] * (f-i+1);

    if(i != f){
        lazy[l] += lazy[no];
        lazy[r] += lazy[no];            
    }

    lazy[no] = 0;
}

void update(int no, int i, int f, int a, int b, int valor){
    int l = 2 * no, r = 2 * no + 1, m = (i+f)/2;

    if(lazy[no] != 0) prop(no, i, f);

    if(i > f || i > b || f < a) return ;

    if(a <= i && f <= b){
        lazy[no] += valor;
        prop(no, i, f);
    }else{
        update(l, i, m, a, b, valor);
        update(r, m + 1, f, a, b, valor);

        segtree[no] = segtree[l] + segtree[r];
    }

    return ;
}

int query(int no, int i, int f, int a, int b){
    int l = 2 * no, r = 2 * no + 1, m = (i+f)/2;

    if(lazy[no] != 0) prop(no, i, f);

    if(i > f || i > b || f < a) return 0;

    if(a <= i && f <= b) return segtree[no];
    
    return query(l, i, m, a, b) + query(r, m + 1, f, a, b);
}