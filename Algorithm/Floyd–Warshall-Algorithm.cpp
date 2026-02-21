//Floyd–Warshall Algorithm (All-Pairs Shortest Path)
//Time Complexity: O(n^3)
//Space Complexity: O(n^2)
//The Floyd–Warshall Algorithm is a dynamic programming algorithm used to find the shortest paths in a weighted graph with positive or negative edge weights (but with no negative cycles). The algorithm works by iteratively updating a distance matrix that represents the shortest path between pairs of vertices. The algorithm can be implemented as follows:

//syntax: The graph is represented as an adjacency matrix, where graph[i][j] is the weight of the edge from vertex i to vertex j. If there is no edge, it can be represented as infinity (or a very large number).
//Example usage:    
// vector<vector<int>> graph = {
//     {0, 3, INF, 7},
//     {8, 0, 2, INF},  
//     {5, INF, 0, 1},
//     {2, INF, INF, 0}
// };
// vector<vector<int>> shortestPaths = floydWarshall(graph);
//The algorithm is efficient for small to medium-sized graphs, and it can be used to find the shortest paths between all pairs of vertices in a graph. However, it may not be suitable for large graphs due to its O(n^3) time complexity.

//code implementation:

vector<vector<int>> floydWarshall(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> dist = graph; // Initialize distance matrix with the input graph

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    return dist;
}

//Note: In the above implementation, INF is a constant representing infinity (or a very large number) to indicate that there is no direct edge between two vertices. The algorithm updates the distance matrix by checking if the path through vertex k is shorter than the previously known path from vertex i to vertex j.

