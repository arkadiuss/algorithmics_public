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
typedef pair<int, int> PII;
typedef vector<vector<int> > VVI;
const int INFTY=20000000;
const int MAX=500100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}

template<class T> void coutVec(vector<T> tab){
	for(T t : tab){
		cout<<t<<" ";
	}
	cout<<"\n";
}

template<class T> void coutSet(multiset<T> tab){
	for(T t : tab){
		cout<<t<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
void addToSets(multiset<int> & A,multiset<int> & D, int a) {
	if(A.size() == 0) {
		A.insert(a);
		return;
	}
	auto next_it = A.lower_bound(a);
	if(next_it == A.begin()) {
		int next = *next_it;
		D.insert(next-a);
	} else if(next_it == A.end()){
		int prev = *(--next_it);
		D.insert(a-prev);
	} else {
		int next = *next_it;
		int prev = *(--next_it);
		D.erase(D.find(next-prev));
		D.insert(next-a);
		D.insert(a-prev);
	}
	A.insert(a);
}

void eraseFromSets(multiset<int> & A,multiset<int> & D, int a) {
	if(A.size() == 1) {
		A.erase(A.find(a));
		return;	
	}
	auto cur_it = A.lower_bound(a);
	if(cur_it == A.begin()) {
		int next = *(++cur_it);
		D.erase(D.find(next-a));
	} else {
		auto next_it = next(cur_it);
		int next = *(next_it);
		int prev = *(--cur_it);
		if(next_it == A.end()) {
			D.erase(D.find(a-prev));
		} else {
			D.erase(D.find(a-prev));
			D.erase(D.find(next-a));
			D.insert(next-prev);			
		}
	}
	A.erase(A.find(a));
}
void answer(multiset<int> & A,multiset<int> & D) {
	if(A.size()>1) {
		pln((*A.rbegin())-(*A.begin())-(*D.rbegin()));
	} else {
		pln(0);
	} 	
}
int main(){
	ios_base::sync_with_stdio(0);
	int n,q;
	cin>>n>>q;
	VI a(n);
	loop(i,0,n) cin>>a[i];
	sort(ALL(a));
	multiset<int> A, D;
	A.insert(a[0]);
	loop(i,1,n) {
		A.insert(a[i]);
		D.insert(a[i]-a[i-1]);
	}
	int t,x;
	//coutSet(A);
	//coutSet(D);
	answer(A, D);
	while(q--) {
		cin>>t>>x;
		if(t==0) {
			eraseFromSets(A, D, x);
		} else {
			addToSets(A, D, x);
		}
		answer(A, D);
	}
}
