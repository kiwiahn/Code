// bai nay dua tren y tuong neu la hinh chu nhat. se co hai cap cung x hai cap cung y nhung neu cung x ko dc cung y va nguoc lai. 
#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;

int main(void){
	int Test;
	cin>>Test;
	while(Test--){
		int x[10], y[10];
		bool Used[10] = {false}; // mang danh dau da su dung
		bool ok = true; // bien kiem tra
		For(i, 1, 4){
			cin>>x[i]>>y[i];
		} 
		int resx = 0, resy = 0; // khoi tao hai phan tu dem : resx dem so lan x[i] == x[j]
		For(i, 1, 4){
			if(Used[i] == false){
				Used[i] = true; // vi tri j da su dung
				For(j, 1, 4){
					if(Used[j] == false){
						if(x[j] == x[i]){
							if(y[j] != y[i]){ // neu x[i] == x[j], y[i] == y[j] thi hai diem nay trung nhau ==> ok = false
								resx++;
								Used[j] = true; // o day cho vi tri i da su dung
								break; // break nay de tranh tim them mot vi tri j khac bang voi x[i] de tien cho viec xet resx o duoi
							}
							if(y[j] == y[i]){ //neu trung nhau thi break luon.
								ok == false;
								break;
							}
						}
					}
				}
				if(ok == false) break;	
			}
		}
		if(resx != 2) ok = false; // neu resx ko  dc dem 2 lan thi khong co du 2 cap trung x;
		memset(Used, false, sizeof Used); // memset == for(int i = 0; i <= kich thuoc mang Used; i++) Used[i] = 0;
		For(i, 1, 4){ // phan nay thi tuong tu nhung de xet xem co du 2 cap y bang nhau ko
			if(Used[i] == false){
				Used[i] = true;
				For(j, 1, 4){
					if(Used[j] == false){
						if(y[j] == y[i]){
							resy++;
							Used[j] = true;
							break;
						}
					}
				}	
			}
		}
		if(resy != 2) ok = false;
		if(ok == false) cout<<"NO"<<endl;
		if(ok == true) cout<<"YES"<<endl;
	}
	return 0;
}

