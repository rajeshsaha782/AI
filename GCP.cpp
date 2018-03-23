#include<iostream>
#include<conio.h>
#include <stack>
#include <list>
using namespace std;

class vertex
{
public:
    string color;
};

int main()
{

    stack<int>dfs;
    stack<int>ts;
    int v,e,a,b;
    char d;
    cout<<"Enter number of Vertices: ";
    cin>>v;
    vertex V[v];
   cout<< V[0].color;
    cout<<"Enter number of Edges: ";
    cin>>e;
    int m[v][v];
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            m[i][j]=0;
        }
    }
    cout<<endl;
    for(int i=0; i<e; i++)
    {
            cout<<"Enter connected (undirected) Vertices (u & v): ";
            cin>>a>>b;
            m[a][b]=m[b][a]=1;

    }

    int visited[v];
    for(int i=0; i<v; i++)
    {
        visited[i]=0;

    }

    //cout<<"\nEnter the starting Vertex: ";
    //cin>>e;
    dfs.push(0);
    visited[0]=1;
    //cout<<"\nDFS :"<<dfs.top()<<" ";


   V[0].color="red";


    while(!dfs.empty())
    {

        for(int i=0; i<v; i++)
        {
            if(m[dfs.top()][i]==1 && visited[i]==0)
            {
                dfs.push(i);
                visited[i]=1;
                //cout<<dfs.top()<<" ";

                for(int j=0;j<v;j++)
                {
                    if(m[i][j]==1)
                    {

                           if(V[j].color=="red")
                            {
                                V[i].color="blue";
                            }
                            else if(V[j].color=="blue")
                            {
                                V[i].color="green";
                            }
                            else if(V[j].color=="green")
                            {
                                V[i].color="red";
                            }

                    }

                }
                i=0;
                continue;
            }


        }
        int check=0,node=dfs.top();
        while(check<v)
        {
            if(m[node][check]==1 && V[node].color==V[check].color)
            {
                if(V[check].color=="red")
                {
                    V[node].color="blue";
                }
                else if(V[check].color=="blue")
                {
                    V[node].color="green";
                }
                else if(V[check].color=="green")
                {
                    V[node].color="red";
                }
            }
            check++;
        }
        dfs.pop();

    }
    cout<<endl;

    int c=0;
    while(c<v)
    {
        cout<<c<<"->"<<V[c].color<<endl;
        c++;
    }

    getch();
}
