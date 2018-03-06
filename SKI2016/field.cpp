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
const int MAX=305000;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int num[MAX];
int res[MAX];
int n;
void divideBy2(){
	res[0]=num[0]/2;
	num[0]=num[0]%2;
	loop(i,1,n){
		res[i]=(num[i-1]*10+num[i])/2;
		num[i]=(num[i-1]*10+num[i])%2;
	}
	if(res[0]==0){
		loop(i,0,n-1){
			num[i]=res[i+1];
		}
		n--;
	}else{
		loop(i,0,n){
			num[i]=res[i];
		}
	}
	//coutTab(num,n);
}
bool check(){
	while(num[n-1]%2==0&&(n>1||(n==1&&num[0]%2==0))){
		divideBy2();
	}
	if((num[0]==1||num[0]==5)&&n==1) return 1;
	return 0;
}
int main(){
	ios_base::sync_with_stdio(0);
	int T;
	string A;
	cin>>T;
	while(T--){
		cin>>A;
		n=A.size();
		loop(i,0,A.size()){
			num[i]=A[i]-'0';
		}
		//coutTab(num,n);
		if(check()) cout<<"TAK";
		else cout<<"NIE";
		entr;
	}
}
