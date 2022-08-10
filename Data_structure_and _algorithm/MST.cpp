#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class edge
{
public:
    int source;
    int dest;
    int weight;
};

bool comparator(edge e1, edge e2) // sorting helper
{
    return e1.weight < e2.weight;
}

int findParent (int v, int * parent)
{
    if (parent[v] == v)
        return v;
    return findParent (parent[v], parent);
}

void kruskal(edge *input, int n, int e) // kruskal algo
{
    sort(input, input + e, comparator); // sorting the the edges in ascending order

    edge *output = new edge[n - 1]; // creating the output array of size (n-1)

    int * parent  = new int[n];
    for (int i=0; i<n ;i++)
        parent[i] = i;
    
    int i = 0;
    int count = 0;  // maintaining no of elements in output array

    while (count != n-1) // iterating till we get n-1 edges
    {
        edge currentEdge = input[i];
        
        // checking if the currentEdge is valid to enter in the output array
        // basically checking if the newly entered edge doesnt form a cycle in tree
        int sourceParent = findParent (currentEdge.source , parent);
        int destParent = findParent (currentEdge.dest , parent);

        if (sourceParent != destParent)
        {
            output[count] = currentEdge;
            count ++ ;
        }
        i++;
    }
    for (int i=0; i<n-1; i++)  // displaying final egdes of output array 
        cout << output[i].source << " <-> " << output[i].dest << ": " << output[i].weight << endl;

}

int main()
{
    int n, e; // n = no_of_vertices, e = no_of_edges
    cout << "Enter the no. of vertices: ";
    cin >> n;
    cout << "Enter the no. of edges: ";
    cin >> e;

    edge *input = new edge[n]; // creating the edge type of input array

    for (int i = 0; i < e; i++) // taking the no. of edges as input
    {
        int s, d, w;
        cout << "Enter the source_vertex: ";
        cin >> s;
        cout << "Enter the dest_vertex: ";
        cin >> d;
        cout << "Enter the weight: ";
        cin >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    kruskal(input, n, e);

    return 0;
}