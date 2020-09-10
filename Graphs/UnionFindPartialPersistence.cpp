#include <bits/stdc++.h>

using namespace std;

int anc[100010];
int tim[100010];
int weight[100010];

/*
tim[i]: says when the current anc[i] was defined.
*/

int root(int x, int t){
    /*
    anc[i] only change once,
    so if tim[i] > t, anc[i] was i at t.
    */
    if(anc[x] == x || tim[x] > t) return x;

    return root(anc[x], t);
}

int join(int x, int y, int t){
    x = root(x, t);
    y = root(y, t);

    if(weight[y] > weight[x]) swap(x, y);

    anc[y] = x;
    tim[y] = t;
    weight[x] += weight[y];
}

int main(){
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        anc[i] = i;
        weight[i] = 1;
        tim[i] = 0;
    }

    return 0;
}