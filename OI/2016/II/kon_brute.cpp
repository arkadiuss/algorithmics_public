#include<bits/stdc++.h>
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i--)
#define VAR(i,c) __typeof(c) i=(c)
#define foreach(it,c) for(VAR(it,c.begin());it!=c.end();it++)
#define SIZE(c) c.size()
#define ALL(c) c.begin(), c.end()
#define ps(v) cout<<v<<" "
#define pln(v) cout<<v<<"\n"
#define entr cout<<"\n"
#define ll long long
#define pb push_back
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int MAX=1000100;
int n,k;
int hm[MAX];
int g;
struct que{
	int a,l,d;
};
que mq(int a, int l, int d){
	que q;
	q.a=a;
	q.l=l;
	q.d=d;
	return q;
}
vector<que> qs;
void addbrute(int a,int l, int d){
	for(int j=a-1;j<=a-1+(l-1)*d;j+=d){
		hm[j]++;
	}
}
void brute(){
	loop(i,0,SIZE(qs)){
		addbrute(qs[i].a,qs[i].l,qs[i].d);
	}
	loop(i,0,n){
		ps(hm[i]);
	}
}
int a[MAX];
void solveeq(){
	//pln("robie cudownie");
	loop(i,0,SIZE(qs)){
		a[qs[i].a-1]+=1;
		int pos=qs[i].a-1+qs[i].l*qs[i].d;
		if(pos<n)
			a[pos]--;
	}
	for(int i=0;i<qs[i].d;i++){
		int s=0;
		for(int j=i;j<n;j+=qs[i].d){
			s+=a[j];
			hm[j]+=s;
		}
	}
	loop(i,0,n){
		ps(hm[i]);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	int k;
	cin>>n>>k;
	g=ceil(sqrt(n));
	int a,l,d;
	bool eq=1;
	loop(i,0,k){
		cin>>a>>l>>d;
		if(i>0) eq=eq&&(d==qs[0].d);
		qs.pb(mq(a,l,d));
	}
	if(eq&&d<g){
		solveeq();
	}else{
		brute();
	}
	return 0;
}

