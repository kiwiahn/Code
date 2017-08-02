#include <bits/stdc++.h>

using namespace std;

#define   For(i, a, b)            for(int i = a; i <= b; i++)
#define   Ford(i, a, b)           for(int i = a; i >= b; i--)
#define   ll                      long long
#define   here                    cout<<"I am Here"<<endl;

int const maxn = 1000000;

int subsetPairNotDivisibleByK(int arr[], int N, int K){
    int f[K];
    memset(f, 0, sizeof(f));
    
    for (int i = 0; i < N; i++)
        f[arr[i] % K]++;
 
    if (K % 2 == 0)
        f[K/2] = min(f[K/2], 1);
 
    int res = min(f[0], 1);
 
    for (int i = 1; i <= K/2; i++)
        res += max(f[i], f[K-i]);
 
    return res;
}
 
//  Driver code to test above methods
int main(){
    int arr[100000], N;
    int K;
    cin>>N>>K;
    For(i, 0, N - 1) cin>>arr[i];
    cout << subsetPairNotDivisibleByK(arr, N, K);
    return 0;
}
