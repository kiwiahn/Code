#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;

struct No{
	string A;
	string B;
};

int main(void){
	int T;
	cin>>T;
	while(T--){
		int M, N;
		int ok = 1, test = 0;
		No Ar[1001];
		cin>>N>>M;
		For(i, 0, N - 1){
			cin>>Ar[i].A;
		}
		int R, C;
		cin>>R>>C;
		For(i, 0, R - 1) cin>>Ar[i].B;
		For(i, 0, N - R){
			For(j, 0, M - C){
				ok = 1;
				int x = 0;
				For(k, i, i + R - 1){
					int y = 0;
					For(l, j, j + C - 1){
						if(Ar[k].A[l] != Ar[x].B[y]){
							ok = 0;
							break;
						}
						y++;
					}
					if(ok == 0) break;
					x++;
				}
				if(ok == 1){
					cout<<"YES"<<endl;
					test = 1;
					break;
				}
			}
			if(test == 1) break;
		}
		if(test == 0) cout<<"NO"<<endl;
	}
	return 0;
}

