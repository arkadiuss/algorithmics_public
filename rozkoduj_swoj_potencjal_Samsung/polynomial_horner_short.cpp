#include<iostream>
using namespace std;
const int N=150;
#define l(i,j,n) for(int i=j;i<n;i++)
#define lb(i,n,j) for(int i=n;i>=j;i--)
#define op operator
#define dm(i) d=r.n[i]/10000000LL;r.n[i]%=10000000LL;
#define cs const B & a
struct B{
	long long n[N],d;
	B(string s){
		l(i,0,N)
			n[i]=0;
		d=1;
		l(i,0,s.size()){
			n[i/7]=n[i/7]+(s[s.size()-1-i]-48)*d;
			d*=10;
			if(d==1e7) d=1;
		}	
	}
	
	B(){
		B("0");
	}
	
	B op+(cs){
		B r("0");
		d=0;
		l(i,0,N){
			r.n[i]=n[i]+a.n[i]+d;
			dm(i);
		}
		return r;
	}
	
	void op=(cs){
		l(i,0,N)
			n[i]=a.n[i];
	}
	
	B op*(cs){
		B r("0"), mr("0"), tr("0");
		l(i,0,N){
			d=0;
			l(j,0,N){
				r.n[i+j]=n[i]*a.n[j]+d;
				dm(i+j);
			}
			mr=mr+r;
			r=tr;
		}
		return mr;
	}
};
int n,m,k,s;

string qt,at;
int main(){
	cin>>n>>qt>>k>>m;
	B a[12],q(qt),r,e,e1("1");
	lb(i,n,0){
		cin>>at;
		B att(at);
		a[i]=att;
	}
	while(k--){
		r=e;
		lb(i,n,0){
			r=r*q+a[i];
		}
		s=0;
		l(i,0,m){
			s+=(r.n[i/7]%10)*(r.n[i/7]%10);
			r.n[i/7]/=10;
		}
		cout<<s<<"\n";
		q=q+e1;
	}
} 
