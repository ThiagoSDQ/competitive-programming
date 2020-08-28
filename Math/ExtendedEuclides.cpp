#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll ext_gcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }

    ll X, Y;

    ll g = ext_gcd(b, a%b, X, Y);

    x = Y;
    y = X - Y*(a/b);

    return g;
}