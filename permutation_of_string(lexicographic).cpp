#include <bits/stdc++.h>
using namespace std;
typedef long long int  ll;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define PI 3.141592653589793238462
#define com(x) (x).begin(), (x).end()
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
#define loop(i,a,b) for(ll i=a;i<b;++i)
#define bloop(i,a,b) for(ll i=a;i>=b;--i)
#define pb push_back
#define ppb pop_back
#define ss second
#define ff first
#define umap unordered_map
#define uset unordered_set
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define codejam cout << "Case #" << ii + 1 << ": ";
#define impossible cout << "IMPOSSIBLE" << endl;
#define dashline cout<<"-------------------------------"<<endl;
#define hashline cout<<"###############################"<<endl;
void fileio(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
}

void sol(ll i,string &s){
	if(i==s.length()){
		cout<<s<<endl;
		return ;
	}
	for (ll j = i; j <s.length() ;j++)	{
		swap(i,j,s);
		sol(i+1,s);
		swap(i,j,s);
	}
}
void answer(){
string s;
cin>>s;
sol(0,s);
}
int main(){
fileio();
fastio();
answer();
return 0;
}
// This Template Is Created By Vishal Sharma