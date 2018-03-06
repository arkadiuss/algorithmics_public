#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define foreach(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define SIZE(c) (c).size()
#define ALL(c) (c).begin(), (c).end()
using namespace std;
typedef vector<int> VI;
const int INFTY=20000000;
const int MAX=200100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
struct task{
	int i;
	int a;
	ll t;
	bool operator<(const task & b) const
	{
		return t<b.t;
	}
};
bool sortByA(task a,task b){
	if(a.a==b.a) return a.t<b.t;
	return a.a>b.a;
}
task ts[MAX];
int n;
ll T;
	
int main(){
	//ios_base::sync_with_stdio(0);
	cin>>n>>T;
	loop(i,0,n){
		cin>>ts[i].a>>ts[i].t;
		ts[i].i=i;
	}
	sort(ts,ts+n,sortByA);
	
	priority_queue<task> Q;
	int i=0;
	ll sT=0;
	while(i<n&&Q.size()<ts[i].a){
		if(sT+ts[i].t<=T){
			Q.push(ts[i]);
			sT+=ts[i].t;
		}else{
			if(!Q.empty()&&Q.top().t>ts[i].t){
				sT-=Q.top().t;
				Q.pop();
				sT+=ts[i].t;
				Q.push(ts[i]);
			}
		}
		i++;
	}
	
	int c=0;
	vector<task> ans;
	while(!Q.empty()){
		ans.pb(Q.top());
		Q.pop();
	}
	loop(i,0,ans.size()) if(ans[i].a>=ans.size()) c++;
	pln(c);
	pln(ans.size());
	foreach(it,ans) ps((it->i)+1);
}
