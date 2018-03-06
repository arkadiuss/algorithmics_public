#include<bits/stdc++.h>
using namespace std;

const int N=2000;

struct BigNum{
	int n[N];
	BigNum(string s){
		for(int i=0;i<N;i++){
			n[i]=0;
		}
		for(int i=0;i<s.size();i++){
			n[i]=s[s.size()-1-i]-48;
		}
	};
	
	BigNum(){
		BigNum("0");
	};
	
	BigNum operator+(const BigNum & a){
		BigNum r("0");
		int d=0;
		for(int i=0;i<N;i++){
			r.n[i]=n[i]+a.n[i]+d;
			d=r.n[i]/10;
			r.n[i]%=10;
		}
		return r;
	}
	
	bool operator=(const BigNum & a){
		for(int i=0;i<N;i++){
			n[i]=a.n[i];
		}
		return 1;
	}
	
	BigNum operator*(const BigNum & a){
		BigNum r("0"), mr("0"), tr("0");
		for(int i=0;i<N;i++){
			int d=0;
			for(int j=0;j<N;j++){
				mr.n[i+j]=n[i]*a.n[j]+d;
				d=mr.n[i+j]/10;
				mr.n[i+j]%=10;
			}
			r=r+mr;
			mr=tr;
		}
		return r;
	}
	
	BigNum operator*(const int & a){
		BigNum r("0");
		int d=0;
		for(int i=0;i<N;i++){
			r.n[i]=n[i]*a+d;
			d=r.n[i]/10;
			r.n[i]%=10;
		}
		return r;
	}
};
int n,m,k;
BigNum aq[12][12];
int newton[12][12];

int main(){
	string qt,at;
	cin>>n>>qt>>k>>m;
	BigNum q(qt),r,e,e1("1");
	BigNum a[12];
	newton[1][0]=1;
	newton[1][1]=1;
	for(int i=2;i<12;i++){
		newton[i][0]=1;
		for(int j=1;j<=i;j++){
			newton[i][j]=newton[i-1][j]+newton[i-1][j-1];
		}
	}
	for(int i=n;i>=0;i--){
		cin>>at;
		BigNum att(at);
		a[i]=att;
		aq[i][0]=a[i];
		for(int j=1;j<=n;j++){
			aq[i][j]=aq[i][j-1]*q;
		}
	}
	for(int i=n;i>=0;i--){
		r=r*q+a[i];
	}
	while(k--){
		int s=0;
		for(int i=0;i<m;i++){
			s+=r.n[i]*r.n[i];
		}
		cout<<s<<"\n";
		r=e;
		for(int i=n;i>0;i--){
			q=e;
			for(int j=i;j>=0;j--){
				q=q+aq[i][j]*newton[i][i-j];
			}
			r=r+q;
			aq[i][i]=q;
			for(int j=i-1;j>0;j--){
				q=e;
				for(int k=j;k>=0;k--)
					q=q+aq[i][k]*newton[j][j-k];
				aq[i][j]=q;
			}
			
		}
		r=r+a[0];
	}
} 
