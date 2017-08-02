#include<bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;
int const base = 1e9 + 7;

int maxSubArraySum(int a[], int size){
   int max_so_far = 0, max_ending_here = 0;
   for (int i = 0; i < size; i++){
       max_ending_here = max_ending_here + a[i];
       if (max_ending_here < 0)
           max_ending_here = 0;
           
       else if (max_so_far < max_ending_here)
           max_so_far = max_ending_here;
   }
   return max_so_far;
}

int Ar[100000], n;

int main(void){
	int maxs = -100000;
	int Sum = 0;
	cin>>n;
	For(i, 0, n - 1){
		cin>>Ar[i];
		if(Ar[i] > 0){
			Sum += Ar[i];
		}
		if(Ar[i] > maxs) maxs = Ar[i];
	}
	if(Sum == 0) Sum = maxs;
	int S = maxSubArraySum(Ar, n);
	if(S == 0) S = maxs;
	cout<<S<<" "<<Sum;
	return 0;
}

