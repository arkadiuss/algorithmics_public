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
#define mp make_pair
using namespace std;
const int MAX=500100;
const int MOD=1000000000;
const int INFTY=1000000000;
typedef vector<int> VI;
typedef pair<int,int> PII;
void coutTab(int * tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//---------------------------------
int n;
struct val{
	int od,nw;
	int i;
};
val vs[MAX];
bool toSort1(val a, val b){
	return a.od<b.od;
}
bool toSort2(val a, val b){
	return a.i<b.i;
}
void coutVal(){
	loop(i,0,n){
		ps(vs[i].od);pln(vs[i].nw);
	}
}
int k=0;
int hml[MAX];
int D;
int tree[3*MAX];
int treeI[3*MAX];
void countD(){
	D=1;
	while(D<n) D*=2;
}
void createTree(){
	loop(i,D,2*D) treeI[i]=i-D;
	loopback(i,D-1,1) treeI[i]=treeI[2*i];
}
void update(int i, int v){
	i=i+D;
	tree[i]+=v;
	i/=2;
	while(i>0){
		tree[i]=max(tree[2*i],tree[2*i+1]);
		if(tree[2*i]>=tree[2*i+1])
			treeI[i]=treeI[2*i];
		else
			treeI[i]=treeI[2*i+1];	
		i=i/2;
	}
}
PII read(int L,int R){
	L=L+D;
	R=R+D;
	int v=0;
	int vi=0;
	while(L<R){
		if(L%2==1){
			if(tree[L]>v)
				vi=treeI[L];
			v=max(v,tree[L]);
		}
		if(R%2==0){
			if(tree[R]>v)
				vi=treeI[R];
			v=max(v,tree[R]);
		}
		L=(L+1)/2;
		R=(R-1)/2; 
	}
	if(L==R){
		if(tree[L]>v)
			vi=treeI[L];
		v=max(v,tree[L]);	
	}
	return mp(vi,v);
}
int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
int main(){
	ios_base::sync_with_stdio(0);
	n=readInt();
	loop(i,0,n){
		vs[i].od=readInt();;
		vs[i].i=i;
	}
	sort(vs,vs+n,toSort1);
	//coutVal();
	
	loop(i,0,n){
		int j=i;
		while(j<n&&vs[i].od==vs[j].od){
			vs[j].nw=k;
			j++;
		}
		i=j-1;
		k++;
	}
	sort(vs,vs+n,toSort2);
	//coutVal();
	countD();
	createTree();
	loop(i,0,n){
		update(vs[i].nw,1);
		PII res=read(0,D);
		if(res.ss>=(i+2)/2){
			hml[res.ff]++;
			if(hml[res.ff]>=(n+2)/2) break;
		}
		//ps(res.ff);pln(res.ss);
		//coutTab(tree,2*D);	
	}
	//coutTab(hml,n);
	int nw=-1;
	loop(i,0,n){
		if(hml[i]>=(n+2)/2){
			nw=i;
			break;
		}
	}
	if(nw==-1) pln("NIE");
	else{
		loop(i,0,n){
			if(vs[i].nw==nw){
				pln(vs[i].od);
				break;
			}
		}
	}
}
