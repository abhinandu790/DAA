#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge{
	int S,D,W;
};
bool compare(Edge a,Edge b){
	return a.W<b.W;
}
int findSet(int v,vector<int>&parent){
	if(v!=parent[v]){
		parent[v]=findSet(parent[v],parent);
	}
	return parent[v];
}
void unionSet(int a,int b,vector<int>&parent,vector<int>&rank){
	a=findSet(a,parent);
	b=findSet(b,parent);
	if(a!=b){
		if(rank[a]<rank[b]){
		swap(a,b);
		}
		parent[b]=a;
		if(rank[a]==rank[b]){
			rank[a]++;
		}
	}
}
void Kruskal(int vertices,vector<Edge>& edges){
	sort(edges.begin(),edges.end(),compare);
		vector<int>parent(vertices);
		vector<int>rank(vertices,0);
			for(int i=0;i<vertices;i++){
				parent[i]=i;
			}
int Weight=0;
	for(Edge e: edges){
if (findSet(e.S,parent)!=findSet(e.D,parent)){
	cout<<e.S<<"-"<<e.D<<":"<<endl;
	Weight+=e.W;
		unionSet(e.S,e.D,parent,rank);
	}
}
cout<<"Total weight:"<<Weight<<endl;
}
int main(){
int vertices,edges;
cin>>vertices>>edges;
vector<Edge>edgeList(edges);

for(int i=0;i<edges;++i){
cin>>edgeList[i].S>>edgeList[i].D>>edgeList[i].W;
}
Kruskal(vertices,edgeList);
return 0;
}
	
