#include <bits/stdc++.h>

using namespace std;

int segtree[400040];
int lazy[400040];

void update(int no, int i, int f, int a, int b, int valor){
    int l = 2 * no, r = 2 * no + 1;

    if(lazy[no] != 0){
        segtree[no] += lazy[no] * (f - i + 1);

        if(i != f){
            lazy[l] += lazy[no];
            lazy[r] += lazy[no];            
        }

        lazy[no] = 0;
    }

    if(i > f || i > b || f < a) return ;

    if(a <= i && f <= b){
        segtree[no] += valor * (f - i + 1);

        lazy[l] += valor;
        lazy[r] += valor;
    }else{
        update(l, i, (i+f)/2, a, b, valor);
        update(r, (i+f)/2 + 1, f, a, b, valor);

        segtree[no] = segtree[l] + segtree[r];
    }

    return ;
}

int soma(int no, int i, int f, int a, int b){
    int l = 2 * no, r = 2 * no + 1;

    if(lazy[no] != 0){
        segtree[no] += lazy[no] * (f - i + 1);

        if(i != f){
            lazy[l] += lazy[no];
            lazy[r] += lazy[no];            
        }

        lazy[no] = 0;
    }

    if(i > f || i > b || f < a) return 0;

    if(a <= i && f <= b) return segtree[no];
    
    return soma(l, i, (i+f)/2, a, b) + soma(r, (i+f)/2 + 1, f, a, b);
}

