#include<iostream>
#include <queue>

using namespace std;
queue<int>frontier;

 class vertex
{
    public :
        int Vcost;
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
            if(node[a[i]].Vcost>node[a[i+1]].Vcost)
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
            m[i][j]=0;
        }
    }

    for(int i=0;i<e;i++)
    {
        int a,b;
        cout<<"Enter connected (directed) Vertices (a -> b) and it's cost: ";
        cin>>a>>b>>cost;

        m[a][b]=cost;
    }

    int explored[v];
    for(int i=0; i<v; i++)
    {
        explored[i]=0;node[i].Vcost=0;
    }
    int vstart,vend;
    cout<<"Enter the start vertex:";
	cin>>vstart;
	cout<<"Enter the end vertex:";
	cin>>vend;

    frontier.push(vstart);
    explored[vstart]=1;
    while(!frontier.empty())
    {
        if(vend==frontier.front())
        {
            cout<<"Found Vertex "<<vend<<" cost="<<node[vend].Vcost;
            break;
        }

        for(int i=0; i<v; i++)
        {
            if(m[frontier.front()][i]!=0 && explored[i]==0)
            {
                int temp_cost=node[frontier.front()].Vcost+m[frontier.front()][i];
                if(temp_cost<node[i].Vcost || node[i].Vcost==0)
                {
                    node[i].Vcost=temp_cost;
                    frontier.push(i);
                }


            }
        }

        //cout<<frontier.front();
        explored[frontier.front()]=1;
        frontier.pop();
        if(!frontier.empty())
        {
            vsort(node);
        }


    }

}
