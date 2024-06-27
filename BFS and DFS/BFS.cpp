#include<iostream>
#include<vector>
#include<queue>
#include<iterator>
using namespace std;

vector<int> adjlist[10];
int visited[10];
void AddEdge(int a, int b){
    adjlist[a].push_back(b);
    adjlist[b].push_back(a);
}
void bfs(int start){
    queue<int> queue;
    visited[start]=1;
    queue.push(start);

    while (!queue.empty())
    {
        int n= queue.front();
        cout<<n<<endl;
        queue.pop();
        for (int i = 0; i < adjlist[n].size(); i++)
        {
            if (!visited[adjlist[n][i]])
            {
                visited[adjlist[n][i]]=1;
                queue.push(adjlist[n][i]);
            }
        }
    }
}
int main(){
    int x;
    cout<<"size: ";
    cin>>x;
    for (int i = 0; i < x; i++)
    {
        visited[i]=0;
    }
    int u, v;
    cout<<"Input: "<<endl;
    while(1){
        cin>>u>>v;
        if(u==-1||v==-1){
            break;
        }
        AddEdge(u,v);
    }
    cout<<"BFS: "<<endl;
    bfs(0);
    cout<<"List: "<<endl;
    for (int i = 0; i < x; i++)
    {
        cout<<i<<"-->";
        vector<int> ::iterator p;
        for ( p = adjlist[i].begin(); p!=adjlist[i].end(); p++)
        {
            cout<<*p<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
/*
input: 
size: 5
0 1
0 2
1 3
2 0
2 3
2 4
-1 -1
*/