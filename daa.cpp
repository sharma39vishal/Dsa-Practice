Lab Manual
⦁	WAP to implement Linear Search & determine its time complexity.
Solution:

#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int arr[n];
for (int i = 0; i < n; ++i){
    cin>>arr[i];
}
int target;
cin>>target;
for (int i = 0; i < n; ++i){
    if(arr[i]==target){
        cout<<"Element Was found on Index : "<<i<<endl;
        return 0;
    }
}
cout<<"Element does not found"<<endl;
return 0;
}

Input:
5
1 2 3 4 5
4

Output:
Element Was found on Index : 3
 
Time Complexity:
O(N) due to traversal through single loop and finding of element.


















⦁	WAP to implement Binary Search & determine its time complexity.
 • Recursive method 
Solution:
#include <bits/stdc++.h>
using namespace std;
void binarySearch(int arr[],int left,int right,int target){
    if(left>right){
        cout<<"Element does not found"<<endl;
        return;
    }
    int mid=(left+right)/2;
    if(arr[mid]==target){
        cout<<"Element Was found on Index : "<<mid<<endl;
    }
    else if(arr[mid]>target){
         binarySearch(arr,left,mid-1,target);
    }
    else{
         binarySearch(arr,mid+1,right,target);
    }
}

int main(){
int n;
cin>>n;
int arr[n];
for (int i = 0; i < n; ++i){
    cin>>arr[i];
}
int target;
cin>>target;

binarySearch(arr,0,n-1,target);

return 0;
}

 
 

• Iterative method 
Solution:
#include <bits/stdc++.h>
using namespace std;

int main(){
int n;
cin>>n;
int arr[n];
for (int i = 0; i < n; ++i){
    cin>>arr[i];
}
int target;
cin>>target;
int left=0,right=n-1;
while(left<right){
    int mid=(left+right)/2;
    if(arr[mid]==target){
        cout<<"Element Was found on Index : "<<mid<<endl;
        return 0;
    }
    else if(arr[mid]>target){
         right=mid-1;
    }
    else{
         left=mid+1;
    }
}
cout<<"Element does not found"<<endl;
}

 

Time Complexity :O(logN)








⦁	WAP to implement Insertion Sort & determine its time complexity.
Solution:
#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int arr[n];
for (int i = 0; i < n; ++i){
    cin>>arr[i];
}
int i, key, j;
for (i = 1; i < n; i++){
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key){
        arr[j + 1] = arr[j];
        j = j - 1;
    }
    arr[j + 1] = key;
}
cout<<"Sorted Array :";
for (int i = 0; i < n; ++i){
    cout<<arr[i]<<" ";
}
cout<<endl;
}
 
Time Complexity :O(N2)



















⦁	WAP to implement Bubble Sort & determine its time complexity. 
Solution:
#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int arr[n];
for (int i = 0; i < n; ++i){
    cin>>arr[i];
}
for (int i = 0; i<n-1; i++){
    for (int j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
}
cout<<"Sorted Array :";
for (int i = 0; i < n; ++i){
    cout<<arr[i]<<" ";
}
cout<<endl;
}
 Time Complexity:O(N2)
⦁	WAP to implement Selection Sort & determine its time complexity. 
Solution:
#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int arr[n];
for (int i = 0; i < n; ++i){
    cin>>arr[i];
}
int i, j, min_idx;
for (i = 0; i < n-1; i++){
    min_idx = i;
    for (j = i+1; j < n; j++)
    if (arr[j] < arr[min_idx])
         min_idx = j;
    if(min_idx!=i)
        swap(arr[min_idx],arr[i]);
}
cout<<"Sorted Array :";
for (int i = 0; i < n; ++i){
    cout<<arr[i]<<" ";
}
cout<<endl;
}
 
Time Complexity:O(N2)




















⦁	WAP to implement Quick Sort & determine its time complexity. 
Solution:
#include <bits/stdc++.h>
using namespace std;
int partition(int arr[],int i,int j){
    int pivot = arr[j]; // pivot element  
    int left = (i-1);  
    for (int r = i; r <= j - 1; r++) {  
        if (arr[r] < pivot){  
            left++;
            swap(arr[left],arr[r]);
        }  
    }  
    swap(arr[left+1],arr[j]);
    return (left + 1);
}

