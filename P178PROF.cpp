#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;

int main(void){
	while(1){
		int N;
		cin>>N;
		if(N == 0) return 0;
		int res = 1;
		while(N != 1){
			if(N % 2 == 0){
				res++;
				N /= 2;
			}
			else{
				res++;
				N = N * 3 + 1;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}

