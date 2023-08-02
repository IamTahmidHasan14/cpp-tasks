#include <bits/stdc++.h>
using namespace std;

int LCS( char *X, char *Y, int m, int n ){
    if (m==0 || n==0)
        return 0;
    if (X[m-1] == Y[n-1])
        return 1 + LCS(X, Y, m-1, n-1);
    else
        return max(LCS(X, Y, m, n-1), LCS(X, Y, m-1, n));
}

int main()
{
    char X[] = "AGGTAB", Y[] = "GXTXAYB";
    int m = strlen(X), n = strlen(Y);
    cout << "Length of LCS is: " << LCS( X, Y, m, n ) << endl;
    return 0;
}
