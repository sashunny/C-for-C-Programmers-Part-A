
#include <iostream>
#include <vector>

#include "graph.h"
#include "prim.h"

using namespace std;



int main()
{
	int node;

	graph g; Prim p;

	string file = "../data.txt";

	node = g.readDataFromFile(file);

	vector<vector<int>> edges(node);

	g.setUpGraph(edges);

	g.display(edges);

	p.MST(edges, node);

	return 0;
}
