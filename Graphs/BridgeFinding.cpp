#include <bits/stdc++.h>

using namespace std;

#define mp make_pair

vector < int > lista[100010];
vector < pair < int, int > > bridge;
int disc[100010];
int low[100010];
int n, t;

void dfs(int x, int p){
    disc[x] = t;
    low[x] = t;
    t++;

    for(int i=0; i<lista[x].size(); i++){
        int y = lista[x][i];

        if(disc[y] == 0){
            dfs(y, x);

            low[x] = min(low[x], low[y]);
            if(low[y] > disc[x]) bridge.push_back(mp(min(x, y), max(x, y)));
        }else if(y != p){
            low[x] = min(low[x], disc[y]);
        }
    }
}