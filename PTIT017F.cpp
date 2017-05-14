#include<bits/stdc++.h>

using namespace std;

#define  For(i, a, b)     for(int i = a; i <= b; i++)
#define  Ford(i, a, b)    for(int i = a; i >= b; i--)
#define  ll               long long
#define  here             cout<<"i am here"<<endl;
const long long base= 1e9 + 7;
const int maxn = 1000000;

int test1(string s){
	int t = (s[s.length() - 1] - 48) + (s[s.length() - 2] - 48) * 10;
	if(t % 4 != 0) return 0;
	return 1;
}
int test2(string s){
	int t = 0;
	For(i, 0, s.length() - 1){
		t = t + (s[i] - 48);
	}
	if(t % 9 == 0) return 1;
	return 0;
}
int main(void){
	ios::sync_with_stdio(false);
	string s;
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		if(test1(s) == 0) cout<<"NO"<<endl;
		else{
			if(test2(s) == 0) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
	}
	return 0;
}

