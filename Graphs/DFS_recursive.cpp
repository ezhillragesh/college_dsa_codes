#include<iostream>
#define MAX 20
using namespace std;
int adj[MAX][MAX];
int visited[MAX];
int n;
void dfs(int v);
int main()
{
	int i,j,origin,dest,v;
	cout<<"how many nodes in the graph?";
	cin>>n;
	int maxedges=n*(n-1);
    while(1)  //i=0,....5
	{
		cout<<"enter the origin & destination of the edge "<<i+1<<"\n";
		cout<<"enter (0,0) if u want to quit\n";
		cin>>origin>>dest;
		if(origin==0 && dest==0)
		  break;
		if(origin>n|| dest>n || origin<=0 ||dest<=0)
		{
			cout<<"invalid edge";
			
		}
		else
		{
			adj[origin][dest]=1;
			adj[dest][origin]=1;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<adj[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"enter the vertex where u want to start the traversal from";
	cin>>v;
	dfs(v);
}
void dfs(int v)
{
	int i;
	cout<<v;
	visited[v]=1;
	for(i=1;i<=n;i++)
	{
		if(adj[v][i]==1 && visited[i]!=1)
		   dfs(i);
	}
	
}