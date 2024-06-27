#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int n;
vector<int> adj[10];
bool visited[10];
void AddEdge(int u, int v){
    adj[u].push_back(v);
}
void DFS(int start){
    stack<int> st;
    st.push(start);
    visited[start]= true;
    while (!st.empty()){
        int u = st.top();
        cout<<u<<" ";
        st.pop();
        for (int i = 0; i < adj[u].size(); i++)
        {
            if (!visited[adj[u][i]])
            {
                st.push(adj[u][i]);
                visited[adj[u][i]]= true;
            }
        }
    }
    cout<<endl;
}
bool is_StronglyConnected(){
    for (int i = 0; i < n; i++)
    {
        if (!adj[i].empty())
        {
            for (int j = 0; j < n; j++)
            {
                visited[j]=false;
            }
            DFS(i);
            for (int j = 0; j < n; j++)
            {
                if (visited[j]==false)
                {
                    return false;
                }
            }
            
        }
    }
    return true;
}
int main(){
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        visited[i]=false;
    }
    int u,v;
    while (1)
    {
        cin>>u>>v;
        if (u==-1||v==-1)
        {
            break;
        }
        AddEdge(u,v);
    }
    if (is_StronglyConnected())
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}