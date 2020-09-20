
#include <iostream>
#include <vector>
#include <fstream>
#include <climits>

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


graph::graph()
{

}


int graph::readDataFromFile(string &file)
{
	fstream f;
	string word;

	f.open(file);

	int i = 0; 

    while(getline(f, word))
    {
        if(i == 0)
        {
        	node = stoi(word);
        }
        else
        {

        	fillUp(word);

        }

        i++;
    }

    return node;
}


void graph::fillUp(string str)
{
	int i=0;

	string word = ""; 
	for (auto x : str) 
	{ 
    	if (x == ' ') 
        { 
        	if(i==0)
            {
        		source.push_back(stoi(word));
           		i++;
           		word = "";
           	}
           	else if(i==1)
           	{
           		destination.push_back(stoi(word));
           		i++;
           		word = "";
           	}
       	} 
       	else
       	{ 
           	word = word + x; 
       	} 
   	}  

   	weight.push_back(stoi(word));
}


void graph::setUpGraph(vector<vector<int>> &edges)
{

	for(int i =0;i<node;i++)
	{
		vector<int> v(node);
		edges[i] = v;
	}


	for(int i=0;i<source.size();i++)
	{
		edges[source[i]][destination[i]] = weight[i];
	}
}


void graph::display(vector<vector<int>> &edges)
{
	for(int i =0;i<node;i++)
	{
		for(int j=0;j<node;j++)
		{ 
			cout<<edges[i][j]<<" ";
		}
		cout<<endl;

	}
}


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


Prim::Prim()
{

}


void Prim::MST(vector<vector<int>> &edges, const int &node)
{
	vector<int> weight(node), parent(node);
	vector<bool> isVisited(node);

	init(weight,parent,isVisited,node);

	for(int i =0;i<node -1;i++)
	{
		int minVertex = findMinVertex(weight,isVisited,node);
		
		isVisited[minVertex] = true;
		//for each neighbour of the minVertex do the following 
		for(int j=0; j<node;j++)
		{
			//check if there are neighbours and find them all
			if(!isVisited[j] && edges[minVertex][j] != 0)
			{
				if(edges[minVertex][j] < weight[j])
				{
					weight[j] = edges[minVertex][j];
					parent[j] = minVertex;
				}
			}
		}
	}

	displayOutput(weight, parent, node);
}


void Prim::init(vector<int> &weight, vector<int> &parent, vector<bool> &isVisited, const int &node)
{
	for(int i =0;i<node;i++)
	{
		weight[i] = INT_MAX;
		isVisited[i] = false;
	}

	weight[0] = 0;
	parent[0] = -1;
}


int Prim::findMinVertex(vector<int> &weight, vector<bool> &isVisited, const int &node)
{
	int minVertex = -1;
	for(int i=0;i<node;i++)
	{
		if(!isVisited[i])
		{
			if(minVertex == -1 || weight[i] < weight[minVertex])
			{	
				minVertex = i;
			}
		}
	}

	return minVertex;
}


void Prim::displayOutput(vector<int> &weight, vector<int> &parent, const int &node)
{
	cout<<".............output............."<<endl;

	for(int i=1;i<node;i++)
	{
		if(parent[i] < i)
		{
			cout<<parent[i]<<" "<<i<<" :  "<<weight[i]<<endl;
		}
		else
		{
			cout<<i<<" "<<parent[i]<<"   "<<weight[i]<<endl;
		}
		
	}

	int val = MSTValue(weight);

	cout<<"MST value is : "<<val<<endl;

}


int Prim::MSTValue(vector<int> &weight)
{
	int sum = 0;

	for(auto i : weight)
	{
		sum += i;
	}

	return sum;
}


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


/***********************************OUTPUT***********************************/
/*

0 4 8 0 0 
4 0 2 6 0 
8 2 0 3 9 
0 6 3 0 5 
0 0 9 5 0 
.............output.............
0 1 :  4
1 2 :  2
2 3 :  3
3 4 :  5
MST value is : 14


       (1)-------(3)
      / |      /  | 
     /  |     /   |
    (0) |    /    |
     \  |   /     |
      \ |  /      |
       (2)-------(4)
*/