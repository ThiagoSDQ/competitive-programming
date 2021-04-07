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

/*
    ax + by = c

    g = gcd(a, b)

    solution: if g|c

    find x' and y' for ax' + by' = g

    k = c/g
    x = x' * k
    y = y' * k

    other solutions:

    a(x +- (b/g)*z) + b(y -+ (a/g)*z) = c
*/

bool find_solution(ll a, ll b, ll c, ll &x, ll &y, ll &g){
    g = ext_gcd(abs(a), abs(b), x, y);

    if(c%g != 0) return false;

    ll k = c/g;

    x *= k;
    y *= k;

    if(a < 0) x = -x;
    if(b < 0) y = -y;

    return true;
}