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
	int t;
	cin>>t;
	int res = 0;
	while(t--){
		int n = 3,y;
		For(i, 1, 3){
			cin>>y;
			if(y == 0) n--;
		}
		if(n >= 2) res++;
	}
	cout<<res;
	return 0;
}

