#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define fi first
#define se second

const ll MOD = 1000000007;
ll n;

int main(){
    cin >> n;

    ll base = 2;
    ll result = 1;
    while(n>0){
        if(n & 1){
            result *= base;
            result %= MOD;
        }
        base *= base;
        base %= MOD;
        n = n>>1;
    }

    cout << (result+MOD)%MOD << "\n";
}