void quickSort(int arr[],int i,int j){
    if(i<j){
        int p=partition(arr,i,j);
        quickSort(arr,i,p-1);
        quickSort(arr,p+1,j);
    }
}

int main(){
int n;
cin>>n;
int arr[n];
for (int i = 0; i < n; ++i){
    cin>>arr[i];
}
quickSort(arr,0,n-1);
cout<<"Sorted Array :";
for (int i = 0; i < n; ++i){
    cout<<arr[i]<<" ";
}
cout<<endl;
}

 
 
Time Complexity : O(NlogN)








⦁	WAP to implement Merge Sort & determine its time complexity.
Solution:
#include <bits/stdc++.h>
using namespace std;

void mergeprocess(int A[],int start,int mid,int end) {
int p = start ,q = mid+1;
int Arr[end-start+1] , k=0;
for(int i = start ;i <= end ;i++) {
    if(p > mid)     
       Arr[ k++ ] = A[ q++] ;
   else if ( q > end)  
       Arr[ k++ ] = A[ p++ ];
   else if( A[ p ] < A[ q ])
      Arr[ k++ ] = A[ p++ ];
   else
      Arr[ k++ ] = A[ q++];
 }
  for(int p=0 ; p< k ;p ++) {
     A[ start++ ] = Arr[ p ] ;                          
  }
}

void mergeSort(int arr[],int i,int j){
    if(i==j){
        return;
    }
    int mid=(i+j)/2;
    mergeSort(arr,i,mid);
    mergeSort(arr,mid+1,j);
    mergeprocess(arr,i,mid,j);
}

int main(){
int n;
cin>>n;
int arr[n];
for (int i = 0; i < n; ++i){
    cin>>arr[i];
}
mergeSort(arr,0,n-1);
cout<<"Sorted Array :";
for (int i = 0; i < n; ++i){
    cout<<arr[i]<<" ";
}
cout<<endl;
}

 
 
Time Complexity : O(NlogN)

⦁	WAP to implement Heap Sort & determine its time complexity. 
Solution:
#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i) {
    int mi=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n&&arr[mi]<arr[l]){
        mi=l;
    }
    if(r<n&&arr[mi]<arr[r]){
        mi=r;
    }
    if(mi!=i){
    swap(arr[mi],arr[i]);
    heapify(arr,n,mi);
    }
}

void buildHeap(int arr[], int n) {
    for(int i=n-1;i>=0;i--){
    heapify(arr,n,i);
    }
}
    
void heapSort(int arr[], int n){
    buildHeap(arr,n);
   for(int i=n-1;i>=0;i--){
       swap(arr[i],arr[0]);
       heapify(arr,i,0);
   }
}

int main(){
int n;
cin>>n;
int arr[n];
for (int i = 0; i < n; ++i){
    cin>>arr[i];
}
heapSort(arr,n);
cout<<"Sorted Array :";
for (int i = 0; i < n; ++i){
    cout<<arr[i]<<" ";
}
cout<<endl;
return 0;
}
 

 
Time Complexity : O(NlogN)




















⦁	WAP to implement Strassen's matrix multiplication. 
Solution:
#include <bits/stdc++.h>
using namespace std;
int dp[501][501];
int solve(int i, int j,int arr[]){
     if(i>=j)return 0;
     int ans=INT_MAX;
     if(dp[i][j]!=-1){
        return dp[i][j];
     }
     for(int k=i;k<=j-1;k++){
         int tempAns = solve(i,k,arr) + solve(k+1,j,arr)+ arr[i-1]*arr[k]*arr[j];   
         ans=min(ans,tempAns);                        
     }
     return dp[i][j]=ans;
}
int main(){
int n;
cin>>n;
int arr[n];
for (int i = 0; i < n; ++i){
    cin>>arr[i];
}
memset(dp,-1,sizeof(dp));
cout<<"Answer : "<<solve(1,n-1,arr)<<endl;
return 0;
}
 





















