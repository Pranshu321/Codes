#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{
    unordered_map<int, int> parent;
    unordered_map<int,int>size;
 
public:
    void makeSet(vector<int>&universe)
    {
        for (auto i: universe) {
            parent[i] = i;
        }
    }
    int Find(int k)
    { 
        if (parent[k] == k) {
            return k;
        }
        return Find(parent[k]);
    }
    void Union(int a, int b) // in this tep this is unotmized if x have greater size we have to make more chnages to accomate the b tree; 
    {
        int x = Find(a);
        int y = Find(b);
 
        parent[x] = y;
    }
};
 
void printSets(vector<int> const &universe, DisjointSet &ds)
{
    for (int i: universe) {
        cout << ds.Find(i) << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> universe = { 1, 2, 3, 4, 5 };
 
    // initialize `DisjointSet` class
    DisjointSet ds;
 
    // create a singleton set for each element of the universe
    ds.makeSet(universe);
    printSets(universe, ds);
 
    ds.Union(4, 3);        // 4 and 3 are in the same set
    printSets(universe, ds);
 
    ds.Union(2, 1);        // 1 and 2 are in the same set
    printSets(universe, ds);
 
    ds.Union(1, 3);        // 1, 2, 3, 4 are in the same set
    printSets(universe, ds);
 
    return 0;
}