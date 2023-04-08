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

ll ans=0;
void mergearr(ll i,ll j,vector<ll>&v){
	vll tmp;
	ll sp=i;
	ll m=(i+j)/2+1;
	ll ss=m;
	while(i<=j&&i<=(sp+j)/2&&m<=j){
		if(v[i]<v[m]){
			tmp.push_back(v[i]);
			i++;
		}
		else{
			// debug(i);
			// debug(m);
			// debug(v);
			ans+=(ss-i);
			// debug((ss-i));
			tmp.push_back(v[m]);
			m++;
		}
	}
	while(i<=(sp+j)/2){
		tmp.push_back(v[i]);
		i++;
	}
	while(m<=j){
		tmp.push_back(v[m]);
		m++;
	}
	// debug(i);
	// debug(j);
	// debug(v);
	// debug(tmp);
	while(tmp.size()){
		v[j]=tmp[tmp.size()-1];
		j--;
		tmp.pop_back();
	}
}

void inversioncnt(ll i,ll j,vector<ll>&v){
	if(i==j){
		return;
	}
	// cout<<"MERGE SORT "<<i <<" "<<j<<endl;
	inversioncnt(i,(i+j)/2,v);
	inversioncnt(((i+j)/2)+1,j,v);
	mergearr(i,j,v);
}

void answer(){
int n;
cin>>n;
vector<ll>v(n);
for (int i = 0; i <n; ++i){
	cin>>v[i];
}
inversioncnt(0,n-1,v);
cout<<ans<<endl;
}
int main(){
fileio();
fastio();
ll t;
cin>>t;
while(t--){
 answer();
}
return 0;
}
// This Template Is Created By Vishal Sharma