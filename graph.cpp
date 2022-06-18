#include <bits/stdc++.h>
using namespace std;

void fileio(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void dfs(vector<vector<int>>& adj,int pa,vector<int> &visit){
    visit[pa]=1;
    cout<<pa<<" ";
    for (int i = 0; i <adj[pa].size() ; ++i){
    if (visit[adj[pa][i]]==0){
            dfs(adj,adj[pa][i],visit);
        }    
    }
}


int main(){
fileio();
int n,m;
// n nodes and m inputes
cin>>n>>m;
vector<vector<int>>adj(n+1);
for (int i = 0; i < m; ++i){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}

cout<<"adjency list"<<endl;
for (int i = 0; i < adj.size(); ++i){
    cout<<i<<": ";
    for (int j = 0; j< adj[i].size(); ++j){
        cout<<adj[i][j]<<" ";
    }
    cout<<endl;
}

vector<int>visit(n+1,0);
cout<<"dfs of tree"<<endl;
dfs(adj,1,visit);
cout<<endl;








vector<int>visit1(n+1,0);
cout<<"bfs of tree"<<endl;
queue<int>q;
q.push(1);
visit1[1]=1;
while(!q.empty()){
        int x=q.front();
        q.pop();
        cout<<x<<" ";
    for (int i = 0; i < adj[x].size(); ++i){
        if (visit1[adj[x][i]]){
        continue;
        }
        visit1[adj[x][i]]=1;
            q.push(adj[x][i]);
    }
}

}

    
