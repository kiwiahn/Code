#include<bits/stdc++.h>

using namespace std;

#define  For(i, a, b)     for(int i = a; i <= b; i++)
#define  Ford(i, a, b)    for(int i = a; i >= b; i--)
#define  ll               long long
#define  here             cout<<"i am here"<<endl;
const long long base= 1e9 + 7;
const int maxn = 1000000;

int n, l, a[maxn], res;

int main(void){
	ios::sync_with_stdio(false);
	cin>>n>>l;
	For(i, 1, n) cin>>a[i];
	sort(a+1, a+n+1);
	res = 2*max(a[1], l - a[n]);
	For(i, 2, n) res = max(res, a[i] - a[i-1]);
	printf("%.10f", (double) res/2);
	return 0;
}

