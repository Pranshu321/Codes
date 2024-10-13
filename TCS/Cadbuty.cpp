#include <stdio.h>
#include <stdlib.h>
#define mini(a, b) a < b ? a : b
int fun(int x, int y)
{
    int ans = 0;
    while (x > 0 && y > 0)
    {
        int min = mini(x, y);
        if (x == y)
        {
            x -= min;
            y -= min;
        }
        else if (x < y)
        {
            y = y - min;
        }
        else
        {
            x = x - min;
        }
        ans++;
    }
    return ans;
}
int main()
{
    int p, q, r, s;
    scanf("%d%d%d%d", &p, &q, &r, &s);
    int ans = 0;
    for (int i = p; i <= q; i++)
    {
        for (int j = r; j <= s; j++)
        {
            ans += fun(i, j);
        }
    }
    printf("%d", ans);
    return 0;
}