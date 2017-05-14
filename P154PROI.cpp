#include<bits/stdc++.h>

using namespace std;

#define  For(i, a, b)     for(int i = a; i <= b; i++)
#define  Ford(i, a, b)    for(int i = a; i >= b; i--)
#define  ll               long long
#define  here             cout<<"i am here"<<endl;
const long long base= 1e9 + 7;
const int maxn = 1000000;

int cmp(string s, string x){
	For(i, 1, s.length() - 1){
		if(abs(s[i] - s[i-1]) != abs(x[i] - x[i-1])) return 0;
	}
	return 1;
}

int main(void){
	ios::sync_with_stdio(false);
	int t;
	string s, x="";
	cin>>t;
	while(t--){
		x="";
		cin>>s;
		Ford(i, s.length() - 1, 0){
			x = x + s[i];
		}
		if(cmp(s, x) == 1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

