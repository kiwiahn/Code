#include<bits/stdc++.h>

using namespace std;

#define  For(i, a, b)     for(int i = a; i <= b; i++)
#define  Ford(i, a, b)    for(int i = a; i >= b; i--)
#define  ll               long long
#define  here             cout<<"i am here"<<endl;
const long long base= 1e9 + 7;
const int maxn = 1000000;

int a[maxn],b[maxn],p[maxn],s[maxn];
int n,m;

int main(void){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	s[-1] = 0;
	s[0] = 0;
	For(i, 0, maxn) p[i] = 0;
	For(i, 1, n){
		cin>>a[i];
		p[a[i]]++;
	}
	For(i, 0, maxn) s[i] = s[i-1] + p[i];
	For(i, 1, m) cin>>b[i];
	
	For(i, 1, m){
		cout<<s[b[i]];
		cout<<endl;
	}
	return 0;
}

