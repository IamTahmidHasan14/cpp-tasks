#include<bits/stdc++.h>
using namespace std;

class Goods
{
    public:
    float Weight, Value;
    string item;
    float VPW()
    {
        return (Value/Weight);
    }
    void set(float w,float v)
    {
        Weight=w; Value=v;
    }
};

void swp(Goods& x, Goods& y)
{
    Goods z=x;
    x=y; y=z;
}

int part(Goods* a,int p, int r)
{
    int i,j=p-1;
    float x;

    i=p+rand()%(r-p);
    swp(a[i],a[r]);;
    x=a[r].VPW();

    for(i=p;i<r;i++)
    {
        if(a[i].VPW()>=x)
        {
            j++;
            swp(a[i],a[j]);
        }
    }
    swp(a[r],a[j+1]);

    return (j+1);
}

void quick(Goods* a,int p, int r)
{
    if(p<r)
    {
        int q=part(a,p,r);
        quick(a,p, q-1);
        quick(a,q+1, r);
    }
}
int knapsack(Goods* a, float l)
{
    for(int i=0;i<3;i++)
    {
        if(l==0) return(i);

        float v=a[i].VPW();
        a[i].Weight=(a[i].Weight<l?a[i].Weight:l);
        a[i].Value=a[i].Weight*v;
        l-=a[i].Weight;
    }
}
void setA(Goods *a)
{
    a[0].Weight=10;
    a[0].Value=60;
    a[0].item="1st";
    a[1].Weight=20;
    a[1].Value=100;
    a[1].item="2nd";
    a[2].Weight=30;
    a[2].Value=120;
    a[2].item="3rd";
}
void show(Goods* a,int n)
{
    cout<<"Item    |  Weight  | Value      | WPV";
    for(int i=0;i<n;i++)
    {
        cout<<"\n"<<a[i].item<<"\t|    "<<a[i].Weight<<"    |  "<<a[i].Value<<"\t|  "<<a[i].VPW();
    }

    cout<<"\n\n";
}
int total(Goods* a, int n)
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        c+=a[i].Value;
    }
    return c;
}
int main()
{
    int n=3;
    Goods A[n];
    setA(A);
    srand(time(0));
    show(A,n);
    quick(A,0,n-1);

    cout<<"Enter limit of weight: ";
    float L;
    cin>>L;
    n=knapsack(A,L);
    show(A,n);
    cout<<"Total Value: "<<total(A,n);

return 0;
}
