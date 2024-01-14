#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAX = 1000000;

int n; // Number of nodes

// dist[i][j] represents shortest distance to go from i to j

vector<vector<int>> dist;

vector<vector<int>> memo;

int fun(int i, int mask)
{

    if (mask == ((1 << i) | 1))
        return dist[0][i]; 

    if (memo[i][mask] != 0)
        return memo[i][mask];

    int res = MAX; 

    for (int j = 1; j < n; j++)
        if ((mask & (1 << j)) && j != i)
            res = min(res, fun(j, mask & (~(1 << i))) + dist[j][i]);

    return memo[i][mask] = res;
}

int main()
{
    ifstream input("Q3_input.txt");
    ofstream output("Q3_output.txt");

    input >> n;

    dist.resize(n, vector<int>(n, 0));
    memo.resize(n, vector<int>(1 << n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            input >> dist[i][j];

    int ans = MAX;

    for (int i = 1; i < n; i++)
        ans = min(ans, fun(i, (1 << n) - 1) + dist[i][0]); // Assuming the starting node is always 1

    output << "The cost of the most efficient tour = " << ans << endl;

    input.close();
    output.close();

    return 0;
}
