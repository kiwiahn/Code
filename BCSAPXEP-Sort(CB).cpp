#include<iostream>

using namespace std;

void quicksort(int l,int r, int a[]){
	if(l>r){
		return;
	}
	int pivot=a[(l+r)/2];
	int i=l,j=r;
	while(a[i]<pivot){
		i++;
	}
	while(a[j]>pivot){
		j--;
	}
	if(i<=j){
		int temp=a[j];
		a[j]=a[i];
		a[i]=temp;
		i++;
		j--;
	}
	quicksort(l,j,a);
	quicksort(i,r,a);
}
int main(void){
	int n,a[1000];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	quicksort(1,n,a);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}

