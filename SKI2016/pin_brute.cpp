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
const int MAX=500100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int nums[MAX];
int n;
int sumNum(){
	int sum=0;
	loop(i,0,n){
		if(i%2==0)
			sum=sum+nums[i];
		else
			sum=sum-nums[i];	
	}
	return sum;
}
bool check(){
	loop(i,0,n){
		loop(j,i+1,n){
			swap(nums[i],nums[j]);
			if(sumNum()==0)
				return 1;
			swap(nums[i],nums[j]);
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	int T;
	cin>>T;
	string s;
	while(T--){
		cin>>s;
		n=s.size();
		loop(i,0,s.size()){
			nums[i]=s[i]-'0';
		}
		if(check())
			cout<<"TAK";
		else
			cout<<"NIE";
		entr;	
	}
}
