#include<bits/stdc++.h>

using namespace std;

#define  For(i, a, b)     for(int i = a; i <= b; i++)
#define  Ford(i, a, b)    for(int i = a; i >= b; i--)
#define  ll               long long
#define  here             cout<<"i am here"<<endl;
const long long base= 1e9 + 7;
const int maxn = 1000000;

stack <char> St;

int main(void){
	ios::sync_with_stdio(false);
	string c;
	while(1){
		getline(cin, c);
		string s = "";
		if(c[0] == '.') break;
		int n = c.length();
		For(i, 0, n - 1){
			if(c[i] == '(' || c[i] == ')' || c[i] == '[' || c[i] == ']'){
				s = s + c[i];
			}
		}
		if(s.length() % 2 != 0) cout<<"NO"<<endl;
		else{
			
		}
	}	
	return 0;
}

