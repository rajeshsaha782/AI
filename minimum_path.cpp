#include<iostream>

using namespace std;

int main()
{
    int matrix[5][5]={};

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            int x;
            cout<<"Enter cost:";
            cin>>x;
            matrix[i][j]=x;
        }
    }

    int a=0,b=0,cost=matrix[0][0];
    for(int i=0;i<25;i++)
    {
        if(matrix[a+1][b]>=matrix[a][b+1])
        {
            b++;
            cost=cost+matrix[a][b];
        }
        else
        {
            a++;
            cost=cost+matrix[a][b];
        }
        if(a==5 || b==5)
        {
            break;
        }
    }
    cout<<cost;
}

