#include <iostream>
using namespace std;
 
int BinSearch(int *M, int n, int k);
 
int main()
{
    const int n=5;
    int A[n];
    int x;
    
    for (size_t i=0; i<n; i++)
    {
        cout << "Please, input A[" << i+1 << "] = ";
        cin >> A[i];
    }
    
    cout << "find this -> ";
    cin >> x;
    
    cout << BinSearch(A, n, x);
    
    return 0;
}
 
int BinSearch(int *M, int n, int k)
{
    int L = 0;
    int R = n;
 
    int m;
    int z = 0;
 
    while (L<R)
    {
        z++;
        m = (L+R)/2;
        if (k > M[m]) L = m;
        if (k < M[m]) R = m;
        if (k == M[m]) break;
    }
 
    return m;
}