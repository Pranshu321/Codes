#include <bits/stdc++.h>
using namespace std;
int tilingways(int n)
{ if(n==0)
    return 0;
    if(n==1)
    return 1;
    return (tilingways(n-2)+tilingways(n-1)); //n-1 shows the tile pacing in verticle direc and n-2 shows that tile pace in horizontal direcion,
    
}
int32_t main() {
	// tiling the tiles
	ios::sync_with_stdio(0);
	cout<<tilingways(4);
	return 0;
}
