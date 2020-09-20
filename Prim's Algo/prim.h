
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Prim
{

public:
	Prim();
	void MST(vector<vector<int>> &edges, const int &node);

private:
	void init(vector<int> &weight, vector<int> &parent, vector<bool> &isVisited, const int &node);
	int findMinVertex(vector<int> &weight, vector<bool> &isVisited, const int &node);
	void displayOutput(vector<int> &weight, vector<int> &parent, const int &node);
	int MSTValue(vector<int> &weight);

};