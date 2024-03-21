#include <bits/stdc++.h>
using namespace std;

int Count(int a, int b, int c, int num)
{
    int k=(c*b)/__gcd(b, c);
    return ((num / a) + (num / b) + (num / c)
            - (num / (a*b)/__gcd(a, b))
            - (num / (c*b)/__gcd(b, c))
            - (num / (c*a)/__gcd(a, c))
            + (num / (k*a)/__gcd(a, (c*b)/__gcd(b, c))));
}
int findNthTerm(int a, int b, int c, int n)
{
    int s=1, e=INT_MAX;
 
    while (s<e) {
        int mid=s+(e-s)/2;
        if (Count(a,b,c,mid)<n)
            s=mid+1;
        else
            e=mid;
    }
    return s;
}
int main()
{
    int a = 2, b = 3, c = 5, n = 10;
 
    cout << findNthTerm(a, b, c, n);
 
    return 0;
}