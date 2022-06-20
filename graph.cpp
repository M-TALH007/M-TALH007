#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class Graph
{
public:
    int size;
    vector<vector<int>> adjMatrix;
    Graph(int size)
    {
        this->size = size;
        adjMatrix.resize(size, vector<int>(size));
    };
    void addEdge(int node1, int node2)
    {
        if (node1 > size && node2 > size)
        {
            cout << "Out of range";
            return;
        }
        adjMatrix[node1][node2] = 1;
        adjMatrix[node2][node1] = 1;
    }
    void printAdjacencyMatrix()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    void bfsTraversal(int startNode)
    {
        vector<bool> visited;
        visited.resize(size, false);
        queue<int> q;
        visited[startNode] = true;
        q.push(startNode);
        int currentNode;
        while (!q.empty())
        {
            currentNode = q.front();
            cout << currentNode << " ";
            q.pop();
            for (int endNode = 0; endNode < adjMatrix[currentNode].size(); endNode++)
            {
                if (adjMatrix[currentNode][endNode] == 0)
                    continue;
                int adjacent = endNode;
                if (!visited[adjacent])
                {
                    visited[adjacent] = true;
                    q.push(adjacent);
                }
            }
        }
    }

    void dfsTraversal(int node)
    {
        static vector<bool> visited;
        visited.resize(size, false);
        visited[node] = true;
        cout << node << " ";
        for (int endNode = 0; endNode < adjMatrix[node].size(); endNode++)
        {
            if (adjMatrix[node][endNode] == 1 && !visited[endNode])
            {
                dfsTraversal(endNode);
            }
        }
    }
};

int main()
{
    Graph g(7);
    g.addEdge(1, 5);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(2, 6);
    cout << "Adjacency matrix: " << endl;
    g.printAdjacencyMatrix();
    cout << "BFS traversal: " << endl;
    g.bfsTraversal(1);
    cout << endl
         << "DFS traversal: " << endl;
    g.dfsTraversal(1);
    return 0;
}