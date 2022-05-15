#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
struct Job
{
    int id;
    int dead;
    int profit;

    //  Job(int ids,int deadline,int profits){
    //      id=ids;
    //      dead=deadline;
    //      profit=profits;

    //  }
};

static bool comp(Job a, Job b)
{
    return a.profit > b.profit;
}

vector<int> Job_Scheduling(Job a[], int n)
{
    sort(a, a + n, comp);
    vector<int> v;
    bool done[n] = {false}; // Done array for setting up the jobs

    int day = 0, profit = 0; // days means jobs been schedule and profit.
    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, a[i].dead - 1); j >= 0; j--) // minimum because dead beyond the number of boxes will not be taken.
        {
            if (done[j] == false) // if slot is empty or not
            {
                profit += a[i].profit;
                day++;
                done[j] = true; // marking the slot true;
                break;
            }
        }
    }
    v.push_back(day);
    v.push_back(profit);

    return v;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    Job a[n];
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[i].id = x;
        a[i].dead = y;
        a[i].profit = z;
    }

    vector<int> v = Job_Scheduling(a, n);
    cout << "The total jobs done and Profit : ";
    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}