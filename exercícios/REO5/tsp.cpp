// CPP program to implement traveling salesman
// problem using naive approach.
#include <bits/stdc++.h>
using namespace std;
#define V 5

// implementation of traveling Salesman Problem
double travllingSalesmanProblem(double graph[][V], unsigned int s)
{
	// store all vertex apart from source vertex
	vector<unsigned int> vertex;
	for (unsigned int i = 0; i < V; i++)
	{
		if (i != s)
		{
			vertex.push_back(i);
		}
	}
	// store minimum weight Hamiltonian Cycle.
	double min_path = INT_MAX;
	do
	{

		// store current Path weight(cost)
		double current_pathweight = 0;

		// compute current path weight
		unsigned int k = s;
		for (unsigned int i = 0; i < vertex.size(); i++)
		{
			current_pathweight += graph[k][vertex[i]];
			k = vertex[i];
		}
		current_pathweight += graph[k][s];

		// update minimum
		min_path = min(min_path, current_pathweight);

	} while (next_permutation(vertex.begin(), vertex.end()));

	return min_path;
}

// driver program to test above function
int main()
{

	// matrix representation of graph
	//1  2   3   4

	double graph[][V] = {
		{0, 2.24, 9999, 1.41, 9999},
		{2.24, 0, 1.41, 9999, 9999},
		{9999, 1.41, 0, 9999, 1},
		{1.41, 9999, 9999, 0, 2.83},
		{9999, 9999, 1, 2.83, 0}};

	/*{ { 0, 10, 15, 20 }, 
                       { 10, 0, 35, 25 }, 
                       { 15, 35, 0, 30 }, 
                       { 20, 25, 30, 0 } }; */
	unsigned int s = 0;
	cout << travllingSalesmanProblem(graph, s) << endl;
	return 0;
}
