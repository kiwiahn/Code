#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;

map <ll, ll> Mp, Xp;

long long Ar[maxn];

int main(void){
	int N;
	long long B;
	cin>>N>>B;
	For(i, 1, N){
		cin>>Ar[i];
		if(Ar[i] >= 0) Mp[Ar[i]]++;
		if(Ar[i] < 0) Xp[abs(Ar[i])]++;
	}
	long long res = 0;
	For(i, 1, N){
		long long  K = B - Ar[i];
		if(Ar[i] >= 0){
			if(K < 0){
				if(Mp[Ar[i]] > 0 && Xp[abs(K)] > 0){
					res += Xp[abs(K)] * Mp[Ar[i]];
					Xp[abs(K)] = 0;
					Mp[Ar[i]] = 0;
				}
			}
			if(K >= 0){
				if(Mp[Ar[i]] > 0 && Mp[K] > 0){
					res += Mp[K] * Mp[Ar[i]];
					Mp[K] = 0;
					Mp[Ar[i]] = 0;
				}
			}
		}
		if(Ar[i] < 0){
			if(K >= 0){
				if(Xp[abs(Ar[i])] > 0 && Mp[K] > 0){
					res += Mp[K] * Xp[abs(Ar[i])];
					Mp[K] = 0;
					Xp[abs(Ar[i])] = 0;
				}
			}
			if(K < 0){
				if(Xp[abs(Ar[i])] > 0 && Xp[abs(K)] > 0){
					res += Xp[abs(K)] * Xp[abs(Ar[i])];
					Xp[abs(K)] = 0;
					Xp[abs(Ar[i])] = 0;
				}
			}
		}
	}
	cout<<res;
	return 0;
}

