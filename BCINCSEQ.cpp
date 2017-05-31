#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;

int Ar[maxn];

int main(void){
	int N;
	cin>>N;
	For(i, 1, N){
		cin>>Ar[i];
	}
	if(N == 1){
		cout<<"1";
		return 0;
	}
	int res = 1, maxs = 0;
	For(i, 2, N){
		if(Ar[i] > Ar[i-1]){
			res++;
		}
		if(Ar[i] < Ar[i - 1]){
		if(res > maxs) maxs = res;
			res = 1;
		}
	}
	cout<<maxs;
	return 0;
}

