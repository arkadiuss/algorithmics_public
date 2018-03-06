#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i--)
#define foreach(i,c) for(VAR(i,c.begin());i!=c.end();i++)
#define ALL(c) c.begin(), c.end()
#define SIZE(c) c.size()
#define ps(v) cout<<v<<" "
#define pln(v) cout<<v<<"\n"
#define entr cout<<"\n"
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
const int MAX=1000100;
const int MOD=1000000000;
const int INFTY=1000000000;
typedef vector<int> VI;

void coutTab(int * tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//---------------------------------
int num[MAX];
int size=1;
void mul2(){
	int f=0;
	loop(i,0,size){
		num[i]=2*num[i]+f;
		f=num[i]/10;
		num[i]=num[i]%10;
	}
	if(f!=0){
		num[size]=f;
		size++;
	}
}
void add1(){
	int f=1;
	loop(i,0,size){
		num[i]=num[i]+f;
		f=num[i]/10;
		num[i]=num[i]%10;
	}
	if(f!=0){
		num[size]=f;
		size++;
	}
}
void remove1(){
	int i=0;
	while(num[i]==0){
		num[i]=9;
		i++;
	}
	num[i]--; 
	if(i==size-1&&num[i]==0) size--;
}
int main(){
	ios_base::sync_with_stdio(0);
	int t,c;
	ll wyn=0;
	cin>>t;
	num[0]=0;
	loop(i,0,t-1){
		if(i%2==0){
			mul2();add1();
		}else if(i%2==1){
			mul2();remove1();
		}
	}
	loopback(i,size-1,0){
		cout<<num[i];
	}
}
