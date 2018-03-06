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
bool color[MAX];
int N,Q,d=1;
void findTreeSize(){
	while(N--){
		d=d*2;
	}
}
void colour(int s,int e){
	loop(i,s,e){
		color[i]=1;
	}
}
int check(){
	int sum=0;
	loop(i,0,d){
		if(color[i])
			sum++;
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>N>>Q;
	findTreeSize();
	int X;
	//pln(d);
	int s,e;
	loop(z,1,Q){
		cin>>X;
		colour(X,X);
		s=2*X;
		e=2*X+1;
		while(s<d){
			colour(s,e);
			s=2*s;
			e=2*e+1;
		}
		cout<<check()<<"\n";	
	}
}
