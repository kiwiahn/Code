#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;
int C, N, res = 0, maxs = 0;
int Ar[100];

void Bab(int tmp){
	For(i, 0, 1){
		res += Ar[tmp] * i;
		if(res <= C){
			if(res > maxs){
				maxs = res;
			}
			if(tmp < N) Bab(tmp + 1);
		}
		res -= Ar[tmp] * i;
	}
}

int main(void){
	cin>>C>>N;
	For(i, 1, N){
		cin>>Ar[i];
	}
	Bab(1);
	cout<<maxs;
	return 0;
}

