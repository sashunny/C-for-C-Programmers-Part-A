
#include "prim.h"

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