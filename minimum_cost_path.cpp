#include<iostream>
using namespace std;
int Mincost(int cost[][100],int m,int n){
int minpath[m+1][n+1];
minpath[0][0]=cost[0][0];
for(int i=1;i<=m;i++)
minpath[i][0]=minpath[i-1][0]+cost[i][0];
for(int j=1;j<=n;j++)
minpath[j][0]=minpath[j-1][0]+cost[j][0];
for(int i=1;i<=m;i++){
for(int j=1;j<=n;j++){
minpath[i][j]=cost[i][j]+min(min(minpath[i-1][j],minpath[i][j-1]),minpath[i-1][j-1]);
}
}
return minpath[m][n];
}
int main(){
int m,n;
cout<<"Enter the number of rows:";
cin>>m;
cout<<"Enter the number of columns:";
cin>>n;

int cost[100][100];
cout<<"Enter cost matrix:"<<endl;
for(int i=0;i<m;i++){
for( int j=0;j<n;j++){
cin>>cost[i][j];
}
}
cout<<"Minimum cost to reach minimum cost:"<<Mincost(cost,m-1,n-1)<<endl;
return 0;
}











