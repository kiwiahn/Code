#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;

int main(void){
	int t;
	cin>>t;
	while(t--){
		char s[105];
		cin>>s;
		int n = strlen(s);
		if(next_permutation(s, s + n)) cout<<s<<endl;
		else cout<<"BIGGEST"<<endl;
	}
	return 0;
}

