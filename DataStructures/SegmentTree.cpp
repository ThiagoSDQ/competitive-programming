#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 100010;

int seg[4*MAXN];

void update(int no, int i, int f, int v, int p){
    int l = 2*no;
    int r = 2*no + 1;

    if(p < i || f < p) return;

    if(i == f){
        seg[no] += v;
    
        return ;
    }

    int m = (i + f)/2;

    update(l, i, m, v, p);
    update(r, m+1, f, v, p);

    seg[no] = seg[l] + seg[r];

    return ;
}

int query(int no, int i, int f, int a, int b){
    int l = 2*no;
    int r = 2*no + 1;

    if(b < i || f < a) return 0;

    if(a <= i && f <= b) return seg[no];

    int m = (i + f)/2;

    return query(l, i, m, a, b) + query(r, m+1, f, a, b);
}

int main(){
    int v[] = {2, 5, -3, 12, 0, 3, 7, 1};
    
    for(int i=0; i<8; i++){
        update(1, 1, 8, v[i], i+1);
    }

    cout << query(1, 1, 8, 2, 6) << "\n";
    
    return 0;
}