#include <iostream>
#include <vector>

#include "graph.h"
#include "shortestPath.h"

using namespace std;


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


