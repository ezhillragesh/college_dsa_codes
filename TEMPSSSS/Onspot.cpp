#include<bits/stdc++.h>
using namespace std;
//21BBS0100
//Ezhill RAGESH K T
class Graph
{
    int V;
    list<int> *adjacent;
public:
    Graph(int V){
    this->V = V;
    adjacent = new list<int>[V];
    }
    void newnode(int v, int w){
    adjacent[v].push_back(w);
}
void DFS(int s, int end)
{
    vector<bool> seen(V, false);//Vector to keep track of nodes visited
    stack<int> stack; //using the pre-defined stack function
    stack.push(s);
 
    while (!stack.empty())
    {
        int s = stack.top();
        stack.pop();
 
        if (!seen[s])
        {
            cout << s << " ";
            seen[s] = true;
        }
        if(s==end)
        {
            break;
        }
 
        for (auto i = adjacent[s].begin(); i != adjacent[s].end(); ++i) if (!seen[*i]) stack.push(*i);
    }
}

};
 
int main()
{
    Graph g(18);
    //adding all the edges
    g.newnode(1, 2);
    g.newnode(2, 3);
    g.newnode(3, 12);    
    g.newnode(3, 4);
    g.newnode(4, 5);
    g.newnode(12, 13);
    g.newnode(13, 17);
    g.newnode(13, 14);
    g.newnode(17, 18);
    g.newnode(14, 15);
    g.newnode(15, 16);
    g.newnode(5, 9);
    g.newnode(5, 8);
    g.newnode(5, 6);
    g.newnode(9, 10);
    g.newnode(10, 11);
    g.newnode(6, 7);
    cout << "Expected Sequence : \n";
    g.DFS(1,16);
 
    return 0;
}