#include <bits/stdc++.h>
#include <thread>
using namespace std;
#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

typedef unsigned long long ull;

ull an1 = 0, an2 = 0;

void evenSum(ull st, ull end)
{
    ull sum = 0;
    for (ull i = st; i <= end; i++)
    {
        if ((i & 1) == 0)
        {
            an1 += i;
        }
    }
    // return sum;
}
void oddSum(ull st, ull end)
{
    ull sum = 0;
    for (ull i = st; i <= end; i++)
    {
        if ((i & 1) == 1)
        {
            an2 += i;
        }
    }
    // return sum;
}

int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    auto startTime = std::chrono::high_resolution_clock::now();
    ull start = 0, end = 1900000000;

    // thread_local(evenSum, start, end);

    mingw_stdthread::thread t1(evenSum, start, end);
    mingw_stdthread::thread t2(oddSum, start, end);

    t1.join();
    t2.join();

    // ull an1 = evenSum(start, end);
    // ull an2 = oddSum(start, end);
    auto stopTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = stopTime - startTime;

    cout << "Even Sum is : " << an1;
    cout << "\nOdd Sum is : " << an2;

    cout << "\n\n TIme taken : " << diff.count();

    return 0;
}