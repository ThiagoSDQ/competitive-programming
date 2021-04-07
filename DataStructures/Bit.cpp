#include <bits/stdc++.h>

using namespace std;

int BIT[100010];
int n;

int sum(int x){
    int soma = 0;

    while(x > 0){
        soma += BIT[x];

        x -= x & -x;
    }

    return soma;
}

void upd(int x, int v){
    while(x <= n){
        BIT[x] += v;

        x += x & -x;
    }
}