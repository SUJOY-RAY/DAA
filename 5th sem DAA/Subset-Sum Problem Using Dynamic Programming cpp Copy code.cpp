#include <iostream>
using namespace std;


bool subsetSum(int arr[], int n, int sum){
    bool dp[n+1][sum+1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0]=true;
    }
    
    for (int  j = 0; j <= sum; j++)
    {
        dp[0][j]=false;
    }
    
    for (int  i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            dp[i][j]=dp[i-1][j];
            if (j>=arr[i-1]){
                dp[i][j]=dp[i][j]||dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][sum];        
}

int main(){
    int arr[]={12,3,4,5,65,4,3,23,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<subsetSum(arr,n,7);


    return 0;
}