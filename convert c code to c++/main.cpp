#include <iostream>
#include <vector>

using namespace std;

//define the constant int N
const int N = 40;

//function definition 
inline int sum(int n, vector<int> data)
{
    int sum = 0;

    /**
    iterate through the vector to find 
    the sum
    */

    for(unsigned int i=0;i<n;++i)
        sum += data[i];
    
    //return the sum of the vector 
    return sum;
}


int main()
{
    //declare variables
    int accum =0;
    vector<int> data;
    
    //push data into the vector 
    for(unsigned int i=0;i<N;++i)
        data.push_back(i);

    //call the function to calculate the sum 
    accum = sum(N,data);
    
    //print the integer sum 
    cout<<"sum is :"<<accum<<endl;
    
    return 0;
}