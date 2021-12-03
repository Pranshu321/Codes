#include <bits/stdc++.h>
using namespace std;
void printNGE(int arr[], int n)
{
	stack<int> s;
	int res[n];
	for (int i =n-1; i>=0;i--) {
		if (!s.empty()) {
			while (!s.empty() && s.top() >= arr[i]) {
				s.pop();
			}
		}
		res[i] = s.empty() ? -1 : s.top();
		s.push(arr[i]);
	}
	for (int i = 0; i < n; i++)
		cout <<res[i]<<" ";
}
int32_t main()
{
	int n; cin>>n;
	int arr[n];
for(int i=0;i<n;i++)
cin>>arr[i];
	// Function call
	printNGE(arr, n);
	return 0;
}