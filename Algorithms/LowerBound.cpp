#include <bits/stdc++.h>

using namespace std;

int a[100100];

int lowerBound(int v){
    int l = 1, r = n;

    while(l < r){
        int m = (l + r)/2;

        if(a[m] < v){
            l = m + 1;
        }else{
            r = m; 
        }
    }

    return l;
}
