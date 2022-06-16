#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

vector<bool> freq(100, false);
void find_permutations(vector<int> v, vector<vector<int>> &ans, vector<int>&permu)
{
    if (permu.size() == v.size())
    {
        ans.push_back(permu);
        return;
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (!freq[i])
        {
            permu.push_back(v[i]);

            freq[i] = true;
            find_permutations(v, ans, permu);
            freq[i] = false;
            permu.pop_back();
        }
    }
}

int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {   int a; cin>>a;
        v.push_back(a);
    }

    vector<vector<int>> ans;
    vector<int> permu;
    find_permutations(v, ans, permu);
    cout<<"----------------------------------------------------\n";
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}