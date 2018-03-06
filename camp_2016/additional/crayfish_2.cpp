#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
using namespace std;
const int INFTY=20000000;
const int MAX=317;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
bool row[MAX][3],column[MAX][3];
char board[MAX][MAX];
string b5[5],b6[6],b7[7];
int n;

void find(int size){
	if(size==5){
		loop(i,0,5){
			loop(j,0,5){
				board[(n-size)/2+i][(n-size)/2+j]=b5[i][j];
			}
		}
	}else if(size==6){
		loop(i,0,6){
			loop(j,0,6){
				board[(n-size)/2+i][(n-size)/2+j]=b6[i][j];
			}
		}
	}else if(size==7){
		loop(i,0,7){
			loop(j,0,7){
				board[(n-size)/2+i][(n-size)/2+j]=b7[i][j];
			}
		}	
	}else{
		find(size-6);
		loop(i,0,3){
			loop(j,0,size-6){
				//cout<<i+(n-size)/2<<" "<<j+(n-size)/2<<"\n";
				board[i+(n-size)/2][j+(n-size)/2]='.';
				board[size-i-1][j+(n-size)/2]='.';
			}
		}
		loop(i,0,size-6){
			loop(j,0,3){
				//cout<<i+(n-size)/2<<" "<<j+(n-size)/2<<"\n";
				board[i+(n-size)/2][j+(n-size)/2]='.';
				board[i+(n-size)/2][size-j-1]='.';
			}
		}
		loop(i,0,3){
			
			loop(j,0,3){
				cout<<i+(n-size)/2<<" "<<j+(n-size)/2<<"\n";
				board[i+(n-size)/2][j+(n-size)/2]=b6[i][j];
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	b5[0]="ra..k";
	b5[1]="k.ra.";
	b5[2]="a..kr";
	b5[3]=".kar.";
	b5[4]=".rk.a";
	b6[0]="rak...";
	b6[1]="k.r.a.";
	b6[2]="...akr";
	b6[3]=".r.k.a";
	b6[4]=".kar..";
	b6[5]="a...rk";
	b7[0]="rak....";
	b7[1]="k.r..a.";
	b7[2]="....akr";
	b7[3]=".r.k..a";
	b7[4]="..ark..";
	b7[5]=".k.ar..";
	b7[6]="a....rk";
	find(n);
	loop(i,0,n){
		loop(j,0,n){
			cout<<board[i][j];
		}
		cout<<"\n";
	}
}
