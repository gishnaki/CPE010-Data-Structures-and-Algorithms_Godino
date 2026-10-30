#include <iostream>
#include "diaGraph.h"
#include "graphTraversal1.h"
#include "graphTraversal2.h"

int main()
{
    //ILO A
    graphEdge edges[] = {
        // (x, y, w) 
        {0, 1, 2},
        {0, 2, 4},
        {1, 4, 3},
        {2, 3, 2},
        {3, 1, 4},
        {4, 3, 3}
    };

    int N = 6; // Number of vertices in the graph
    int n = sizeof(edges) / sizeof(edges[0]);

    DiaGraph diagraph(edges, n, N);

    std::cout << "ILO A: Adjacency List" << std::endl;
    std::cout << "Graph adjacency list\n(start_vertex, end_vertex, weight):" << std::endl;

    for (int i = 0; i < N; i++) {
        display_AdjList(diagraph.head[i], i);
    }
    std::cout << std::endl;

    //ILO B
    using T = unsigned;

    std::cout << "ILO B.1: Depth-First Search (DFS)" << std::endl;
    DFS::test_DFS<T>();
    std::cout << std::endl;

    std::cout << "ILO B.2: Breadth-First Search (BFS)" << std::endl;
    BFS::test_BFS<T>();

    return 0;
}   