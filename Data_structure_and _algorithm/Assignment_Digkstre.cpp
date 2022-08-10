#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int findMinVertex(int *distance, bool *visited, int n)   // function to find vertex with min distance
{
    int minVertex = -1;
    for (int i = 0; i < n; i++)
        if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
            minVertex = i;
    return minVertex;
}

void dijkstra(int **graph, int n)
{
    int *distance = new int[n];   // array to maintain all nodes weights
    bool *visited = new bool[n];  // array to check whether the nodes are visited or not

    for (int i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;   // initiallizing all distace as infinity except source, done below 
        visited[i] = false;      // as initial all nodes will not visited, so false 
    }

    int start_vertex;   // taking the source vertex
    cout << "Enter the start vertex: ";
    cin >> start_vertex;
    distance[start_vertex] = 0;  // initiallizing its distance as 0, so to take as first node to be proccessed

    for (int i = 0; i < n - 1; i++)   
    {
        int minVertex = findMinVertex(distance, visited, n);   // finding the node with carrying the minimum distance
        visited[minVertex] = true;  // as we visit node, mark in list as true
        for (int j = 0; j < n; j++)  // iterating to relax nodes  
        {
            if (graph[minVertex][j] != 0 && !visited[j])  // checking for adjacent edges AND if node visited or not 
            {
                int dist = distance[minVertex] + graph[minVertex][j];  // calculate distance from min vertex to that node
                if (dist < distance[j])  // if above distance less than already existing wait, relax it
                {
                    distance[j] = dist;
                }
            }
        }
    }
    for (int i=1 ;i<n; i++)  // preinting the min. distance from strat_vertex
    {
        cout << distance[i] << " "; 
    }
    // freeing the memory 
    delete[] visited;  
    delete[] distance;
}

int main()
{
    int n; // no_of_vertices
    int e; // no_of_edges

    cout << "Enter the no. of vertices: ";
    cin >> n;

    cout << "Enter the no. of edges: ";
    cin >> e;

    int **graph = new int *[n]; // creating the dynamic 2D array

    for (int i = 0; i < n; i++)
    {
        graph[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++) // creating the graph (using adjancency matrix form)
    {
        int source, dest, weight;
        cout << "Enter the source: ";
        cin >> source;
        cout << "Enter the destination: ";
        cin >> dest;
        cout << "Enter the weight: ";
        cin >> weight;
        graph[source][dest] = weight;
    }

    dijkstra(graph, n);

    for (int i = 0; i < n; i++)
        delete[] graph[i];

    return 0;
}
// arr[i].push_back(make_pair(value[j], weight));