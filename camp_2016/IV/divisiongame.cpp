#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<=s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
using namespace std;
const int INFTY=20000000;
const int MAX=1000100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int nimber[MAX];
bool was[MAX];
int n,maxn,ns[MAX],maxnimber,ans[MAX];
bool prime[MAX];
void sieve(){
	loop(i,0,maxn+2){
		prime[i]=1;
		nimber[i]=0;
	}
	int j,k;
	loop(i,2,maxn){
		if(prime[i]){
			j=i*2;
			nimber[i]++;
			while(j<=maxn){
				k=j;
				while(k%i==0){
					nimber[j]++;
					k=k/i;
				}
				prime[j]=0;	
				j=j+i;
			}
		}
	}
}
int mex(){
	int i=0;
	while(was[i]){
		i++;	
	}
	return i;
}
void prepare(){
	ans[1]=0;
	ans[2]=1;
	maxnimber=2;
	loop(i,3,maxn){
		/*loop(j,0,maxnimber+3){
			was[j]=0;
		}
		was[nimber[1]]=1;
		loop(d,2,sqrt(i)){
			if(i%d==0){
				//cout<<i<<" "<<d<<"\n";
				was[nimber[i/d]]=1;
				was[nimber[d]]=1;
			}
		}
		//cout<<i<<" "<<nimber[i]<<" "<<mex()<<"\n";
		nimber[i]=mex();
		maxnimber=max(maxnimber,nimber[i]);
		//cout<<nimber[i]<<" ";*/
		ans[i]=ans[i-1] xor nimber[i];
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	int T,T2;
	cin>>T;
	T2=T;
	nimber[1]=0;
	nimber[2]=1;
	int i=0;
	while(T--){
		cin>>n;
		maxn=max(maxn,n);
		ns[i]=n;
		i++;		
	}
	sieve();
	prepare();
	loop(j,0,i-1){
		if(ans[ns[j]]!=0)
			cout<<"Pierwszy"<<"\n";
		else
			cout<<"Drugi"<<"\n";
	}
}
