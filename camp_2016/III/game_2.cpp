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
ll ms[MAX];//majatek spolki
vector<int> so[MAX]; //spolki wlascicieli
vector<int> wls[MAX]; //wlasciciele spolki
ll mo[MAX]; //majatek oligarchy
bool isBig[MAX];
bool oneBig;
int n,m,q;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>q;
	int a,fi,o;
	ll zi,sum;
	int sq;
	loop(i,0,n){
		mo[i]=0;
		ms[i]=0;
		isBig[i]=0;
	}
	sq=sqrt(n);
	loop(i,0,q){
		cin>>a;
		if(a==1){
			cin>>fi>>zi;
			ms[fi]=ms[fi]+zi;
			if(oneBig){
				loop(j,0,wls[fi].size()){
					if(isBig[wls[fi][j]])
						mo[wls[fi][j]]=mo[wls[fi][j]]+zi;
				}
			}
		}else if(a==2){
			cin>>o;
			sum=0;
			if(!isBig[o]){
				loop(j,0,so[o].size()){
					sum=sum+ms[so[o][j]];
				}
			}else
				sum=mo[o];
					
			cout<<sum<<"\n";
		}else{
			cin>>o>>fi;
			so[o].push_back(fi);
			if(isBig[o]){
				mo[o]=mo[o]+ms[fi];
				wls[fi].push_back(o);
			}
			if(so[o].size()>=sq&&!isBig[o]){
				sum=0;
				loop(j,0,so[o].size()){
					sum=sum+ms[so[o][j]];
					wls[so[o][j]].push_back(o);
				}
				isBig[o]=1;
				mo[o]=sum;
				oneBig=1;
			}
			
		}
	}
}
