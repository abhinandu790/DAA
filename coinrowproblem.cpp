#include<iostream>
using namespace std;
int Coinrow(int coins[],int n){
if(n==0)
return 0;

int p2=0,p1=coins[0],current;
for(int i=1;i<n;i++){
current=max(p1,p2+coins[i]);
p2=p1;
p1=current;
}
return p1;
}

int main(){
int n;
cout<<"Enter the number of coins:";
cin>>n;
int*coins=new int[n];

cout<<"Enter the values of the coins:";
for(int i=0;i<n;i++){
cin>>coins[i];
}
 int result=Coinrow(coins,n);
cout<<"Maximum value that can be collected:"<<result<<endl;
delete[] coins;
return 0;
}

