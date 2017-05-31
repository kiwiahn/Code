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
	int n;
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		For(i, 1, n) cout<<i;
		Ford(i, n - 1, 1) cout<<i;
		cout<<endl;
	}	
	return 0;
}

