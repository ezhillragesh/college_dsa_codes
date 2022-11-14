#include <bits/stdc++.h>
using namespace std;
//21BBS0100

class edge{
    public:
        int source;
        int dest;
        int weight;
};
bool compare(edge e1,edge e2){
    return e1.weight<e2.weight;//sort increase order
}


int findparent(int v,int *parent){
    if(parent[v]==v){
        return v;
    }
    return findparent(parent[v],parent);
}


void kruskals(edge input[],int n,int e){
    //Sorting the input array according to weight
    sort(input,input+e,compare);
    edge*output=new edge[n-1];
    
    int *parent=new int[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    int count=0,i=0;
    while(count!=n-1){
        edge curr=input[i];
        //check for cycle
        int sparent=findparent(curr.source,parent);
        int dparent=findparent(curr.dest,parent);
        if(sparent!=dparent){
            output[count]=curr;
            count++;
            parent[sparent]=dparent;
        }
        i++;
    }
    for(int i=0;i<n-1;i++){
        if(output[i].source<output[i].dest){
        cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }
        else{
            cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
        }
    }

}
int main(){
    int n,e;
    edge *input=new edge[e];
    cout<<"Enter Number of Vertices & Edges : ";
    cin>>n>>e;
    for(int i=0;i<e;i++ ){
        int s,d,w;
        cout<<"Enter Source, Destination, Weight : ";
        cin>>s>>d>>w;
        input[i].source=s;
        input[i].dest=d;
        input[i].weight=w;
    }
    kruskals(input,n,e);

}