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

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
multiset<int,std::greater<int>> rs,cs;
multiset<int> ce,re;
struct k{
	int x1,x2,y1,y2;	
};
k ks[MAX];
int n;
pair<int,int> check(){
	loop(i,0,n){
		rs.erase(rs.find(ks[i].x1));
		cs.erase(cs.find(ks[i].y1));
		re.erase(re.find(ks[i].x2));
		ce.erase(ce.find(ks[i].y2));
		int x1=*rs.begin();
		int y1=*cs.begin();
		int x2=*re.begin();
		int y2=*ce.begin();
		if(y2>=y1&&x2>=x1){
			return {x1,y1};
		}
		rs.insert(ks[i].x1);
		cs.insert(ks[i].y1);
		re.insert(ks[i].x2);
		ce.insert(ks[i].y2);	
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){
		cin>>ks[i].x1>>ks[i].y1>>ks[i].x2>>ks[i].y2;
		rs.insert(ks[i].x1);
		cs.insert(ks[i].y1);
		re.insert(ks[i].x2);
		ce.insert(ks[i].y2);
	}
	pair<int,int> res = check();
	ps(res.ff);pln(res.ss);
}
