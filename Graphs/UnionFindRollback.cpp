#include <bits/stdc++.h>

using namespace std;

//Stacks to keep the changes made by the last join operation.
stack < pair < int, int > > lastAnc; 
stack < pair < int, int > > lastWeight; 

int anc[100010];
int weight[100010];

int root(int x){
    if(anc[x] == x) return x;

    return root(anc[x]);
}

void join(int x, int y){
    x = root(x);
    y = root(y);

    //Union by Size
    if(weight[y] > weight[x]) swap(x, y);

    lastAnc.push(make_pair(y, anc[y]));
    lastWeight.push(make_pair(x, weight[x]));

    anc[y] = x;
    weight[x] += weight[y];
}

void rollback(){    
    int x = lastAnc.top().first;
    anc[x] = lastAnc.top().second;
    lastAnc.pop();

    x = lastWeight.top().first;
    weight[x] = lastWeight.top().second;
    lastWeight.pop();
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