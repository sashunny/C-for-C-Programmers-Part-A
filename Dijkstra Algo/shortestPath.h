#include <iostream>
#include <vector>
#include <climits>

using namespace std;

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