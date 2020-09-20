#include <iostream>
#include <vector>
#include <ctime>
#include <climits>

using namespace std;

class graph
{
    public:
    	graph(const int &node, vector<vector<int>> &edges);
    	void createGraph(float &density,vector<vector<int>> &edges);
        void showGraph(vector<vector<int>> &edges);

    private:
    	//variables and constants
    	const int n;
    	const int range;
    	

    	//methods
    	void deleteEdges(vector<vector<int>> &edges);
    	void createEdge(const int &a, const int &b, const int &value,vector<vector<int>> &edges);


};

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

class dijkstra
{
    public:
        dijkstra(const int &node);
        void ShortestPath(vector<vector<int>> &edges);
        void printOutput(vector<vector<int>> &edges, const int &node);

    private:
        int findMinNode(vector<int> &dist, vector<bool> &isVisited);

        int node;
        vector<int> cost;
 
};

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


int main()
{
	vector<float> density = {0.2f, 0.4f};

	const int node = 50;

	vector<vector<int>> edges(node);
 
    dijkstra shortest(node);
    graph gp(node, edges);

    

    for(int i =0; i<density.size();i++)
    {
    	cout<<"density :"<<density[i]<<endl;
    	gp.createGraph(density[i],edges);

        //cout<<"displaying graph....."<<endl; 

    	//gp.showGraph(edges);

    	shortest.ShortestPath(edges);

    	shortest.printOutput(edges, node);
    	
    }

    return 0;
}


