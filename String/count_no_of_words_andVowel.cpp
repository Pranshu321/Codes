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
    string s;
    getline(cin, s);
    int Vcount = 0, Ccount = 0, Scount = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            Vcount++;

        else if (s[i] == ' ')
            Scount++;

        else
            // Else increment the count of consonants
            Ccount++;
    }
    cout << "Vowel Count : " << Vcount;
    cout << "\nConsonant Count : " << Ccount;
    cout << "\nSpaces Count : " << Ccount;

    return 0;
}