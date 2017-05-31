#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;
int kt(long long m){
	int res = 0;
	while(m != 0){
		res++;
		m /= 10;
	}
	return res;
}
map <int, int> Mp, Xp, Used;
int Ar3[maxn];

int main(void){
	int N, M, k = 1;
	int Ar1[1001], Ar2[1001];
	cin>>N;
	For(i, 1, N){
		cin>>Ar1[i];
		int x = 2;
		int m = Ar1[i];
		while( x * x <= Ar1[i]){
			if( m % x == 0 ){
				Mp[x]++;
				m= m / x;
				if(Used[x] != 1){
					Used[x] = 1;
					Ar3[k] = x;
					k++;
				}
			}
			if( m % x != 0 ){
				x++;
			}
			if( m == 1 ){
				break;
			}
		}
		if(m != 1 && Used[m] != 1){
			Used[m] = 1;
			Ar3[k] = m;
			k++;
		}
		Mp[m]++;	
	}
	cin>>M;
	For(i, 1, M){
		cin>>Ar2[i];
		int x = 2;
		int m = Ar2[i];
		while( x * x <= Ar2[i]){
			if( m % x == 0 ){
				Xp[x]++;
				m= m / x;
				if(Used[x] != 1){
					Used[x] = 1;
					Ar3[k] = x;
					k++;
				}
			}
			if( m % x != 0 ){
				x++;
			}
			if( m == 1 ){
				break;
			}
		}
		Xp[m]++;
		if(m != 1 && Used[m] != 1){
			Used[m] = 1;
			Ar3[k] = m;
			k++;
		}	
	}
	long long res = 1;
	For(i, 1, k - 1){
		if(Mp[Ar3[i]] > 0 && Xp[Ar3[i]] > 0){
			if(Mp[Ar3[i]] >= Xp[Ar3[i]]){
				res = res * 1ll * pow(Ar3[i], Xp[Ar3[i]]);
			}
			else{
				res = res * 1ll * pow(Ar3[i], Mp[Ar3[i]]);
			}
		}
	}
	long long m = res % 1000000000;
	if(kt(m) < 9){
		For(i, 1, 9 - kt(m)) cout<<"0";
		cout<<m;
	}
	else{
		cout<<m;
	}
	return 0;
}

