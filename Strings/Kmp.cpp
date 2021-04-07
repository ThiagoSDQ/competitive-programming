#include <bits/stdc++.h>

using namespace std;

int P[100010];       

int main(){
    string w, t;
    cin >> w;
    cin >> t;

    string s = w + "#" + t;

    //Offline:
    for(int i=1; i<s.size(); i++){
        P[i] = P[i-1];
    
        while(P[i] > 0 && s[P[i]] != s[i]){
            P[i] = P[P[i] - 1];
        }

        if(s[P[i]] == s[i]) P[i]++;
    }

    for(int i=0; i<s.size(); i++){
        cout << P[i] << " ";
    }
    cout << "\n";

    //Online:
    //only stores P for w + "#"
    s = w + "#";
    for(int i=1; i<s.size(); i++){
        P[i] = P[i-1];
    
        while(P[i] > 0 && s[P[i]] != s[i]){
            P[i] = P[P[i] - 1];
        }

        if(s[P[i]] == s[i]) P[i]++;
    }

    int k = 0;//store P for current last position of t
    for(int i=0; i<t.size(); i++){
        while(k > 0 && s[k] != t[i]){
            k = P[k - 1];
        }

        if(s[k] == t[i]) k++;
        cout << k << " ";
    }
    cout << "\n";

    return 0;
}