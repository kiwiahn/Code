#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;

map <int, int> Mp, Xp;

int main(void){
	int N;
	int Ar[505], F[505];
	bool used[505];
	cin>>N;
	For(i, 1, N){
		cin>>Ar[i];
	}
	int maxs = 0;
	
	For(i, 1, N){
		F[1] = Ar[i];
		For(j, 1, N){
			if(j != i){
				memset(used, true, sizeof used);
				F[2] = Ar[j];
				used[j] = false;
				used[i] = false;
				int	x = 3, res = 2, ok = 1;
				while(ok == 1){
					ok = 0;
					For(k, 1, N){
						if(used[k] == true){
							if(Ar[k] == F[x-2] + F[x-1]){
								ok = 1;
								F[x] = Ar[k];
								x++;
								res++;
								used[k] = false;
							}
						}
					}
				}
				if(res == N){
					cout<<res;
					return 0;
				}
				if(res > maxs) maxs = res;
			}
		}	
	}
	cout<<maxs;
	return 0;
}

