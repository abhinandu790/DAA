#include<iostream>
using namespace std;
int Knapsack(int w,int weights[],int values[],int n){
int dp[n+1][w+1];
for(int i=0;i<=n;i++){
for(int e=0;e<=w;e++){
if(i==0||e==0)
dp[i][e]=0;
else if(weights[i-1]<=e)
dp[i][e]=max(dp[i-1][e],dp[i-1][e-weights[i-1]]+values[i-1]);
else
dp[i][e]=dp[i-1][e];
}
}
return dp[n][w];
}

int main(){
int n,w;
cout<<"Enter the number of items:";
cin>>n;
int values[n],weights[n];
cout<<"Enter the values of the items:";
for(int i=0;i<n;i++){
cin>>values[i];
}
cout<<"Enter the weights of the items:";
for(int i=0;i<n;i++){
cin>>weights[i];
}
cout<<"Enter the maximum capacity of Knapsack:"<<endl;
cin>>w;
cout<<"Maximum value that can be obtained:"<<Knapsack(w,weights,values,n)<<endl;
return 0;
}
