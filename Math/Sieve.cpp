#include <bits/stdc++.h>

using namespace std;

bool isPrime[100010];
int n;

void sieve(int x){
    isPrime[0] = false;
    isPrime[1] = false;

    for(int i=2; i<=x; i++){
        if(isPrime[i]){
            for(long long int j=i*i; j<=x; j+=i){
                isPrime[j] = false;
            }
        }
    }
}

int main(){
    cin >> n;

    for(int i=0; i<=n/2; i++) isPrime[i] = true;

    sieve(n);

    return 0;
}

