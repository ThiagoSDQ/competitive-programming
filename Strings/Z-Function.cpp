#include <bits/stdc++.h>

using namespace std;

int Z[100010];

string t;
string w;
string s;

int main(){
    int l = 0, r =0;

    cin >> t >> w ;

    s = w + "#" + t;

    int j = 0;
    for(int i=1; i<s.size(); i++){
        if(r >= i){
            j = i - l;

            Z[i] = min(Z[j], r - i + 1);
        }else{
            while(i + Z[i] < s.size() && s[Z[i] + i] == s[Z[i]]){
                Z[i]++;

                if(i + Z[i] >= r){
                    l = i;
                    r = i + Z[i] - 1;
                }
            }
        }
    }

    for(int i=0; i<s.size(); i++){
        cout << Z[i] << (i + 1 == s.size() ? "\n" : " ");
    }

    return 0;
}