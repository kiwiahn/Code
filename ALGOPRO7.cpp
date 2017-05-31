#include<bits/stdc++.h>

using namespace std;

#define For(i, a, b)    for(int i = a; i <= b; i++)
#define Ford(i, a, b)   for(int i = a; i >= b; i--)
#define ll              long long
#define here            cout<<"I am here"<<endl;
const int base = 1e9 + 7;
const int maxn = 1000000;

int main(void){
	ios::sync_with_stdio(false);
	int n, k;
	cin>>n>>k;
	int a[100000];
	For(i, 0, n - 1) cin>>a[i];
	sort(a, a + n);
	cout<<a[k];
	return 0;
}
