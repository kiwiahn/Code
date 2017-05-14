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
	int n;
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int s=0;
		while(n >= 10){
			s = 0;
			while(n!=0){
				s = s + n%10;
				n/= 10;
			}
			n = s;
		}
		cout<<n<<endl;
	}	
	return 0;
}

