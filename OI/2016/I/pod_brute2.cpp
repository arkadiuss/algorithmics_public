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
const int MAX=500100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int B,q;
int a[MAX];
vector<ll> nums;
int fctrl(int n){
	int f=1;
	loop(i,1,n+1){
		f=f*i;
	}
	return f;
}
void coutNums(int mask){
	loopback(i,nums.size()-1,0){
		if(1<<i&mask)
			cout<<nums[i];
	}
	cout<<"\n";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>B>>q;
	int sum=0;
	loop(i,0,B){
		cin>>a[i];
		sum=sum+a[i];
	}
	loop(i,0,B){
		loop(j,0,a[i]){				
			nums.pb(i);		
		}
	}
	vector<ll> bestnum;
	int bestmask;
	loop(mask,1,1<<sum){
		ll dec=0;
		ll p=1;
		loop(i,0,sum){
			if(1<<i&mask){
				dec+=p*nums[i];
				p=p*B;	
			}
			
		}
		if(dec%(B-1)==0){
			bestnum=nums;
			bestmask=mask;
			//coutNums(mask);
			//pln(dec);
		}	
	}
	nums=bestnum;
	coutNums(bestmask);
}
