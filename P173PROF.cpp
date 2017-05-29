#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;

int main(void){
	int T;
	cin>>T;
	while(T--){
		long long a, b;
		cin>>a>>b;
		long long Ar[4];
		
		For(i, 1, 3)Ar[i] = b;
		
		if(a == b){
			cout<<"0"<<endl;
		}
		else{
			long long res = 0;
			if(2 * b - 1 >= a) cout<<"3"<<endl;
			else{
				long long x, y, z;
				while(1){
					Ar[1] = Ar[2] + Ar[3] - 1;
					if(Ar[1] > a) break;
					res++;
					x = Ar[1];
					Ar[2] = Ar[1] + Ar[3] - 1;
					if(Ar[2] > a) break;
					res++;
					y = Ar[2];
					Ar[3] = Ar[1] + Ar[2] - 1;
					if(Ar[3] > a) break;
					z = Ar[3];
					res++;
				}
				res += 3;
				if(x == a) res--;
				if(y == a) res--;
				if(z == a) res--;
				cout<<res<<endl;
			}
		}
	}
	return 0;
}

