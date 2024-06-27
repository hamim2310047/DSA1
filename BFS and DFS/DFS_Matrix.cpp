#include<iostream>
#include<stack>
using namespace std;
int matrix[10][10];
bool visited[10];
int n;
void addEdge(int u, int v){
    matrix[u][v]=1;
    matrix[v][u]=1;
}
void DFS(int strat){
    stack<int> st;
    st.push(strat);
    visited[strat]=true;
    while (!st.empty())
    {
        int u = st.top();
        cout<<u<<" ";
        st.pop();
        for (int i = 0; i < n; i++)
        {
            if (!visited[i]&&matrix[u][i])
            {
                visited[i]=true;
                st.push(i);
            }
        }
    }
    cout<<endl;
}
int main(){
    cout<<"Size: "<<endl;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        visited[i]=false;   
    }
    while (1)
    {
        int u,v;
        cin>>u>>v;
        if (u==-1||v==-1)
        {
            break;
        }
        addEdge(u,v);
    }
    cout<<"DFS:"<<endl;
    DFS(0);
    cout<<"Matrix:"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}