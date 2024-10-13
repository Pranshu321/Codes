#include <bits/stdc++.h>

using namespace std;

#define int long long

int fibonacci(int n)
{

   if (n == 0 || n == 1)
   {
      return n;
   }

   if (n == 2)
   {
      return 1;
   }

   int partialAns1 = fibonacci(n - 1);
   int partialAns2 = fibonacci(n - 2);

   return partialAns1 + partialAns2;
}

int32_t main()

{
   ios_base::sync_with_stdio(false);
   cout.tie(0);
   cin.tie(0);
   int n;
   cin >> n;
   cout << fibonacci(n);

   return 0;
}