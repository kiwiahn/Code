#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;

int main(void){
	string s;
	cin>>s;
	For(i, 0, s.length() - 1){
		if(s[i] < 96){
			s[i] += 32;
		}
		if(s[i] != 'u' && s[i] != 'e' && s[i] != 'o' && s[i] != 'a' && s[i] != 'i' && s[i] != 'y'){
			cout<<"."<<s[i];
		}
	}
	return 0;
}

