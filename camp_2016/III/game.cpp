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
int ms[MAX];//majatek spolki
vector<int> vs[MAX]; //wlasciciele spolki
int o[MAX]; //majatek oligarchy
int n,m,q;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>q;
	int a,fi,zo,zi;
	loop(i,0,q){
		cin>>a;
		if(a==1){
			cin>>fi>>zi;
			ms[fi]=ms[fi]+zi;
			loop(j,0,vs[fi].size()){
				o[vs[fi][j]]=o[vs[fi][j]]+zi;
			}
		}else if(a==2){
			cin>>zo;
			cout<<o[zo]<<"\n";
		}else{
			cin>>zo>>fi;
			//o[vs[fi]]=o[vs[fi]]-ms[fi];
			vs[fi].push_back(zo);
			o[zo]=o[zo]+ms[fi];
		}
	}
}
