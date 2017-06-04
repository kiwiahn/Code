#include<iostream>

using namespace std;


int const maxn = 1000000;

int p[maxn],a[maxn],b[maxn];
int fi[maxn],se[maxn],th[maxn];

int main(void){
	int n,max,max1,max2,max3;
	int m,k,j,key;
	
	while( 1 ){
		for(int i =1 ; i <= max1;i++){
			p[i] = 0;
			b[i] = 0;
			fi[i] = 0;
			se[i] = 0;
			th[i] = 0;
		}
		max=0;
		max1=0;
		max2=0;
		max3=0;
		k=0;
		j=1;
		cin>>n;
		if(n == 0){
			break;
		}
		while(n > 0){
			cin>>m;
			for(int i = 1;i <= m; i++){
				cin>>a[i];
				if(i == 1){
					p[a[i]]+=3;
					fi[a[i]]++;
				}
				if(i == 2){
					p[a[i]]+=2;
					se[a[i]]++;
				}
				if(i == 3){
					p[a[i]]++;
					th[a[i]]++;
				}
				if(p[a[i]] > max){
					max = p[a[i]];
				}
				if(a[i] > max1){
					max1=a[i];
				}
			}
			n--;
		}
		for(int i = 1; i <= max1;i++){
			if(p[i] == max){
				b[j]=i;
				j++;
				k++;
			}
		}
		if(k == 1){
			cout<<b[1];
		}
		if(k > 1){
			k=0;
			max=0;
			for(int i = 1;i < j;i++){
				if(fi[b[i]] >= max){
					max = fi[b[i]];
				}
			}
			for(int i = 1;i < j; i++){
				if(fi[b[i]] == max){
					key = b[i];
					k++;
				}	
			}
			if(k == 1){
				cout<<key;
			}
			if(k > 1){
				k=0;
				for(int i = 1;i < j;i++){
					if(fi[b[i]] == max && se[b[i]] >= max2){
						max2 = se[b[i]];
					}
				}	
				for(int i = 1;i < j; i++){
					if(se[b[i]] == max2 && fi[b[i]] == max){
						key = b[i];
						k++;
					}	
				}
				if(k == 1){
					cout<<key;
				}
				if(k > 1){
					for(int i = 1;i < j;i++){
						if(fi[b[i]] == max && se[b[i]] == max2 && th[b[i]] >= max3){
							max3 = th[b[i]];
						}
					}	
					for(int i = 1;i < j; i++){
						if(se[b[i]] == max2 && fi[b[i]] == max && th[b[i]] == max3){
							cout<<b[i]<<" ";
						}	
					}	
				}
			}
		}
		cout<<endl;
		
	}
	return 0;
}


