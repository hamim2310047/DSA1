#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int adjlist[10][10];
int visited[10];
int x;
void AddEdge(int a, int b){
    adjlist[a][b]=1;
    adjlist[b][a]=1;
}
void bfs(int start){
    queue<int> queue;
    visited[start]=1;
    queue.push(start);

    while (!queue.empty())
    {
        int u= queue.front();
        cout<<u<<endl;
        queue.pop();
        for (int i = 0; i <x ; i++)
        {
            if (!visited[i]&&adjlist[u][i])
            {
                visited[i]=1;
                queue.push(i);
            }
        }
    }
}
int main(){
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
    cout<<"Matrix :"<<endl;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cout<<adjlist[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"BFS: "<<endl;
    bfs(0);
    return 0;
}