#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int>>& grid)
 {
    int rows = grid.size();
    int col = grid[0].size();
    for (int i = 1; i < rows; i++) 
    {
        grid[i][0] += grid[i - 1][0];
    }
    for (int j = 1; j < col; j++) 
    {
        grid[0][j] += grid[0][j - 1];
    }
    for (int i = 1; i < rows; i++) 
    {
        for (int j = 1; j < col; j++) 
        {
            grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }
    }

    return grid[rows - 1][col - 1];
}

int main() 
{
    int rows,col;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> col;

    vector<vector<int>> grid(rows, vector<int>(col));
    cout << "Enter elements:" << endl;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            cin >> grid[i][j];
        }
    }

    int result = minPathSum(grid);
    cout << "Minimum sum of path: " << result << endl;

    return 0;
}
