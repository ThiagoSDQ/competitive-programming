#include <bits/stdc++.h>

using namespace std;

int BLOCK_SIZE;

struct query_{
    int l, r, id;

    query_(int l_, int r_, int id_){
        l = l_;
        r = r_;
        id = id_;
    }
};

bool ord_query(query_ a, query_ b){
    if(a.l/BLOCK_SIZE != b.l/BLOCK_SIZE) return a.l/BLOCK_SIZE < b.l/BLOCK_SIZE;

    return a.r < b.r;
}

vector < query_ > query;

int main(){
    int n, q;
    cin >> n >> q;

    BLOCK_SIZE = sqrt(n);

    for(int i=0; i<q; i++){
        int l, r;
        cin >> l >> r;

        query.push_back(query_(l, r, i));
    }

    sort(query.begin(), query.end(), ord_query);

    return 0;
}