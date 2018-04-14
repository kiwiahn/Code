#include <bits/stdc++.h>
using namespace std;

#define 	For(i, a, b)	for(int i = a; i <= b; i++)
#define  	ll  					long long

ll const base = 1e9 + 7;
const ll size = 2;
struct Matrix{
	ll a[size + 1][size + 1];
} I, a;
ll n, res;

// nhan ma tran
Matrix nhan(Matrix A, Matrix B){
	Matrix C;
	For(i,1,size){
		For(j,1,size){
			C.a[i][j] = 0;
			For(k,1,size){
				C.a[i][j] += (A.a[i][k] * B.a[k][j]) % base;
			}
		}
	}
	return C;
}
//luy thua ma tran
Matrix luythua(Matrix A, ll p){
	Matrix RES;
	if(p == 0){
		return I; // ma tran don vi
	}
	if(p == 1) return A;
	RES = luythua(A, p/2);
	RES = nhan(RES, RES);
	if(p%2 == 1) RES = nhan(RES, A);
	return RES;
}
// ham khoi tao ban dau
void init(){
	// ma tran don vi
	I.a[1][1] = 1;	I.a[1][2] = 0;
	I.a[2][1] = 0;	I.a[2][2] = 1;
	//ma tran ban dau
	a.a[1][1] = 1;	a.a[1][2] = 1;
	a.a[2][1] = 1;	a.a[2][2] = 0;
}

void solve(){
	cin >> n;
	if(n == 0 || n == 1) cout << 1;
	else {
		ll f0 = 0, f1 = 1;
		a = luythua(a, n - 1);
		res = a.a[1][1] * f1 + a.a[1][2] * f0;
		cout << res;
	}
}
main(){
	init();
	solve();
}
