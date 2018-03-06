#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
const int INFTY=20000000;
const int MAX=1000100;
const int MAXVALUE=1000000001;
const int ASIZE=60;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}

void coutLLTab(ll* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
pair<ll,ll> ind[MAX];
ll a[]={0, 1, 2, 4, 8, 16, 21, 42, 51, 102, 112, 224, 235, 470, 486, 972, 990, 1980, 2002, 4004, 4027, 8054, 8078, 16156, 16181, 32362, 32389, 64778, 64806, 129612, 129641, 259282, 259313, 518626, 518658, 1037316, 1037349, 2074698, 2074734, 4149468, 4149505, 8299010, 8299049, 16598098, 16598140, 33196280, 33196324, 66392648, 66392693, 132785386, 132785432, 265570864, 265570912, 531141824, 531141876, 1062283752, 1062283805, 2124567610, 2124567664, 4249135328, 4249135383, 8498270766, 8498270822, 16996541644, 16996541701, 33993083402, 33993083460, 67986166920, 67986166979, 135972333958, 135972334020, 271944668040, 271944668103, 543889336206, 543889336270, 1087778672540, 1087778672605, 2175557345210, 2175557345276, 4351114690552, 4351114690619, 8702229381238, 8702229381306, 17404458762612, 17404458762681, 34808917525362, 34808917525433, 69617835050866, 69617835050938, 139235670101876, 139235670101949, 278471340203898, 278471340203972, 556942680407944, 556942680408019, 1113885360816038, 1113885360816114, 2227770721632228, 2227770721632305, 4455541443264610, 4455541443264688, 8911082886529376};

void coutInd(){
	loop(i,0,100){
		cout<<i<<": "<<"("<<ind[i].ff<<","<<ind[i].ss<<")"<<"\n";
	}
}

void prepare(){
	loop(i,0,MAX){
		ind[i]=mp(-1,-1);
	}
	ind[1]=mp(2,1);
}
const int MAXXTAB=1000001;
void firstPhase(){ //count differences between every a[1]..a[ASIZE]
	loop(i,1,ASIZE){	
		loop(j,1,i){
			if(a[i]-a[j]<MAXXTAB)
				ind[a[i]-a[j]]=mp(i,j);
		}
					
	}
} 
void secondPhase(){
	int indA=ASIZE;
	loop(i,2,MAXXTAB){
		if(ind[i].ff==-1){
			ind[i]=mp(indA,indA-1);
			indA=indA+2;
		}
	}
}
pair<ll,ll> findBetter(ll x){
	ll smaller=0;
	loop(i,1,ASIZE){	
		loop(j,1,i){
			if(a[i]-a[j]>=MAXXTAB&&a[i]-a[j]<MAXVALUE){
				if(a[i]-a[j]==x) return mp(i,j);
				if(a[i]-a[j]<x) smaller++; 
			}	
		}			
	}
	return mp(-1,smaller);
}
ll countBetterR(ll x,ll smaller){
	ll r=(x-MAXXTAB+1-smaller)*2+ind[MAXXTAB-1].ff;
}
int main(){
	ios_base::sync_with_stdio(0);
	prepare();
	firstPhase();
	secondPhase();
	//coutInd();
	//coutLLTab(a,ASIZE);
	int n,x;
	cin>>n;
	loop(i,0,n){
		cin>>x;
		if(x<MAXXTAB){
			cout<<ind[x].ff<<" "<<ind[x].ss;
		}else{
			pair<ll,ll> res;
			res=findBetter(x);
			if(res.ff==-1){
				ll r=countBetterR(x,res.ss);
				cout<<r<<" "<<r-1;
			}else
				cout<<res.ff<<" "<<res.ss;
		}
		entr;
		
	}
}
