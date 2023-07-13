#include<bits/stdc++.h>
using namespace std;


typedef struct
{
    string name;
    double weight,price,unitPrice;
} item;


double fractionalKnapsack(item x[], int n, int capacity)
{
    double profit=0;


    cout << "Selected items are: " << endl;

    for(int i=0; i<n; i++)
    {
        if(x[i].weight<=capacity)
        {
            profit+=x[i].price;
            capacity-=x[i].weight;
            cout << x[i].name << endl;
        }
        else
        {
            cout << x[i].name << endl;
            profit+=x[i].unitPrice*capacity;
            break;
        }
    }

    return profit;
}

int main()
{
    int i,n,capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    item x[n];

    for(i=0; i<n; i++)
    {
        cin >> x[i].name >> x[i].weight >> x[i].price;
        x[i].unitPrice = x[i].price/x[i].weight;
    }
    for(int i=0; i<n-1; i++)
    {
        int large = i;
        for(int j=i+1; j<n; j++)
        {
            if(x[j].unitPrice > x[large].unitPrice)
                large = j;
        }
        swap(x[i], x[large]);
    }

    printf("Enter the capacity of Knapsack : ");
    cin >> capacity;

    cout << "Profit: " << fractionalKnapsack(x,n,capacity);

    return 0;
}
