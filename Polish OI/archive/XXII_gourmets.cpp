#include<iostream>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
using namespace std;
const int MAX=1000010;
int n;
double calories[MAX];
int ans[MAX];
int check(int i,int j){
	if(calories[i]>calories[j]){
		//calories[i]=calories[i]/2;
		return i;
	}else{
		//calories[j]=calories[j]/2;
		return j;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){
		cin>>calories[i];
	}
	loop(i,0,n-1){
		ans[i]=check(i,i+1);
	}
	ans[n-1]=check(n-1,0);
	loop(i,0,n){
		//cout<<ans[i]+1<<" ";
		calories[ans[i]]=calories[ans[i]]/2;
	}
	//cout<<endl;
	int j;
	loop(i,0,n-1){
		if(ans[i]==i)
			j=i+1;
		else
			j=i;	
		if(calories[ans[i]]*2<calories[j]){
			calories[ans[i]]=calories[i]*2;
			ans[i]=j;
			calories[ans[i]]=calories[j]/2;
		}
	}
	if(ans[n-1]==n-1)
		j=0;
	else
		j=n-1;	
	if(calories[ans[n-1]]*2<calories[j])
		ans[n-1]=j;
	loop(i,0,n){
		cout<<ans[i]+1<<" ";
	}
}

