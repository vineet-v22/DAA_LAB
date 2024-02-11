#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>> &grid, int i, int j, int n, int m)
{
    if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1)
    {
        return true;
    }
    return false;
}
void dfs(vector<vector<int>> &grid, int i, int j, int &a, int n, int m)
{
    a++;
    grid[i][j] = 0;
    if (isValid(grid, i + 1, j, n, m))
    {
        dfs(grid, i + 1, j, a, n, m);
    }
    if (isValid(grid, i, j + 1, n, m))
    {
        dfs(grid, i, j + 1, a, n, m);
    }
    if (isValid(grid, i - 1, j, n, m))
    {
        dfs(grid, i - 1, j, a, n, m);
    }
    if (isValid(grid, i, j - 1, n, m))
    {
        dfs(grid, i, j - 1, a, n, m);
    }
    if (isValid(grid, i + 1, j + 1, n, m))
    {
        dfs(grid, i + 1, j + 1, a, n, m);
    }
    if (isValid(grid, i + 1, j - 1, n, m))
    {
        dfs(grid, i + 1, j - 1, a, n, m);
    }
    if (isValid(grid, i - 1, j - 1, n, m))
    {
        dfs(grid, i - 1, j - 1, a, n, m);
    }
    if (isValid(grid, i - 1, j + 1, n, m))
    {
        dfs(grid, i - 1, j + 1, a, n, m);
    }
}
int findMaxArea(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a = 0;
            if (grid[i][j] == 1)
            {
                dfs(grid, i, j, a, n, m);
                ans = max(ans, a);
            }
        }
    }
    return ans;
}

int main()
{
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1; 
    }
    int n, m;
    inputFile >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            inputFile >> grid[i][j];
        }
    }
    int ans = findMaxArea(grid);
    outputFile << "Size of Largest region is : " << ans << endl;

    return 0;
}
