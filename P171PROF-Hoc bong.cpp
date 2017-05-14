#include<iostream>
#include<algorithm>
using namespace std;

long long a[1000000];
int n,dem=0;
long long s=0;

int main(void){
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++){
		if(a[i]>=s){
			dem++;
			s=s+a[i];	
		}
	}
	cout<<dem;
	return 0;
}

