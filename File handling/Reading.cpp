#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    ifstream ifs;
    ofstream ofs;
    ofs.open("g.txt");
    ofs << "This is good to have this";

    ifs.open("g.txt");
    if (!ifs.is_open())
    {
        cout << "FIle cannot be opened.";
    }
    string str;
    ifs >> str;
    cout << str;
    if (ifs.eof())
    {
        cout << "End of file reached";
    }
    ifs.close();

    return 0;
}