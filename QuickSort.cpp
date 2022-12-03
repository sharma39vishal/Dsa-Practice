#include <bits/stdc++.h>
using namespace std;

int partion(vector<int>&v,int i,int j){
    int pi=i,e=j;
    i+=1;
    while(i<j){
        while(i<=e&&v[i]<=v[pi]){
            i++;
        }
        while(j>=pi&&v[j]>=v[pi]){
            j--;
        }
        if(i<=e&&j>=pi){
            swap(v[i],v[j]);
            i++;
            j--;
        }
    } 
    if (v[pi]>v[j]){
       swap(v[pi],v[j]);
    }
return j;
}

void quicksort(vector<int>&v,int i,int j){
    if(i>=j){
        return ;
    }
    int p=partion(v,i,j);
    quicksort(v,i,p-1);
    quicksort(v,p+1,j);
}

int main(){
int n;
cin>>n;
vector<int>v(n);
for (int i = 0; i < n; ++i){
    cin>>v[i];
}
quicksort(v,0,n-1);
for (int i = 0; i < n; ++i){
    cout<<v[i]<<" ";
}
cout<<endl;
}

