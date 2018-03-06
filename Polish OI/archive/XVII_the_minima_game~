#include<iostream>
#include<vector>
#include<algorithm>
#define loop(i,j,s) for(int i=j;i<s;i++)
using namespace std;
const int MAX=1000006;
int n;
int k[MAX];
int main(){
	cin>>n;
	loop(i,0,n){
		cin>>k[i];
	}
	sort(k,k+n);
	int result[MAX];
	result[0]=k[0];
	loop(i,1,n){
		result[i]=max(result[i-1],k[i]-result[i-1]);
	}
	cout<<result[n-1];
}
