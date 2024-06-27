#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int n;
vector<int> adj[10];
vector<int> outdegree(10,0);
vector<int> indegree(10,0);
bool visit[10];
void addEdge(int u,int v){
    adj[u].push_back(v);
    outdegree[u]++;
    indegree[v]++;
}
void findleaf(){
    for (int i = 0; i < n; i++)
    {
            if (outdegree[i]==0&&indegree[i]>=1)
            {
                cout<<i<<" ";
            }  
    }
}
int main(){
    cin>>n;
    int u,v;
    while (1)
    {
        cin>>u>>v;
        if (u==-1||v==-1)
        {
            break;
        }
        addEdge(u,v);
    }
    findleaf();
    return 0;
}