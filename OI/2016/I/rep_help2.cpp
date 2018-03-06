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
const int MAX=1000000100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
void coutLLTab(ll* tab,int n){
	cout<<"{";
	loop(i,1,n+1){
		cout<<tab[i]<<", ";
	}
	cout<<"}\n";
}
void coutBoolTab(bool* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
bool diff[200];
pair<int,int> diffsToPair[100];
int r[110];
ll a[110];
long long fastPower(long long n, long long p){
	if(p==0) 
		return 1;
	else if(p==1) 
		return n;
	else if(p%2==0){
		n=fastPower(n,p/2);
		return n*n;
	}else 
		return n*fastPower(n,p-1);
}
ll av(int i){
	ll p,maxr;
	p=(i-1)/2;
	maxr=(i-2)/2;
	ll sum=0;
	sum=2*fastPower(2,p); 
	ll maxpr=sum/4;
	//cout<<sum<<" "<<maxpr<<" "<<maxr<<": ";
	loop(j,0,maxr){
		sum=sum+maxpr*r[j+1];
		//ps(r[j+1]);
		maxpr=maxpr/2;
	}
	//cout<<": ";
	return sum;		
}
int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	a[1]=1;
	a[2]=2;
	diff[1]=1;
	int ar=2;
	int ir=1;
	loop(i,3,n+1){
		cout<<av(i-1)<<" ";
		if(i%2==1)
			a[i]=2*a[i-1];
		else{
			a[i]=a[i-1]+ar;
			diff[ar]=1;
			r[ir]=ar;
			ir++;
			//cout<<ar<<" ";
		}	
		loop(j,1,i){
			if(a[i]-a[j]<200)
				diff[a[i]-a[j]]=1;
				
			//cout<<a[i]-a[j]<<" "; 
		}
		//entr;
		while(diff[ar]){
			ar++;
		}
					
	}
	entr;
	coutTab(r,ir);
	//coutBoolTab(diff,(100));
	coutLLTab(a,n);
}
