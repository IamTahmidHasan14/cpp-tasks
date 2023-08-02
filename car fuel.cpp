#include<bits/stdc++.h>
using namespace std;

int refills(int* x,int l,int n)
{
    int lastR,numR=0, curR=0;
    while(curR<=n)
    {
        lastR=curR;
        while(curR<=n && x[curR+1]-x[lastR]<=l)
        {
            curR++;
        }
        if(curR==lastR)
            return -5;
        if(curR<=n)
            numR++;
    }
    return numR;
}
void show(int* a,int n)
{
    cout<<"\tA= ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" --- ";
    cout<<" =B\n";
}
int main()
{
    int A=0,B=30,L,X[]={A,10,20,B};
    show(X,4);
    cout<<"\nEnter the distance the car will travel at full tank (recommended 10): ";
    cin>>L;
    int n=refills(X,L,3);
    if(n==-5)
        cout<<"Impossible to reach goal!";
    else
    {
        cout<<"Refill is needed "<<n<<" times\n";
        n=0;
        cout<<"At ";
        for(int i=1;i<=3;i++)
        {
            if((X[i]-n)>L)
            {
                cout<<X[i-1]<<"km ";
                n=X[i-1];
            }
        }
    }
    return 0;
}
