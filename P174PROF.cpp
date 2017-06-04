#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;

long long K, Dis[maxn];
string Name[maxn];

int main(void){
	int N;
	Dis[0] = 0;
	int key;
	cin>>N>>K;
	For(i, 1, N){
		cin>>Name[i];
		Dis[i] = Dis[i-1] + i;
		if(Dis[i] <= K) key = i;
	}
	sort(Name + 1, Name + N + 1);
	if(Dis[key] == K) cout<<Name[key];
	else{
		K = K - Dis[key];
		cout<<Name[K];
	}
	return 0;
}

