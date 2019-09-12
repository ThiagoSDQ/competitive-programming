#include <bits/stdc++.h>

using namespace std;

vector < int > lista[100010];
int anc[100010][32];
int nivel[100010];

int n, q;

void dfs(int x){
    for(int i=0; i<lista[x].size(); i++){
        int y = lista[x][i];

        if(nivel[y] == -1){
            anc[y][0] = x;

            nivel[y] = nivel[x] + 1;

            dfs(y);
        }
    }
}

int lca(int a, int b){
    if(nivel[a] < nivel[b]) swap(a, b);

    for(int i=29; i>=0; i--){
        if(nivel[a] - (1 << i) >= nivel[b]) a = anc[a][i];
    }
    
    if(a == b) return a;

    for(int i=29; i>=0; i--){
        if(anc[a][i] != -1 && anc[a][i] != anc[b][i]){
            a = anc[a][i];
            b = anc[b][i];
        }
    }

    return anc[a][0];   
}

int main(){
    cin >> n >> q;

    memset(nivel, -1, sizeof(nivel));
    memset(anc, -1, sizeof(anc));

    for(int i=1; i<n; i++){
        int a, b;

        cin >> a >> b;

        lista[a].push_back(b);
        lista[b].push_back(a);
    }

    anc[1][0] = 1;

    nivel[1] = 0;

    dfs(1);

    for(int i=1; i<30; i++){
        for(int j=1; j<=n; j++){
            if(anc[j][i-1] != -1){
                anc[j][i] = anc[anc[j][i-1]][i-1];
            }
        }
    }

    return 0;
}