#include "shortestPath.h"


dijkstra::dijkstra(const int &node)
{
    this->node = node;
}


void dijkstra::ShortestPath(vector<vector<int>> &edges)
{
    vector<bool> isVisited(node);
    vector<int> dist(node);


    for(int i=0;i<node;i++)
    {
        isVisited[i] = false;
        dist[i] = INT_MAX;
    }

    dist[0] = 0;

    for(int i=0;i<node-1;i++)
    {
        int minNode = findMinNode(dist,isVisited);

        isVisited[minNode] = true;
        for(int j=0;j<node;j++)
        {
            if(edges[minNode][j]!=0 && !isVisited[j])
            {
                int c_dist = dist[minNode] + edges[minNode][j];
                if(c_dist < dist[j])
                {
                   dist[j] = c_dist;
                } 
            }
        }
    }

    cost = dist;
}


int dijkstra::findMinNode(vector<int> &dist, vector<bool> &isVisited)
{
    int minVertex =-1;

    for(int i=0;i<node;i++)
    {
        if(!isVisited[i])
        {
            if(minVertex == -1 || dist[i] < dist[minVertex])
            {
                minVertex = i;
            }
        }
    }

    return minVertex;
}


void dijkstra::printOutput(vector<vector<int>> &edges, const int &node)
{

    /*cout<<"output....."<<endl;

    for(int i =0; i<node;i++)
        cout<<i<<" "<<cost[i]<<"\t";

    cout<<endl;*/

    float averageDistance;
    int sum = 0;

    for(auto x : cost)
    {
        sum += x; 
    }

    averageDistance = static_cast<float>(sum)/cost.size();

    cout<<"Average distance : "<<averageDistance<<endl;
}