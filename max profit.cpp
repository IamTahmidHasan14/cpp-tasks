#include <bits/stdc++.h>
using namespace std;

int ks(int W, int weight[], int value[], int n){
    if (n==0 || W==0)
        return 0;
    if (weight[n-1] > W)
        return ks(W, weight, value, n-1);
    else
        return max(value[n-1]+ ks(W - weight[n-1], weight, value, n-1), ks(W, weight, value, n-1));
}

int main()
{
    int value[] = {30, 14, 16, 9};
    int weight[] = {6, 3, 4, 2};
    int W = 10;
    int n = sizeof(value) / sizeof(value[0]);
    cout << "Max profit: ";
    cout << ks(W, weight, value, n) << endl;
    return 0;
}
