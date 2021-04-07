#include <bits/stdc++.h>

using namespace std;

vector < int > lista[10010];
vector < int > artPoint;
int disc[10010];
int low[10010];
int n, m;
int t = 1;

void dfs(int x, int p = -1){
    disc[x] = t;
    low[x] = t;
    t++;

    int children = 0;
    int flag = 0;
    for(int y : lista[x]){
        if(disc[y] == 0){
            children++;
            dfs(y, x);

            low[x] = min(low[x], low[y]);
            if(flag == 0 && p != -1 && low[y] >= disc[x]){
                artPoint.push_back(x);
                flag = 1;
            }
        }else if(x != p){
            low[x] = min(low[x], disc[y]);
        }
    }

    if(p == -1 && children > 1) artPoint.push_back(x);
}
