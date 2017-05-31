#include<bits/stdc++.h>

using namespace std;

#define  For(i, a, b)     for(int i = a; i <= b; i++)
#define  Ford(i, a, b)    for(int i = a; i >= b; i--)
#define  ll               long long
#define  here             cout<<"i am here"<<endl;
const long long base= 1e9 + 7;
const int maxn = 1000000;
char s[1010];
int main(void){
	ios::sync_with_stdio(false);
	int k;
	int t;
	cin>>t;
	while(t--){
		cin>>k>>s;
		int n = strlen(s);
		printf("%d ", k);
		if(next_permutation(s, s + n)){
			puts(s);
		}
		else puts("BIGGEST");
	}
	return 0;
}


