
#include <iostream>
#include <vector>
#include <ctime>


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
