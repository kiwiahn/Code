#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;

map <int, int> Exist;
int Ar[maxn];

int main(void){
	int N;
	int maxs = 0, mins = 1000000000;
	int res = 0;
	cin>>N;
	For(i, 1, N){
		cin>>Ar[i];
		if(Ar[i] > maxs) maxs = Ar[i];
		if(Ar[i] < mins) mins = Ar[i];
		if(Exist[Ar[i]] == 0){
			res++;
			Exist[Ar[i]] = 1;
		}
	}
	if(res > 3) cout<<"NO";
	else{
		if(res <= 2) cout<<"YES";
		else{
			ll X = 1ll * (maxs + mins);
			if(X % 2 != 0) cout<<"NO";
			else{
				int key;
				For(i, 1, N){
					if(Ar[i] != maxs && Ar[i] != mins){
						key = Ar[i];
						break;
					}
				}
				if(maxs + mins == 2 * key) cout<<"YES";
				else cout<<"NO";
			}
		}
	}
	return 0;
}

