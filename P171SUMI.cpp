#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;

int Solution(char Str[],int n){
	int res = 0;
	int i = 0;
	while(i < n - 1){
		if(Str[i] != Str[i + 1]){
			res++;
			i++;
		}
		if(Str[i] == Str[i + 1]) i += 2;
		if(i == n - 1) res++;
	}
	if(res > 3) return 0;
	return 1;
}

int main(void){
	int Test;
	cin>>Test;
	while(Test--){
		char Str[100001];
		cin>>Str;
		int n = strlen(Str);
		sort(Str, Str + n);
		if(Solution(Str, n) == 1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