10. Write a program to implements knapsack using greedy. 
Solution:
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};
struct comparitor_{
    bool operator()(Item min, Item max){
        return (double)max.value / max.weight > (double)min.value / min.weight;
    }
};
double fractionalKnapsack(int capacity, Item arr[], int n){
    priority_queue<Item, vector<Item>, comparitor_> pq;
    for (int i = 0; i < n; i++){
        pq.push(arr[i]);
    }
    double total_value = 0;
    while (capacity && pq.size()){
        auto top = pq.top();
        pq.pop();
        if (top.weight <= capacity){
            total_value += top.value;
            capacity -= top.weight;
        }
        else{
            total_value += (double)top.value / top.weight * capacity;
            capacity = 0;
        }
    }
    return total_value;
}

int main(){
int W = 50;
Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
int N = sizeof(arr) / sizeof(arr[0]);
cout <<fractionalKnapsack(W,arr,N)<<endl;
}
 
 
Time Complexity: O(NlogN)







⦁	Program for finding minimum cost spanning tree using greedy method using Prim’s algorithm. 
Solution:
#include<bits/stdc++.h>
using namespace std;
int main(){
    int N=5,m=6;
    vector<pair<int,int> > adj[N]; 
    adj[0].push_back({1,2});
    adj[0].push_back({3,6});
    adj[1].push_back({0,2});
    adj[1].push_back({2,3});
    adj[1].push_back({3,8});
    adj[1].push_back({4,5});
    adj[2].push_back({1,3});
    adj[2].push_back({4,7});
    adj[3].push_back({0,6});
    adj[3].push_back({1,8});
    adj[4].push_back({1,5});
    adj[4].push_back({2,7});
    int parent[N];
    int key[N]; 
    bool mstSet[N]; 
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    key[0] = 0; 
    parent[0] = -1; 
    int ansWeight = 0;
    for (int count = 0; count < N - 1; count++){ 
        int mini = INT_MAX, u; 
  
        for (int v = 0; v < N; v++) {
            if (mstSet[v] == false && key[v] < mini) 
                mini = key[v], u = v;
        }
      mstSet[u] = true; 
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) 
                parent[v] = u, key[v] = weight; 
        }
    } 
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
    return 0;
}

 
 

⦁	Program for finding minimum cost spanning tree using greedy method using Kruskal’s algorithm. 
Solution:
#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};
bool comp(node a, node b) {
    return a.wt < b.wt; 
}
int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); 
}
void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
        parent[v] = u; 
    }
    else {
        parent[v] = u;
        rank[u]++; 
    }
}
int main(){
    int N=5,m=6;
    vector<node> edges; 
    edges.push_back(node(0,1,2));
    edges.push_back(node(0,3,6));
    edges.push_back(node(1,0,2));
    edges.push_back(node(1,2,3));
    edges.push_back(node(1,3,8));
    edges.push_back(node(1,4,5));
    edges.push_back(node(2,1,3));
    edges.push_back(node(2,4,7));
    edges.push_back(node(3,0,6));
    edges.push_back(node(3,1,8));
    edges.push_back(node(4,1,5));
    edges.push_back(node(4,2,7));
    sort(edges.begin(), edges.end(), comp); 
    
    vector<int> parent(N);
    for(int i = 0;i<N;i++) 
        parent[i] = i; 
    vector<int> rank(N, 0); 
    
    int cost = 0;
    vector<pair<int,int>> mst; 
    for(auto it : edges) {
        if(findPar(it.v, parent) != findPar(it.u, parent)) {
            cost += it.wt; 
            mst.push_back({it.u, it.v}); 
            unionn(it.u, it.v, parent, rank); 
        }
    }
    cout << cost << endl;
    for(auto it : mst) cout << it.first << " - " << it.second << endl; 
    return 0;
}

 
 
 



