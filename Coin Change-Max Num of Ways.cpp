#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,amount;
    cout<<"Enter no of coin:";
    cin>>n;
    int coin[n];
    cout<<"Enter coin:";
    for(int i=0;i<n;i++)
    {
        cin>>coin[i];
    }
    cout<<"Enter amount:";
    cin>>amount;
    int a[n][amount+1];
    for(int i=0;i<n;i++)
    {
        a[i][0]=1;
    }
    for(int j=1;j<=amount;j++)
    {
        if(j%coin[0]==0)
        {
            a[0][j]=1;
        }
        else
        {
            a[0][j]=0;
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=amount;j++)
        {
            if(j>=coin[i])
            {
                a[i][j]=a[i-1][j]+a[i][j-coin[i]];
            }
            else
            {
                a[i][j]=a[i-1][j];
            }
        }
    }
    cout<<"Maximum number of way:"<<a[n-1][amount]<<endl;


}
