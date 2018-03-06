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
vector<int> num;
ll mod,nummax;
int B;
int a[MAX];
void coutNum(){
	loop(i,0,num.size()){
		cout<<num[i]<<"";
	}
	cout<<"\n";
}
void countMod(){
	mod=0;
	ll p=1;
	//ll p2=1;
	loop(i,0,num.size()){
		//nummax=nummax+num[i]*p2;
		mod=(mod+num[i]*p)%(B-1);
		p=(p*B)%(B-1);
		//p2=p2*B;
	}
}
void remA(int v){
	if(v>0){
		remA(v/B);
		a[v%B]--;
	}
}	
int main(){
	ios_base::sync_with_stdio(0);
	int q;
	cin>>B>>q;
	loop(i,0,B){
		cin>>a[i];
	}
	loop(i,0,B){
		loop(j,0,a[i]){
			num.pb(i);
		}
	}
	countMod();
	//coutNum();
	//pln(mod);
	remA(mod);
	vector<int> res;
	loop(i,0,B){
		loop(j,0,a[i]){
			res.pb(i);
		}
	}
	int k;
	while(q--){
		cin>>k;
		if(k>res.size()-1)
			pln(-1);
		else	
			pln(res[k]);
	}
}
