#include<iostream>
#include<queue>
using namespace std;
int grid[10][10];
bool visited[10][10];
int n;
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
struct node
{
    int x;
    int y;
};
bool isValid(int x,int y){
    if (x>=0 && x<n && y>=0 && y<n && !visited[x][y])
    {
        return true;
    }
    return false;
}
void BFS(int a, int b){
    queue<node> q;
    q.push({a,b});
    visited[a][b]=true;
    while (!q.empty())
    {
        int x=q.front().x;
        int y=q.front().y;
        cout<<grid[x][y]<<" ";
        q.pop();
        for (int i = 0; i < n; i++)
        {
            int next_x=x+dx[i];
            int next_y=y+dy[i];
            if (isValid(next_x,next_y))
            {
                visited[next_x][next_y]=true;
                q.push({next_x,next_y});
            }
        }
    }
    cout<<endl;
}
int main(){
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>grid[i][j];   
        }
    }
    BFS(0,0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<visited[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}