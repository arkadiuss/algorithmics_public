#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define foreach(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define SIZE(c) (c).size()
#define ALL(c) (c).begin(), (c).end()
using namespace std;
typedef vector<int> VI;
const int INFTY=20000000;
const int MAX=500100;
const int MOD=10000000;
typedef vector<vector<char> > VVC;
void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int n,m;
VVC M;
pair<int, vector<char> >  forRow(int i ,char a, char b){
	int s1=0,s2=0;
	loop(j,0,m){
		if(j%2==0){
			if(M[i][j]!=a) s1++;
			if(M[i][j]!=b) s2++;
		}else{
			if(M[i][j]!=b) s1++;
			if(M[i][j]!=a) s2++;
		}
	}
	vector<char> res;
	if(s1<s2){
		loop(j,0,m){
			if(j%2==0)
				res.pb(a);
			else
				res.pb(b);
		}
	}else{
		loop(j,0,m){
			if(j%2==0)
				res.pb(b);
			else
				res.pb(a);
		}
	}
	return { min(s1,s2), res };
}
pair<int, vector<char> > forCol(int j ,char a, char b){
	int s1=0,s2=0;
	loop(i,0,n){
		if(i%2==0){
			if(M[i][j]!=a) s1++;
			if(M[i][j]!=b) s2++;
		}else{
			if(M[i][j]!=b) s1++;
			if(M[i][j]!=a) s2++;
		}
	}
	vector<char> res;
	if(s1<s2){
		loop(i,0,n){
			if(i%2==0)
				res.pb(a);
			else
				res.pb(b);	
		}
	}else{
		loop(i,0,n){
			if(i%2==0)
				res.pb(b);
			else
				res.pb(a);
		}
	}
	return { min(s1,s2), res };
}
pair<int, VVC> countForRows(char a, char b, char c, char d){
	int s1=0,s2=0;
	pair<int, vector<char> > ret;
	VVC res1, res2;
	loop(i,0,n){
		if(i%2==0){
			ret = forRow(i,a,b);
			s1+=ret.ff;
			res1.pb(ret.ss);
			ret = forRow(i,c,d);
			s2+=ret.ff;
			res2.pb(ret.ss);
		}else{
			ret=forRow(i,c,d);
			s1+=ret.ff;
			res1.pb(ret.ss);
			ret=forRow(i,a,b);
			s2+=ret.ff;
			res2.pb(ret.ss);
		}
	}
	if(s1<s2)
		return {s1,res1};
	return {s2,res2};
}
pair<int, VVC> countForCols(char a, char b, char c, char d){
	int s1=0,s2=0;
	pair<int, vector<char> > ret;
	VVC res1(n), res2(n);
	loop(j,0,m){
		if(j%2==0){
			ret=forCol(j,a,b);
			s1+=ret.ff;
			loop(i,0,n) res1[i].pb(ret.ss[i]);
			ret=forCol(j,c,d);
			s2+=ret.ff;
			loop(i,0,n) res2[i].pb(ret.ss[i]);
		}else{
			ret=forCol(j,c,d);
			s1+=ret.ff;
			loop(i,0,n) res1[i].pb(ret.ss[i]);
			ret=forCol(j,a,b);
			s2+=ret.ff;
			loop(i,0,n) res2[i].pb(ret.ss[i]);
		}
	}
	if(s1<s2)
		return {s1,res1};
	return {s2,res2};
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	M = vector<vector<char> >(n, vector<char>(m));
	loop(i,0,n){
		loop(j,0,m) cin>>M[i][j];
	}
	pair<int, VVC> res[] = {
		countForRows('A','G','C','T'),
		countForRows('A','C','G','T'),
		countForRows('A','T','C','G'),
		countForRows('G','C','A','T'),
		countForRows('G','T','A','C'),
		countForRows('C','T','A','G'),
		countForCols('A','G','C','T'),
		countForCols('A','C','G','T'),
		countForCols('A','T','C','G'),
		countForCols('G','C','A','T'),
		countForCols('G','T','A','C'),
		countForCols('C','T','G','A'),
	};
	int mini=res[0].ff;
	int minii = 0;
	loop(i,0,12){
		if(res[i].ff<mini){
			minii=i;
			mini=res[i].ff;
		}
	}
	loop(j,0,n){
		loop(k,0,m){
			cout<<res[minii].ss[j][k];
		}
		entr;
	}	
}
