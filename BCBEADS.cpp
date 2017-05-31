#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;

int main(void){
	int n, res = 0;
	int a[101];
	a[0] = -1;
	cin>>n;
	For(i, 1, n){
		cin>>a[i];
		if(a[i] != a[i-1] && a[i-1] != -1){
			res++;
		}
	}
	cout<<res;
	return 0;
}

