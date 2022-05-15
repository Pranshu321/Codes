#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
struct comp
{
    bool operator()(vector<int> a, vector<int> b)
    {
        if (a[1] == b[1]) // Checking that arrival time is same or not
        {
            if (a[2] == b[2]) // Checking burst time or we say time to complete is same or not.
            {
                return a[0] < b[0]; // Then we sort according to id number of arrival and burst time is same.
            }
            else
            {
                return a[2] < b[2]; // else on the basis of burst time.
            }
        }
        return a[1] < b[1]; // if diffrent arrival time then on the basis of arrival time.
    }
};
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> v(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    vector<int> ans;
    sort(v.begin(), v.end(), comp());

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({v[0][2], v[0][1], v[0][0]}); // enter the data in min heap in order {burst time , arrival time , id};
    int i = 1;                            // i=1 because one task is already in progress.
    int current_time = 0;                 // time noting variable.
    while (!pq.empty())
    {
        int burst_time = pq.top()[0];
        int id = pq.top()[2];

        pq.pop();
        ans.push_back(id);

        current_time = current_time + burst_time; // simply adding the burst time.

        while (true) // This is loop checking arrival time of processes less than the current time.
        {
            if (i < n and v[i][1] <= current_time) // same checking
            {
                pq.push({v[i][2], v[i][1], v[i][0]}); // if yes
                i++;
            }
            else // else break.
            {
                break;
            }
        }
    }

    // Simply print.
    cout << "The order of tasks that completed by CPU will be : ";
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}