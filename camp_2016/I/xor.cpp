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
int n,x,howManyxor=0;
int a[MAX];bool xored[MAX]={0};
int main(){
	ios_base::sync_with_stdio(0);
	srand(time(NULL));
	cin>>n>>x;
	loop(i,0,n) cin>>a[i];
	
	loop(i,1,n){
		if(a[i]<a[i-1]){
			if((a[i] xor x) < a[i]){
				int j=i;
				while(j>1&&a[j]<a[j-1]&&!xored[j-1]){
					a[j-1]= (a[j-1] xor x);
					xored[j-1]=1;
					j--;
				}
			}else{
				if((a[i] xor x)<a[i-1]){
					int j=i;
					while(j>1&&a[j]<a[j-1]){
						a[j-1]= (a[j-1] xor x);
						xored[j-1]=1;
						j--;
					}
				}else if(i>1&&(a[i-1] xor x)>=a[i-2]&&(a[i-1] xor x)<=a[i]){	
				 	a[i-1]=(a[i-1] xor x);
				 	xored[i-1]=1;
				}else{
					a[i] =(a[i] xor x);
					xored[i]=1;
				}
			}	
		}	
	}
	loop(i,1,n-1){
		if(xored[i-1]||xored[i+1]){
			if((a[i] xor x)>=a[i]&&(a[i] xor x)<=a[i+1])
				a[i]=a[i] xor x; 
		}
	}
	loop(i,0,n-1){
		if(xored[i]&&!xored[i+1])
			howManyxor++;
	}
	
	if(xored[n-1])
		howManyxor++;
	//loop(i,0,n) cout<<xored[i];
	//cout<<"\n";
	cout<<howManyxor<<"\n";
	//loop(i,0,n) cout<<a[i]<<" ";
	
}
