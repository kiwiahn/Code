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
	int n, res = 0;
	cin>>n;
	string s[1000];
	For(i, 1, n){
		cin>>s[i];
		if(s[i] == "X++" || s[i] == "++X") res++;
		if(s[i] == "X--" || s[i] == "--X") res--;
	}	
	cout<<res;
	return 0;
}

