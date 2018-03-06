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
ll change(int i,int p){
	ll sum=0;
	ll b=1;
	while(i>0){
		sum=sum+(i%10)*b;
		i=i/10;
		b=b*p;
	}
	return sum;
}
int maxInNum(int i){
	int maxi=0;
	while(i>0){
		maxi=max(maxi,i%10);
		i=i/10;
	}
	return maxi;
}
bool check(int l,int p){
	if(l>=p) return true;
	loop(i,2,11){
		if(i>maxInNum(p)){
			if(change(p,i)<=l)
				return true;
		}
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(0);
	int l,p;
	cin>>p>>l;
	if(check(l,p)) cout<<"Tak";
	else cout<<"Nie";
}
