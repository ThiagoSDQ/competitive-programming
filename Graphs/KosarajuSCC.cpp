#include <bits/stdc++.h>

using namespace std;

vector < int > lista[100010], listaT[100010], comp[100010];
stack < int > st;
int vis[100010];
int n, m, contC = 0;

void dfs(int x){
    vis[x] = 1;

    for(int i=0; i<lista[x].size(); i++){
        int y = lista[x][i];

        if(vis[y] == 0) dfs(y);
    }

    st.push(x);
}

void dfsT(int x){
    comp[contC].push_back(x);

    vis[x] = 1;

    for(int i=0; i<listaT[x].size(); i++){
        int y = listaT[x][i];

        if(vis[y] == 0) dfsT(y);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        lista[a].push_back(b);
        listaT[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        if(vis[i] == 0) dfs(i);
    }

    memset(vis, 0, sizeof(vis));

    while(st.size() > 0){
        if(vis[st.top()] == 0){
            dfsT(st.top());
            contC++;
        }
        
        st.pop();
    }

    return 0;
}