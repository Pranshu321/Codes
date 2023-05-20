#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int> stockspan(vector<int> prices)
{
  vector<int> ans;
  stack<pair<int, int>> s;
  for (int i = 0; i < prices.size(); i++)
  {
    int days = 1;
    while (!s.empty() and s.top().first <= prices[i])
    {
      days += s.top().second;
      s.pop();
    }
    s.push({prices[i], days});
    ans.push_back(days);
  }
  return ans;
}
int32_t main()
{
  // your code goes here
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  vector<int> a = {100, 80, 60, 70, 60, 75, 85};
  vector<int> res = stockspan(a); // in this we have to count the number of days
  // on which the price is less than current day;
  for (auto i : res)
    cout << i << " ";
  return 0;
}
