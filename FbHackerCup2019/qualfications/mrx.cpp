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
int split(string &exp, int s, int e) {
	int c = 0;
	for(int i = s+1; i < e-1; i++) {
		if(exp[i] == '(') {
			c++;
		} else if(exp[i] == ')') {
			c--;
		} else if(c==0 && (exp[i]=='&'||exp[i]=='|'||exp[i]=='^')) {
			return i;
		}
	}
	
	return -1;
}

char eval_and(char a, char b) {
	if((a=='x' && b == 'X')||(a=='X' && b == 'x')) return '0';
	if(a=='x' && b == 'x') return 'x';
	if(a=='X' && b == 'X') return 'X';
	if(b=='1') return a;
	if(a=='1') return b;
	return '0';
}

char eval_or(char a, char b) {
	if(a=='x' && b == 'x') return 'x';
	if(a=='X' && b == 'X') return 'X';
	if((a=='x' && b == 'X')||(a=='X' && b == 'x')) return '1';
	if(b=='0') return a;
	if(a=='0') return b;
	return '1';
}

char eval_xor(char a, char b) {
	if(a==b) return '0';
	if((a=='x' && b == 'X')||(a=='X' && b == 'x')) return '1';
	
	if(b == '0') return a;
	if(a == '0') return b;
	
	if(a=='x' || b=='x') return 'X';
	return 'x';
}

char eval(string &exp, int s, int e) {
	if(e-s<=1) return exp[s];
	int sp = split(exp, s, e);
	char a = eval(exp, s+1, sp);
	char b = eval(exp, sp+1, e-1);
	char op = exp[sp];
	if(op == '&') {
		return eval_and(a,b);
	} else if(op == '|') {
		return eval_or(a,b);
	} else {
		return eval_xor(a,b);
	}
}

int result(string &exp) {
	char res = eval(exp, 0, exp.size());
	if(res == 'x' || res == 'X') return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	int T;
	cin>>T;
	string s;
	for(int t=0;t<T;t++) {
		cin>>s;
		cout<<"Case #"<<t+1<<": "<<result(s)<<"\n";
	}
}