⦁	Program for finding all pairs shortest paths using Dijkstra’s algorithm.
Solution:
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=5,m=6,source=1;
    vector<pair<int,int> > g[n+1];
    g[1].push_back({2,2});
    g[1].push_back({4,1});
    g[2].push_back({1,2});
    g[2].push_back({5,5});
    g[2].push_back({3,4});
    g[3].push_back({2,4});
    g[3].push_back({4,3});
    g[3].push_back({5,1});
    g[4].push_back({1,1});
    g[4].push_back({3,3});
    g[5].push_back({2,5});
    g[5].push_back({3,1});  
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
    vector<int> distTo(n+1,INT_MAX);
    distTo[source] = 0;
    pq.push(make_pair(0,source));   
    while( !pq.empty() ){
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();
        vector<pair<int,int> >::iterator it;
        for( it = g[prev].begin() ; it != g[prev].end() ; it++){
            int next = it->first;
            int nextDist = it->second;
            if( distTo[next] > distTo[prev] + nextDist){
                distTo[next] = distTo[prev] + nextDist;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }
    cout << "The distances from source " << source << " are : \n";
    for(int i = 1 ; i<=n ; i++) cout << distTo[i] << " ";
    cout << "\n";
    return 0;
}

 
 







⦁	 Write a program for optimal merge patterns. 
Solution:
#include <bits/stdc++.h>
using namespace std;
void sol(int arr[],int i,int j,int &mx,int &mn){
    if(i==j){
        mx=max(mx,arr[i]);
        mn=min(mn,arr[i]);
        return;
    }
    int mid=(i+j)/2;
    sol(arr,i,mid,mx,mn);
    sol(arr,mid+1,j,mx,mn);
}

int main(){
int n;
cin>>n;
int arr[n];
for (int i = 0; i < n; ++i){
    cin>>arr[i];
}
int mx=INT_MIN,mn=INT_MAX;
sol(arr,0,n-1,mx,mn);
cout<<"MIN of All element :"<<mn<<endl;
cout<<"MAX of All element :"<<mx<<endl;
return 0;
}
 





















⦁	 Program to implement 8 queens problem using backtrack method. 
Solution:
#include <bits/stdc++.h>
using namespace std;
 vector<vector<string>>board;
 bool isSafe(vector<string>& v, int row, int col) {
        int n =v.size();
        for(int i = 0; i < n; i++) {
            if(v[i][col] == 'Q') return false; 
            if(row - i >= 0 && col - i >= 0 && v[row - i][col - i] == 'Q') return false;
            if(row - i >= 0 && col + i <  n && v[row - i][col + i] == 'Q') return false;
       }
        return true;
    }
    void rec(vector<string>&v,int i,int n){
        if(i==n){
            board.push_back(v);
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(v,i,j)){
                v[i][j]='Q';
                rec(v,i+1,n);
                v[i][j]='.';
            }
        }
    }
int main(){
int n;
cin>>n;
string s(n,'.');
vector<string>v(n,s);
rec(v,0,n);
for (int i = 0; i < board.size(); ++i){
    for(int j=0;j<board[0].size();j++){
        cout<<board[i][j]<<endl;
    }
    cout<<endl;
}
return 0;
}

 
 





⦁	 Write a program to implement Hamiltonian cycle problem. 
Solution:
#include<bits/stdc++.h>
using namespace std;
int n=5;
int graph[5][5] = {
   {0, 1, 0, 1, 0},
   {1, 0, 1, 1, 1},
   {0, 1, 0, 0, 1},
   {1, 1, 0, 0, 1},
   {0, 1, 1, 1, 0},
};
int path[5];
bool isValid(int v, int k) {
   if (graph [path[k-1]][v] == 0) 
      return false;

   for (int i = 0; i < k; i++)  
      if (path[i] == v)
         return false;
   return true;
}

bool cycleFound(int k) {
   if (k == n) {  
      if (graph[path[k-1]][ path[0] ] == 1 )
         return true;
      else
         return false;
   }
   for (int v = 1; v < n; v++) {      
      if (isValid(v,k)) {                
         path[k] = v;
         if (cycleFound (k+1) == true)
            return true;
         path[k] = -1;               
      }
   }
   return false;
}
bool hamiltonianCycle() {
   for (int i = 0; i < n; i++)
      path[i] = -1;
   path[0] = 0; //first vertex as 0

   if ( cycleFound(1) == false ) {
      cout <<"No path possible"<<endl;
      return false;
   }
   cout<< " hamiltonian cycle is: ";
   for (int i = 0; i < n; i++)
      cout << path[i] << " ";
   cout << path[0] << endl;      
   return true;
}
int main() {
   hamiltonianCycle();
   return 0;
}

 
 
