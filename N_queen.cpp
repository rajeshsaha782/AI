#include<iostream>
#include<stdlib.h>
using namespace std;
int m[100][100],q;

bool PlaceQueen(int row,int col)
{
    int i, j;
    for (i = 0; i < col; i++)///same row
    {
        if (m[row][i])
            return false;
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)///diagonal
    {
        if (m[i][j])
            return false;
    }

    for (i = row, j = col; j >= 0 && i < 8; i++, j--)
    {
        if (m[i][j])
            return false;
    }

    return true;
}

bool Nqueen(int col)
{
     if (col >= q)
     {
        return true;
     }

    for(int i=0;i<q;i++)
    {
            if(PlaceQueen(i,col))
            {
                m[i][col]=1;
                cout<<"1->"<<i<<" "<<col<<endl;
                if(Nqueen(col+1))
                {
                    return true;

                }
                cout<<"2->"<<i<<" "<<col<<endl;
                m[i][col] = 0;
            }


    }
return false;
}

int main()
{


   /* for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            m[i][j]=0;
        }
    }*/

cin>>q;
    Nqueen(0);
    /*for(int i=7;i>=0;i--)
    {
        for(int j=7;j>=0;j--)
        {
            if(PlaceQueen(i,j))
            {
                m[i][j]=1;
                break;
            }

        }
    }*/

    for(int i=0;i<q;i++)
    {
        for(int j=0;j<q;j++)
        {
            cout<<m[i][j];
        }
        cout<<endl;
    }
}
