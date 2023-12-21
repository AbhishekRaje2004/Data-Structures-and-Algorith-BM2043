/*********************************************
 * Name:Abhishek Raje
 * Roll No:bm22btech11002
 * Assignment 7
 * Graphs
 * Q1
*********************************************/
#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
#include<unordered_set>
using namespace std;
/*********************************************
 * Creating class Graph
*********************************************/
class graph
{
    unordered_map<int, list<int>> adj;//creating map from int to list that is it represents the adjacency list
   vector<vector<int>> AdjMatrix;
    public:

    /*********************************************
    * Function to insert edge
    *********************************************/
void insertEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);

    int maxNode = max(u, v);
    if (maxNode > AdjMatrix.size())
    {
        AdjMatrix.resize(maxNode, vector<int>(maxNode, 0));
    }

    AdjMatrix[u - 1][v - 1] = 1;
    AdjMatrix[v - 1][u - 1] = 1;
}


    /*********************************************
    * Function to print the adjacency list
    *********************************************/
    void printlist()
    {
        for (auto i : adj)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
            {
                cout << j << "  ";
            }
            cout << endl;
            //Time Complexity O(i.first.size()*i.second.size()) or O(rows*colums)
        }
    }
void printMatrix()
{
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < AdjMatrix.size(); i++)
    {
        for (int j = 0; j < AdjMatrix.size(); j++)
        {
            if (j < AdjMatrix[i].size() && AdjMatrix[i][j] == 1)
            {
                cout << "1 "; 
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}



    /*******************************************************
    * Function to return the breadth first search of a graph
    *******************************************************/
    void bfs(int start)
    {
        unordered_set<int> visited;//creating a visited array for keeping track of visited elements
        queue<int> q;

        visited.insert(start);//inserting start in the visted  array
        q.push(start);//pushing start in the queue

        cout << "BFS Traversal starting from node " << start << ": ";

        while (!q.empty())
        {
            int current = q.front();
            cout << current << " ";//printing the front element in the queue
            q.pop();//removing the front element of the queue

            for (int neighbor : adj[current])//inserting all the neighbouts of current node in the queue
            {
                if (visited.find(neighbor) == visited.end())
                {
                    visited.insert(neighbor);
                    q.push(neighbor);
                    //my pushing the neighbours of current node the breadth first search algorithm is implemented
                }
            }
         //Time Complexity O(Nodes+Edges)

        }

        cout << endl;
    }

    /*******************************************************
    * Function to return the depth first search of a graph
    *******************************************************/
    void dfs(int start, unordered_set<int>& visited)
    {
        cout << start << " ";
        visited.insert(start);//inseting the start element in the visisted list

        for (int neighbor : adj[start])//looping over the neighbours of the node
        {
            if (visited.find(neighbor) == visited.end())
            {
                dfs(neighbor, visited);//applying depth first search on the neighbour
            }
        }
        //Time Complexity O(Nodes)
    }

    void depthFirstSearch(int start)
    {
        unordered_set<int> visited;
        cout << "DFS Traversal starting from node " << start << ": ";
        dfs(start, visited);
        cout << endl;
    }
};

int main()
{   
    cout<<"BFS and DFS Implementation of Undirected Graph"<<endl;
    int n, m;
    cout << "Enter Number of Nodes" << endl;
    cin >> n;
    cout << "Enter Number of Edges" << endl;
    cin >> m;
    graph g;
    cout<<"Enter Nodes from 1 to "<<n<<endl;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cout << "Enter Node :";
        cin >> u;
        cout << "Enter Node to   :";
        cin >> v;
        g.insertEdge(u, v);
    }
    cout<<"Adjaceny List"<<endl;
    g.printlist();
    g.printMatrix();
    int startNode;
    cout << "Enter the starting node for BFS and DFS: ";
    cin >> startNode;

    g.bfs(startNode);
    g.depthFirstSearch(startNode);

    return 0;
}