#include<iostream>
using namespace std;


int knapsack(int W, int wt[],int val[],int n){
    int dp[n+1][W+1];
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if(i==0||w==0){
                dp[i][w]=0;
            }else if (wt[i-1]<=w)
            {
                dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);
            }else
            {
                dp[i][w]=dp[i-1][w];
            }            
        }
    }    
    return dp[n][W];

}



int main()
{
    int val[7]={1,2,3,452,3,46,7};
    int wt[7]={7,6,54,3,21,23,45};
    int n=7;
    cout<<knapsack(40,wt,val,n);
    return 0;
}
