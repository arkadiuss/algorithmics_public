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
int old[MAX];
int howmanyoneven[MAX], howmanyonodd[MAX];
int maxeven,maxeven2,maxodd,maxodd2;
int imaxeven,imaxeven2,imaxodd,imaxodd2;
int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	loop(i,0,n){
		cin>>old[i];
	}
	loop(i,0,n){
		if(i%2==0){
			howmanyoneven[old[i]]++;
		}else{
			howmanyonodd[old[i]]++;
		}
	}
	maxeven=0;
	maxodd=0;
	maxeven2=0;
	maxodd2=0;
	imaxeven=-1;
	imaxodd=-1;
	imaxeven2=-1;
	imaxodd2=-1;
	loop(i,0,n+1){
		if(howmanyoneven[i]>maxeven){
			maxeven=howmanyoneven[i];
			imaxeven=i;
		}
		if(howmanyonodd[i]>maxodd){
			maxodd=howmanyonodd[i];
			imaxodd=i;
		}
	}
	loop(i,0,n+1){
		if(howmanyoneven[i]>maxeven2&&i!=imaxeven){
			maxeven2=howmanyoneven[i];
			imaxeven2=i;
		}
		if(howmanyonodd[i]>maxodd2&&i!=imaxodd){
			maxodd2=howmanyonodd[i];
			imaxodd2=i;
		}
	}
	int ans=0;
	if(imaxodd!=imaxeven){
		ans=n-(maxodd+maxeven);
	}else{
		ans=n-max(maxodd+maxeven2,maxodd2+maxeven);
	}
	cout<<ans;
}
