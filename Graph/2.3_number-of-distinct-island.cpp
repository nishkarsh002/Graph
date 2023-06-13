// C++ implementation of above approach
#include <bits/stdc++.h>
using namespace std;

// 2D array for the storing the horizontal and vertical
// directions. (Up, left, down, right}
vector<vector<int> > dirs = { { 0, -1 },
							{ -1, 0 },
							{ 0, 1 },
							{ 1, 0 } };

// Function to perform dfs of the input grid
void dfs(vector<vector<int> >& grid, int x0, int y0,
		int i, int j, vector<pair<int, int> >& v)
{
	int rows = grid.size(), cols = grid[0].size();

	if (i < 0 || i >= rows || j < 0
		|| j >= cols || grid[i][j] <= 0)
		return;

	// marking the visited element as -1
	grid[i][j] *= -1;

	// computing coordinates with x0, y0 as base
	v.push_back({ i - x0, j - y0 });

	// repeat dfs for neighbors
	for (auto dir : dirs) {
		dfs(grid, x0, y0, i + dir[0], j + dir[1], v);
	}
}

// Main function that returns distinct count of islands in
// a given boolean 2D matrix
int countDistinctIslands(vector<vector<int> >& grid)
{
	int rows = grid.size();
	if (rows == 0)
		return 0;

	int cols = grid[0].size();
	if (cols == 0)
		return 0;

	set<vector<pair<int, int> > > coordinates;

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {

			// If a cell is not 1
			// no need to dfs
			if (grid[i][j] != 1)
				continue;

			// vector to hold coordinates
			// of this island
			vector<pair<int, int> > v;
			dfs(grid, i, j, i, j, v);

			// insert the coordinates for
			// this island to set
			coordinates.insert(v);
		}
	}

	return coordinates.size();
}

// Driver code
int main()
{
	vector<vector<int> > grid = { { 1, 1, 0, 1, 1 },
								{ 1, 0, 0, 0, 0 },
								{ 0, 0, 0, 0, 1 },
								{ 1, 1, 0, 1, 1 } };

	cout << "Number of distinct islands is "
		<< countDistinctIslands(grid);

	return 0;
}
