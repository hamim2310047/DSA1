#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int n;
vector<int> adj[10];
vector<int> indegree(10,0);
bool visit[10];
void addEdge(int u,int v){
    adj[u].push_back(v);
    indegree[v]++;
}
void DFS(int start){
    stack<int> st;
    st.push(start);
    visit[start]=true;
    while (!st.empty())
    {
        int u= st.top();
        cout<<u<<" ";
        st.pop();
        for (int i = 0; i < adj[u].size(); i++)
        {
            if (!visit[adj[u][i]])
            {
                visit[adj[u][i]]=true;
                st.push(adj[u][i]);
            }
        }
    }
}
int findRoot(){
    for (int i = 0; i < n; i++)
    {
        if (!adj[i].empty())
        {
          if (indegree[i]==0)
          {
            return i;
          }
        }
    }
    return -1;
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
    if (findRoot()!=-1)
    {
        cout<<"Root : "<<findRoot()<<endl;
    }
    else{
        cout<<"Root not found"<<endl;
    }
    return 0;
}