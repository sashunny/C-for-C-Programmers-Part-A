
#include "graph.h"

graph::graph(const int &node, vector<vector<int>> &edges)
:n(node),range(10)
{

    for(int i=0;i<node;i++)
    {
        vector<int> _n(node);
        edges[i] = _n;
    }
}


void graph::createGraph(float &density, vector<vector<int>> &edges)
{

    srand(time(0));

    for(int i =0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            float prob = (rand() % 100) / 100.0;

            
            if (prob < density)
            {
                int value = rand() % range + 1;
                createEdge(i, j, value, edges);
            }                
        }
     
    }

    deleteEdges(edges);

}


void graph::deleteEdges(vector<vector<int>> &edges)
{
    for(int i =0;i<n;i++)
    {               
        for(int j=0;j<n;j++)
        {
            if(j==i)
                edges[i][i] = 0;
        }
    }
}


void graph::createEdge(const int &a, const int &b, const int &value, vector<vector<int>> &edges)
{

    //bidirectional graph
    edges[a][b] = value;
    edges[b][a] = value;

}


void graph::showGraph(vector<vector<int>> &edges)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<edges[i][j]<<"\t";
            if(j==n-1)
                cout<<endl;
        }
    }
}
