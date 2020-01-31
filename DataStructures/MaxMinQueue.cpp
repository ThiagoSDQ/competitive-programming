#include <bits/stdc++.h>

using namespace std;

struct minqueue{
    stack < pair < int, int > > s1, s2;

    void push(int x){
        if(s1.size() == 0){
            s1.push(make_pair(x, x));
        }else{
            s1.push(make_pair(x, min(x, s1.top().second)));
        }
    }

    void pop(){
        if(s2.size() == 0) swap();
        
        s2.pop(); 
    }

    void swap(){
        s2.push(make_pair(s1.top().first, s1.top().first));
        s1.pop();

        while(s1.size() > 0){
            s2.push(make_pair(s1.top().first, min(s1.top().first, s2.top().second)));
            s1.pop();
        }
    }

    int size(){
        return s1.size() + s2.size();
    }

    int front(){
        return s2.top().first;
    }

    int mini(){
        return min((s2.size() > 0 ? s2.top().second : 0x7fffffff), (s1.size() > 0 ? s1.top().second : 0x7fffffff));
    }
};

struct maxqueue{
    stack < pair < int, int > > s1, s2;

    void push(int x){
        if(s1.size() == 0){
            s1.push(make_pair(x, x));
        }else{
            s1.push(make_pair(x, max(x, s1.top().second)));
        }
    }

    void pop(){
        if(s2.size() == 0) swap();
        
        s2.pop(); 
    }

    void swap(){
        s2.push(make_pair(s1.top().first, s1.top().first));
        s1.pop();

        while(s1.size() > 0){
            s2.push(make_pair(s1.top().first, max(s1.top().first, s2.top().second)));
            s1.pop();
        }
    }

    int size(){
        return s1.size() + s2.size();
    }

    int front(){
        return s2.top().first;
    }

    int maxi(){
        return max((s2.size() > 0 ? s2.top().second : -0x7fffffff), (s1.size() > 0 ? s1.top().second : -0x7fffffff));
    }
};