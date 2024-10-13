#include <stdio.h>
#include <limits.h>
#define vertices 5

int minimum_key(int k[], int mst[])
{
   int minimum = INT_MAX, min, i;

   for (i = 0; i < vertices; i++)
      if (mst[i] == 0 && k[i] < minimum) // finding the minimum key weighted path and updating the parent;
         minimum = k[i], min = i;        // minimum storing the wt path;
                                         // min is storing the parent

   return min;
}

void prim(int g[vertices][vertices])
{
   int parent[vertices];
   int wt[vertices];
   int vis[vertices];
   int i, count, u, v;
   for (i = 0; i < vertices; i++)
      wt[i] = INT_MAX, vis[i] = 0;

   wt[0] = 0;
   parent[0] = -1;

   for (count = 0; count < vertices - 1; count++)
   {

      u = minimum_key(wt, vis);
      vis[u] = 1;

      for (v = 0; v < vertices; v++)

         if (g[u][v] && vis[v] == 0 && g[u][v] < wt[v])
            parent[v] = u, wt[v] = g[u][v];
   }

   for (i = 1; i < vertices; i++)
      printf("%d  %d    %d \n", parent[i], i, g[i][parent[i]]);
}

int main()
{
   int g[vertices][vertices] = {
       {3, 2, 1, 9, 0},
       {5, 1, 2, 10, 4},
       {0, 4, 1, 0, 9},
       {8, 10, 0, 2, 10},
       {1, 6, 8, 11, 0},
   };

   prim(g);
}