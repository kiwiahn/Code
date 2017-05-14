#include<bits/stdc++.h>

using namespace std;

#define  For(i, a, b)     for(int i = a; i <= b; i++)
#define  Ford(i, a, b)    for(int i = a; i >= b; i--)
#define  ll               long long
#define  here             cout<<"i am here"<<endl;
const long long base= 1e9 + 7;
const int maxn = 1000000;

int main(void){
	ios::sync_with_stdio(false);
	int n,x = 1;
	int a[100];
	while(1){
		cin>>n;
		if(n == 0) break;
		For(i, 1, n) cin>>a[i];
		int res = 0, test;
		while(1){
			test = 1;
			For(i, 1, n - 1){
				if(a[i + 1] == a[i]) test++;
				else break;
			}
			if(test == n){
				cout<<"Case "<<x<<": "<<res<<" iterations"<<endl;
				break;
			}
			if(res >= 1001){
				cout<<"Case "<<x<<": not attained"<<endl;
				break;
			}
			int key = a[1];
			For(i, 1, n - 1){
				a[i] = abs(a[i] - a[i+1]);
			}
			a[n] = abs(a[n] - key);
			res++;
		}
		x++;
	}	
	return 0;
}

