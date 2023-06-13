// C++ Program to implement
// the above approach
#include <bits/stdc++.h>
using namespace std;

// n -> is number of nodes in graph
// m -> is number of edges in graph
int n, m ;

// Stack to store the
// visited vertices in
// the Topological Sort
stack<int> s;

// Store Topological Order
vector<int> tsort;

// Adjacency list to store edges
vector<int> adj[int(1e5) + 1];

// To ensure visited vertex
vector<int> visited(int(1e5) + 1);

// Function to perform DFS
void dfs(int u)
{
	// Set the vertex as visited
	visited[u] = 1;

	for (auto it : adj[u]) {

		// Visit connected vertices
		if (visited[it] == 0)
			dfs(it);
	}

	// Push into the stack on
	// complete visit of vertex
	s.push(u);
}

// Function to check and return
// if a cycle exists or not
bool check_cycle()
{
	// Stores the position of
	// vertex in topological order
	unordered_map<int, int> pos;
	int index = 0;

	// Pop all elements from stack
	while (!s.empty()) {
		pos[s.top()] = index;

		// Push element to get
		// Topological Order
		tsort.push_back(s.top());

		index += 1;

		// Pop from the stack
		s.pop();
	}

	for (int i = 0; i < n; i++) {
		for (auto it : adj[i]) {

			// If parent vertex
			// does not appear first
			if (pos[i] > pos[it]) {

				// Cycle exists
				return true;
			}
		}
	}

	// Return false if cycle
	// does not exist
	return false;
}

// Function to add edges
// from u -> v
void addEdge(int u, int v)
{
	adj[u].push_back(v);
}

// Driver Code
int main()
{
	n = 4, m = 5;

	// Insert edges
	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(1, 2);
	addEdge(2, 0);
	addEdge(2, 3);

	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			dfs(i);
		}
	}

	// If cycle exist
	if (check_cycle())
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
