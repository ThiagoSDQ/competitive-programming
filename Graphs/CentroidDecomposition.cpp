#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define fi first
#define se second

vector < int > lista[50010];
int subSize[50010];
bool used[50010];
int n, k;

void calcSubSize(int x, int p = -1){
    subSize[x] = 1;
    for(int y : lista[x]){
        if(y == p || used[y]) continue;
        calcSubSize(y, x);
        subSize[x] += subSize[y];
    }
}

int findCentroid(int x, int treeSize){
    for(int y : lista[x]){
        if(subSize[y] > subSize[x] || used[y]) continue;
        if(2*subSize[y] > treeSize) return findCentroid(y, treeSize);
    }

    return x;
}

ll centroidDecomp(int x){
    calcSubSize(x);
    
    int centroid = findCentroid(x, subSize[x]);
    
    ll ans = 0;

//PROCESS

    used[centroid] = true;

    for(int y : lista[centroid]){
        if(used[y]) continue;
        ans += centroidDecomp(y);
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;

    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;

        lista[a].push_back(b);
        lista[b].push_back(a);
    }

    cout << centroidDecomp(1) << "\n";

    return 0;
}