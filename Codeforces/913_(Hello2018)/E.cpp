#include<bits/stdc++.h>
#include <unistd.h>
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
const int MAX=520;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
string states[MAX];
char lastOperation[MAX];
int n=256;

int empty_state(){
	int e=0;
	loop(i,0,256){
		if(states[i].size()==0) e++;
	}
	return e;
}
bool lowers(string a, string b){
	if(a==b) return false;
	if(a.size()<b.size()) return true;
	else if(b.size()<a.size()) return false;
	int j=0;
	while(a[j]==b[j]) j++;
	if(j==SIZE(a)) return false;
	if(a[j]<b[j]) return true;
	return false;
}
int NOT(int a){
	return 255-a;
}
string neg(int i){
	if(lastOperation[i]=='|'||lastOperation[i]=='&')
		return "!("+states[i]+")";
	else
		return "!"+states[i];	
}
string checkOr(int i){
	if(lastOperation[i]=='|')
		return "("+states[i]+")";
	else 
		return states[i];
}
void count(){
	states[15]="x";
	states[51]="y";
	states[85]="z";
	bool changed=true;
	while(changed){
		changed=false;
		string con="";
		loop(i,0,n){
			if(states[i].size()!=0){
				con=neg(i);
				if(states[NOT(i)].size()==0||lowers(con,states[NOT(i)])){
					changed=true;
					//ps(NOT(i));ps(states[NOT(i)]);pln(con);
					states[NOT(i)]=con;
					
					lastOperation[NOT(i)]=' ';
				}	
			}
		}
		loop(i,0,n){
			loop(j,0,n){
				if(states[i].size()!=0 && states[j].size()!=0){
					loop(k,0,4){
						con="";
						int res;
						if(k==0){
							con=states[i]+"|"+states[j];
							res=i|j;
						}else if(k==1){
							con=neg(i)+"|"+states[j];
							res=NOT(i)|j;
						}else if(k==2){
							con=states[i]+"|"+neg(j);
							res=i|NOT(j);
						}else if(k==3){
							con=neg(i)+"|"+neg(j);
							res=NOT(i)|NOT(j);
						}
						if(states[res].size()==0||lowers(con,states[res])){
							changed=true;
							//ps((i|j));ps(states[i|j]);ps(con);
							//ps((states[i|j].size()==0));pln(lowers(con,states[i|j]));
							states[res]=con;
							lastOperation[res]='|';
						}
						//if(i==15&&j==17){ps((i|j));ps(con);pln(states[i|j]);}
						if(k==0){
							con="";
							con=checkOr(i);
							con+="&";
							con+=checkOr(j);
							res=i&j;
						}else if(k==1){
							con="";
							con=neg(i);
							con+="&";
							con+=checkOr(j);
							res=NOT(i)&j;
						}
						else if(k==2){
							con="";
							con=checkOr(i);
							con+="&";
							con+=neg(j);
							res=i&NOT(j);
						}
						else if(k==3){
							con="";
							con=neg(i);
							con+="&";
							con+=neg(j);
							res=NOT(i)&NOT(j);
						}	
						if(states[res].size()==0||lowers(con,states[res])){
							changed=true;
							//ps((i&j));ps(states[i&j]);ps(con);
							//ps((states[(i&j)].size()==0));pln(lowers(con,states[i&j]));
							states[res]=con;
							lastOperation[res]='&';
						}
						//if(i==15&&j==17){ps((i&j));ps(con);pln(states[i&j]);}			
					}
				}	
			}
		}
		//pln(states[NOT(17)]);	
		//usleep(1000000);
	}
}
int toDec(string a){
	int p2=1;
	int s=0;
	loopback(i,SIZE(a)-1,0){
		s+=(a[i]-'0')*p2;
		p2*=2;
	}
	return s;
}
int main(){
	ios_base::sync_with_stdio(0);
	loop(i,0,n){ 
		states[i]="";
		lastOperation[i]=' ';
	}
	count();
	int q;
	string a;
	cin>>q;
	while(q--){
		cin>>a;
		pln(states[toDec(a)]);
	}
	
}
