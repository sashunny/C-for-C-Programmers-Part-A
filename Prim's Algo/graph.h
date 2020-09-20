
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


class graph
{

public:
	graph();
	int readDataFromFile(string &file);
	void setUpGraph(vector<vector<int>> &edges);
	void display(vector<vector<int>> &edges);

private:
	vector<int> source, destination, weight;
	int node;

	void fillUp(string str);


};