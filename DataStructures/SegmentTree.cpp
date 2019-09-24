#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

pair < int, int> segmax[400040];

void update(int no, int i, int f, int v, int p){
    int l = 2*no;
    int r = 2*no + 1;

    if(p < i || f < p) return;

    if(i == f){
        segmax[no].first = max(segmax[no].first, v);
        segmax[no].second = p;
    
        return ;
    }

    int m = (i + f)/2;

    update(l, i, m, v, p);
    update(r, m+1, f, v, p);

    segmax[no] = max(segmax[l], segmax[r]);

    return ;
}

pair < int, int > queryMax(int no, int i, int f, int a, int b){
    int l = 2*no;
    int r = 2*no + 1;

    if(b < i || f < a) return make_pair(0, -1);

    if(a <= i && f <= b) return segmax[no];

    int m = (i + f)/2;

    return max(queryMax(l, i, m, a, b), queryMax(r, m+1, f, a, b));
}
