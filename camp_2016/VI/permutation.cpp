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
const int MAX=12;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,1,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int size=1,n;
int perm[MAX];
int p=29;
bool was[10000000]={0};
int power(){
	loop(i,1,n){
		size=size*i;
	}
}
bool check(){
	int sum=0;
	loop(i,1,n){
		sum=sum*p+perm[i];
	}
	if(was[sum])
		return 0;
	was[sum]=1;	
	return 1;		
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,1,n){
		cin>>perm[i];
		//perm[i]--;
	}
	int j=2;
	power();
	
	loop(i,1,size){
		bool checked=0;
		//if(!check()){
		//	next_permutation(perm,perm+n);
		//if(!check()) cout<<"was - ";
		//}
		//if(perm[1]==1&&perm[2]==2&&perm[3]==3&&perm[4]==4&&i>1){
		//	swap(perm[n],perm[1]);
		//	swap(perm[2],perm[3]);
		//}
		coutTab(perm,n);
		if(i%(size/n)==0&&i!=1&&i!=size){
			int k=2;
			while(perm[k]!=(i/(size/n)+1)){
				//cout<<i/(size/n)+1<<" "<<k<<" "<<perm[k]<<"\n";
				k++;
			
			}
			//cout<<i/(size/n)+1<<" "<<k<<" "<<perm[k]<<"\n";
			swap(perm[1],perm[k]);
			//break;
		}else{
			j++;
			if(j>n)
				j=3;
			swap(perm[2],perm[j]);
		}
		
	}
}
