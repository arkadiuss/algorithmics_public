#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pd( x ) cout << x << "\n"
#define pcnt(i) __builtin_popcount(i)
#define ll long long
using namespace std;
const int INFTY=20000000;
const int MAX=500100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<"\n";
	}
	//cout<<"\n";
}
//------------------------------------------
int n;
int M,h[MAX],sq[MAX],maxi[MAX]; 
double sqt[MAX];
stack<int> A,S,Sp,Ap;
void countSq(){
	loop(i,0,n+1){
		sqt[i]=sqrt(i);
		sq[i]=ceil(sqt[i]);
	}
}
void findM(){
	M=0;
	loop(i,0,n){
		M=max(M,h[i]);
	}
}
int lightCon(int a,int b){
	return h[b]-h[a]+sq[abs(a-b)];
}
double lightConToBin(int a,int b){
	return ((double)h[b]-h[a])+sqt[abs(a-b)];
}
int findQ(int a,int b){
	int p=0,k=a;
	int s=(p+k+1)/2;
	while(p<k){
		if(lightConToBin(s,b)>=lightConToBin(s,a)){
			k=s-1;
		}else{
			p=s;
		}
		s=(p+k+1)/2;
	}
	return k;
}
void countR(){
	loopback(i,n-1,0){
		if(h[i]>=M-sq[n]&&(A.empty()||h[i]>h[A.top()])){
			while(!A.empty()&&findQ(i,A.top())>S.top()){	
				A.pop();
				S.pop();
			}
			if(!A.empty()){
				S.push(findQ(i,A.top()));
				A.push(i);
			}else{
				A.push(i);
				S.push(i);
			}	
		}
	}
	/*Ap=A;
	while(!Ap.empty()){
		cout<<Ap.top()<<" ";
		Ap.pop();
	}
	cout<<"\n";
	Sp=S;
	while(!Sp.empty()){
		cout<<Sp.top()<<" ";
		Sp.pop();
	}
	cout<<"\n";*/
	loop(i,0,n){
		while(!S.empty()&&S.top()<i){ S.pop();A.pop();}
		if(!S.empty()) maxi[i]=max(maxi[i],lightCon(i,A.top()));
	}
	while(!A.empty()){
		A.pop();
	}
	while(!S.empty()){
		S.pop();
	}
}
void countFirstAndLast(){
	loop(i,1,n){
		maxi[0]=max(maxi[0],lightCon(0,i));
	}
	loopback(i,n-2,0){
		maxi[n-1]=max(maxi[n-1],lightCon(n-1,i));
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){
		cin>>h[i];
	}
	countSq();
	findM();
	countFirstAndLast();
	countR();
	//coutTab(maxi,n);
	reverse(h,h+n);
	reverse(maxi,maxi+n);
	countR();
	reverse(maxi,maxi+n);
	coutTab(maxi,n);
}
