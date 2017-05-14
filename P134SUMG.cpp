#include<bits/stdc++.h>

using namespace std;

#define  For(i, a, b)     for(int i = a; i <= b; i++)
#define  Ford(i, a, b)    for(int i = a; i >= b; i--)
#define  ll               long long
#define  here             cout<<"i am here"<<endl;
const long long base= 1e9 + 7;
const int maxn = 1000000;
int n,a[100],b[100],x[100];
int mins,res1,res2;
bool ok;
void Sinh(int i){
	For(j, 0, 1){
		res1 = 1;
		res2 = 0;
		x[i] = j;
		if(i == n){
			ok = false;
			For(k, 1, n){
				if(x[k] == 1){
					ok = true;
					res1 *= a[k];
					res2 += b[k];
				}
			}
			if(ok == true && abs(res1 - res2) < mins) mins = abs(res1 - res2);
		}
		else Sinh(i+1);
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin>>n;
	For(i, 1, n){
		cin>>a[i]>>b[i];
	}
	mins = abs(a[1] - b[1]);
	Sinh(1);
	cout<<mins;
	return 0;
}

