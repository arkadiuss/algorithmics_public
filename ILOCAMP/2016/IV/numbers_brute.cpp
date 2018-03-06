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
const ll MOD=1000000009;

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

int check(int L, int R,int num){
	int last=nums[R];
	while(num){
		if(!(num%10<last)) return false;
		last=num%10;
		num=num/10;
	}
	if(nums[L]<last)
		return true;
	return false;	
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
			ans=(ans*countPoss(L,i))%MOD;
		}
		if(nums[i]>0){
			L=i;
		}
	}
	cout<<ans;
}
