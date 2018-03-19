#include<iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
queue<int>frontier;
int heuristic_value[10]={366,253,176,193,10,0,160};
 class vertex
{
    public :
        int total_cost;
};
int vsort(class vertex *node)
{
    int s=frontier.size();
    int a[s];
    for(int i=0;i<s;i++)
    {
        a[i]=frontier.front();
        frontier.pop();
    }

    for(int j=0;j<s-1;j++)
    {
        for(int i=0;i<s-1;i++)
        {
            if(node[a[i]].total_cost>node[a[i+1]].total_cost)
            {
                swap(a[i],a[i+1]);

            }
        }

    }

    for(int i=0;i<s;i++)
    {
        frontier.push(a[i]);
    }
}
int main()
{
    int v,e,cost;

    cout<<"Enter number of Vertices: ";
    cin>>v;

    vertex node[v];

    cout<<"Enter number of Edges: ";
    cin>>e;

    int m[v][v];

    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            m[i][j]=9999;
        }
    }

    for(int i=0;i<e;i++)
    {
        int a,b;
        cout<<"Enter connected (directed) Vertices (a -> b) and it's cost: ";
        cin>>a>>b>>cost;

        m[a][b]=m[b][a]=cost;
    }

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0; i<v; i++)
    {
        node[i].total_cost=0;
    }
    int vstart,vend;
    cout<<"Enter the start vertex:";
	cin>>vstart;
	cout<<"Enter the end vertex:";
	cin>>vend;

    frontier.push(vstart);

    while(!frontier.empty())
    {
        if(vend==frontier.front())
        {
            cout<<"Found Vertex "<<vend<<" cost="<<node[vend].total_cost;
            break;
        }

            for(int i=0; i<v; i++)
            {
                if(m[frontier.front()][i]!=9999)
                {
                    cout<<"Node "<<i<<"->cost:"<<m[frontier.front()][i]<<"+heuristic_value:"<<heuristic_value[i]<<endl;
                    node[i].total_cost=m[frontier.front()][i]+heuristic_value[i];
                    frontier.push(i);

                }
            }
        }

        //cout<<frontier.front();
        cout<<frontier.front()<<endl;
        frontier.pop();
        if(!frontier.empty())
        {
            vsort(node);
        }


    }


