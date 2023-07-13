#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int c[n];
    int arr[n+1][m+1];
    for(int i=0; i<n; i++)
        cin >> c[i];


    for(int i=0; i<=n; i++)
        arr[i][0] = 0;
    for(int j=1; j<=m; j++)
        arr[0][j] = m+1;



    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(j>=c[i-1])
            {
                arr[i][j] = min(arr[i-1][j], (1+arr[i][j-c[i-1]]));
            }
            else
            {
                arr[i][j] = arr[i-1][j];

            }
        }

    }
    cout <<"Minimun number of coin is: "<< arr[n][m] << endl;
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    /*
    int i = n, j = m;
    vector<char> s;
    while(i>0 && j>0)
    {
        if(track[i][j] == 'D')
        {
            s.push_back(s1[i-1]);
            i--;
            j--;
        }
        else if(track[i][j] == 'U')
            i--;
        else j--;
    }
    reverse(s.begin(), s.end());
    for(int i=0; i<s.size(); i++)
        cout << s[i]<< endl;

    cout << endl;
    */
}
