
#include<iostream>
#include<conio.h>
using namespace std;
void dijkstra(int source,int dest);
int d[6],p[6],a[6][6]={0};
int i,j,n;
int main()
{   int source,dest;
    cout<<"enter the no of nodes\n";
    cin>>n;
    cout<<"enter the adj matrix\n";
    for(i=0;i<n;i++)
    { for(j=0;j<n;j++)
        cin>>a[i][j];
    }
    for(source=0;source<n;source++)
    {  for(dest=0;dest<n;dest++)
       {
       dijkstra(source,dest);
       if(d[dest]==99999)
         cout<<dest<<"not reachable from"<<source<<"\n";
       else
       {
           cout<<"shortest path";
           i=dest;
           while(i!=source)
           { cout<<i<<"<--";
             i=p[i];
           }
           cout<<i<<"="<<d[dest]<<"\n";
       }
       }
    }
    getch();
    return 0;
}
void dijkstra(int source,int dest)
{int i,u,v,s[6],min;
     for(i=0;i<n;i++)
     {
       d[i]=a[source][i];
       s[i]=0;
       p[i]=source;
     }
     s[source]=1;
     for(i=1;i<n;i++)
     {
         min=99999;
         u=-1;
         for(j=0;j<n;j++)
         {
           if(s[j]==0)
           {
             if(d[j]<min)
             {
               min=d[j];
               u=j;
             } 
           }     
         }
         if(u==-1)
           return;
         s[u]=1;
         if(u==dest)
           return;
         for(v=0;v<n;v++)
         {
           if(s[v]==0)
           {  if(d[u]+a[u][v]<d[v])
              { d[v]=d[u]+a[u][v];
                p[v]=u;
              }
           }
         }
     }
}   
