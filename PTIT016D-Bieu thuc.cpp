#include<iostream>
#include<algorithm>

using namespace std;
const int maxn=100000;
long long a[maxn];

bool cmp(int a,int b){
	return a>b;
}

int main(void){
	long long n;
	long long k;
	long long s=0;
	cin>>n;
	cin>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+2,a+n+1,cmp);
	
	for(int i=1;i<=k+1;i++){
		s=(long long )(s+a[i]);
	}
	for(int i=k+2;i<=n;i++){
		s=(long long) (s-a[i]);
	}
	
	cout<<s;
	return 0;
}

