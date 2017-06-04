#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;
int const basic = 1e6;

int main(void){
	while(1){
		int N;
		cin>>N;
		if(N == 0) return 0;
		if(N <= basic){
			cout<<N<<endl;
		}
		if(N > basic && N <= 5 * basic){
			N = N - N / 10;
			cout<<N<<endl;
		}
		if(N > 5 * basic){
			N = N - N / 5;
			cout<<N<<endl;
		}
	}
	return 0;
}

