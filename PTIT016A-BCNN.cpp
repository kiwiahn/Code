#include<iostream>

using namespace std;

long long gcd(long long a,long long b){
	long long temp;
	while(b){
		temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}

int main(void){
	long long A,B,max,max1,N,N1,k;
	
	cin>>A>>B;
	
	if(A<B){
		k=A;
		A=B;
		B=k;
	}
	if(A==B){
		cout<<1;
		return 0;
	}
	k=A-B;
	N=(B/k + 1)*k - B;
	
 	max=(A+N)/gcd(A+N,B+N)*(B+N);
	for(long long x=2;x*x<=k;x++){
		 if(k%x==0)
    {
             
            N1=(B/x+1)*x-B; 
            if(N1<N)
            {
               max1=(A+N1)/gcd(A+N1,B+N1)*(B+N1);
               if(max>=max1) {max=max1;N=N1;}
            }
            long long y=k/x;
             
            N1=(B/y+1)*y-B; 
            if(N1<N)
            {
            max1=(A+N1)/gcd(A+N1,B+N1)*(B+N1);
            if(max>=max1) {max=max1;N=N1;}           
            }
    }
	}
	cout<<N;
		
	return 0;
}

