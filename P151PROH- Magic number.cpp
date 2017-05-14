#include<bits/stdc++.h>

using namespace std;

#define  For(i, a, b)     for(int i = a; i <= b; i++)
#define  Ford(i, a, b)    for(int i = a; i >= b; i--)
#define  ll               long long
#define  here             cout<<"i am here"<<endl;
const long long base= 1e9 + 7;
const int maxn = 1000000;

int kt(int n){
	int a[10];
	int i=0,dem = 0;
	while(n != 0){
		a[i] = n%10;
		if(a[i] != 4 && a[i] != 1) return 0;
		if(a[i] == 4) dem++;
		if(dem > 2) return 0;
		if(a[i] != 4) dem = 0;
		n = n/10;
		i++;
	}
	if(a[i-1] == 4) return 0;
	return 1;
	
}

int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;	
	if(kt(n) == 1) cout<<"YES";
	else cout<<"NO";
	return 0;
}

