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
const int MAX=2100;
const ll MOD=1000000007;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int n;
int nums[MAX];
vector<ll> poss(MAX);
vector<ll> newposs(MAX);
int countPoss(int L, int R, int size){
	
	int posssize=R-(L+size);
	loop(i,0,posssize){
		poss[i]=i+1;
	}
	ll S=0;
	loop(i,0,size-1){
		S=0;
		loop(i,0,posssize){
			S=(S+poss[i])%MOD;
			newposs[i]=S;
		}
		poss=newposs;
	}
	return poss[posssize-1];
}

int main(){
	ios_base::sync_with_stdio(0);
	int k;
	cin>>n>>k;
	nums[0]=0;
	n++;
	loop(i,1,n){
		cin>>nums[i];
	}
	nums[n]=k+1;
	n++;
	ll ans=1;
	int L;
	
	//entr;
	loop(i,0,n){
		if(i!=0&&nums[i-1]<0&&nums[i]>=0){
			//cout<<nums[L]<<" "<<nums[i]<<" "<<i-L-1<<" ";
			ans=(ans*countPoss(nums[L],nums[i],i-L-1))%MOD;
		}
		if(nums[i]>=0){
			L=i;
		}
	}
	cout<<ans;
}
