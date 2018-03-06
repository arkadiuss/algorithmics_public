#include<bits/stdc++.h>
#define loop(i,j,s) for(ll i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
using namespace std;
const int INFTY=20000000;
const int MAX=1000100;
const ll MOD=1000000009;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
ll q;
ll sq5=383008016;
string m;
ll mmod;
void createMMod(){
	mmod=0;
	loop(i,0,m.size()){
		mmod=((mmod*10)%MOD+(m[i]-'0'))%MOD;
	}
}
ll power(ll a,ll n){
	if(n==1)
		return a;
	if(n%2==0){
		a=power(a,n/2);
		return (a*a)%MOD;
	}
	return (power(a,n-1)*a)%MOD;		
}
ll modularmultiplicativeinverse(ll a){
	return power(a,MOD-2);	
}

ll sumF(ll n){
	ll sum=0,sumB=0,sumC=0,mmm;
	ll b=(1+sq5);
	ll c=(sq5-1);
	//cout<<b<<" "<<c<<"\n";
	
	//pln(mmm);
	ll B=(power(b,n)*modularmultiplicativeinverse(power(2,n)))%MOD;
	ll C=(power(c,n)*modularmultiplicativeinverse(power(-2,n)))%MOD;
	//cout<<B<<" "<<C<<"\n";
	//pln(mmm);
	if(B==1)
		sumB=mmod*B;
	else
		sumB=((power(B,mmod+1)-1)*modularmultiplicativeinverse(B-1))%MOD;
	//pln(sumB);
	if(C==1)
		sumC=mmod*C;
	else
		sumC=((power(C,mmod+1)-1)*modularmultiplicativeinverse(C-1))%MOD;
	//pln(sumC);
	sum=(sumB-sumC)%MOD;
	sum=(sum*modularmultiplicativeinverse(sq5))%MOD;
	//entr;
	if(sum<0)
		sum=sum+MOD;
	return sum;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>q>>m;
	ll n;
	createMMod();
	//pln(mmod);
	loop(i,0,q){
		cin>>n;
		cout<<sumF(n)<<"\n";	
	}
}
