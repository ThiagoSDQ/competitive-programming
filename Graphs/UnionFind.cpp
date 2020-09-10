#include <bits/stdc++.h>

using namespace std;

int anc[100010];
int weight[100010];

int root(int x){
    if(anc[x] == x) return x;

    return anc[x] = root(anc[x]);
}

void join(int x, int y){
    x = root(x);
    y = root(y);

    if(weight[y] > weight[x]) swap(x, y);

    anc[y] = x;
    weight[x] += weight[y];
}

int main(){
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        anc[i] = i;
        weight[i] = 1;
    }

    return 0;
}