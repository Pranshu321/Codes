#include<bits/stdc++.h>
 
 using namespace std;
 
 #define int long long

 class DS{
    deque<int>dq;
    public:
    DS(){
        dq.clear();
    }
    void insertMax(int x){
        dq.push_back(x);
    }
    void insertMin(int x){
        dq.push_front(x);
    }
    void deleteMax(){
        dq.pop_back();
    }
    void deleteMin(){
        dq.pop_front();
    }
    int getMax(){
        return dq.back();
    }
    int getMin(){
        return dq.front();
    }
    int size(){
        return dq.size();
    }
 };
 
 int32_t main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 
 DS s;
 s.insertMax(10);
 s.insertMin(5);
 s.insertMax(20);
 s.insertMin(0);
 s.deleteMin();
 cout<<s.getMax()<<" "<<s.getMin()<<" "<<s.size();

 
 
 
return 0 ;
 
 
 } 