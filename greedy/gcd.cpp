#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> neighbouringElements(vector<vector<int>> &nums)
{
    // Write your code here.
    int n=nums.size();
    int m=nums[0].size();
    vector<vector<int>>mat(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0){
                if(j==0)
                    mat[i][j]=nums[i+1][j]+nums[i][j+1];
                else if(j==m-1)
                    mat[i][j]=nums[i][j-1]+nums[i+1][j];
       else
                    mat[i][j]=nums[j-1][i]+nums[i][j+1]+nums[i+1][j];
            }
           else if(i==n-1){
               if(j==0)
                   mat[i][j]=nums[i-1][j]+nums[i][j+1];
               else if(j==m-1)
                   mat[i][j]=nums[i-1][j]+nums[i][j-1];
               else
                   mat[i][j]=nums[i][j-1]+nums[i][j+1]+nums[i-1][j];
           }
            else{
                if(j==0)
                    mat[i][j]=nums[i-1][j]+nums[i+1][j]+nums[i][j+1];
                else if(j==m-1)
                    mat[i][j]=nums[i-1][j]+nums[i+1][j]+nums[i][j-1];
                else
                     mat[i][j]=nums[i-1][j]+nums[i+1][j]+nums[i][j-1]+nums[i][j+1];
            }
        }
    }
    return mat;
}
int main(){

}