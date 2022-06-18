#include <bits/stdc++.h>
using namespace std;
typedef long long int  ll;

void fileio(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void traverse(vector<vector<ll>> & v,ll curr,ll pr){
    cout<<curr<<endl;
    for (ll i = 0; i < v[curr].size(); ++i){
        if(v[curr][i]!=pr){
        traverse(v,v[curr][i],curr);
      }
    }
}


int main(){

fileio();

ll n;
cin>>n;
vector<vector<ll>>v(n+1);
for (ll i = 0; i < n-1; ++i){
    ll x,y;
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
}

// print adjency list

for (int i = 0; i < v.size(); ++i){
    cout<<i<<": ";
    for (int j = 0; j< v[i].size(); ++j){
        cout<<v[i][j]<<" ";
    }
    cout<<endl;
}

// traverse
cout<<"traversal of n-ary tree"<<endl;
traverse(v,2,0);

}

