#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> adjlist[10];
int visited[10];
void AddEdge(int a, int b){
    adjlist[a].push_back(b);
    //adjlist[b].push_back(a);
}
void dfs(int start){
    stack<int> st;
    visited[start]=1;
    st.push(start);

    while (!st.empty())
    {
        int n= st.top();
        cout<<n<<endl;
        st.pop();
        for (int i = 0; i < adjlist[n].size(); i++)
        {
            if (!visited[adjlist[n][i]])
            {
                visited[adjlist[n][i]]=1;
                st.push(adjlist[n][i]);
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
    cout<<"DFS: "<<endl;
    dfs(0);
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