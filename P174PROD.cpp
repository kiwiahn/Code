#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;

int NMod[6] = {0}, MMod[6] = {0};

int main(void){
	int N, M;
	cin>>N>>M;
	int A = N / 5;
	int B = M / 5;
	For(i, 1, A){
		For(j, 0, 4) NMod[j]++;
	}
	For(i, 1, B){
		For(j, 0, 4) MMod[j]++;
	}
	For(i, 1, N % 5){
		NMod[i]++;
	}
	For(i, 1, M % 5){
		MMod[i]++;
	}
	long long res = 0;
	res += 1ll * NMod[0] * MMod[0];
	For(i, 1, 4){
		res += 1ll * NMod[i] * MMod[5 - i];
	}
	cout<<res<<endl;
	return 0;
}

