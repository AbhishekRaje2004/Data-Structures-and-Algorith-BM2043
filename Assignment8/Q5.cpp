#include <iostream>
#include <vector>
using namespace std;

int maxSquare(vector<vector<char>>& matrix) 
{
    if (matrix.empty() || matrix[0].empty())
     {
        return 0;
    }

    int rows = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> dp(rows, vector<int>(col, 0));
    int maxSide = 0;

    for (int i = 0; i < rows; i++) 
    {
        dp[i][0] = matrix[i][0] - '0';
        maxSide = max(maxSide, dp[i][0]);
    }

    for (int j = 0; j < col; j++)
     {
        dp[0][j] = matrix[0][j] - '0';
        maxSide = max(maxSide, dp[0][j]);
    }
    for (int i = 1; i < rows; i++)
     {
        for (int j = 1; j < col; j++) 
        {
            if (matrix[i][j] == '1')
             {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }

    return maxSide * maxSide;  
}

int main() {
    int m, n;
    cout << "Enter the number of rows : ";
    cin >> m;
    cout << "Enter the number of columns : ";
    cin >> n;

    vector<vector<char>> matrix(m, vector<char>(n));
    cout << "Enter the  matrix :" << endl;
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; ++j) 
        {
            cin >> matrix[i][j];
        }
    }

    int result = maxSquare(matrix);
    cout << "Maximum area of square filled with 1 : " << result << endl;

    return 0;
}
