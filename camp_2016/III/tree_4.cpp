#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
using namespace std;
const int INFTY=20000000;
const int MAX=500100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
vector< vector<int> > G(MAX);
int n;
int maxlev=0;
vector<int> ans;
int go(int v, int l){
	if(G[v].size()==1)
		return 1;
	int maxi=0, val;
	vector<int> vls;	
	loop(i,0,G[v].size()){
		if(G[v][i]!=l){
			val=go(G[v][i],v);
			maxi=max(val,maxi);
			vls.push_back(val);
		}
	}
	bool wasMaxi=0;
	loop(i,0,vls.size()){
		if(vls[i]!=maxi||wasMaxi){
			ans.push_back(vls[i]);
		}else{
			wasMaxi=1;
		}
	}
	//cout<<v+1<<" "<<maxi+1<<"\n";
	return maxi+1;	
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	int a,b;
	loop(i,0,n-1){
		cin>>a>>b;
		G[a-1].push_back(b-1);
		G[b-1].push_back(a-1);
	}
	int l=0;
	loop(i,1,n){
		if(G[i].size()==1)
			l++;
	}
	loop(i,0,G[0].size()){
		ans.push_back(go(G[0][i],0));
	}
	sort(ans.begin(),ans.end());
	
	loop(i,0,ans.size()){
		loop(j,0,ans[i]-1){
			cout<<l<<"\n";
		}
		l--;
		cout<<l<<"\n";
	}
	//cout<<0;
}
