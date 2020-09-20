
#include "graph.h"


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