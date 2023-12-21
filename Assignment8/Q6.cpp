#include <iostream>
#include <vector>
using namespace std;

    int pascalTriangle(int rowIndex, int k, vector<vector<int>>& dp) 
    {
        if (dp[rowIndex][k] != -1) 
        {
            return dp[rowIndex][k];
        }
        dp[rowIndex][k] = pascalTriangle(rowIndex - 1, k - 1, dp) + pascalTriangle(rowIndex - 1, k, dp);
        return dp[rowIndex][k];
    }
    vector<int> getRow(int rowIndex) 
    {
        vector<int> ans;
        vector<vector<int>> dp(rowIndex + 1, vector<int>(rowIndex + 1, -1));

        for (int i = 0; i <= rowIndex; i++) 
        {
            for (int k = 0; k <= i; k++) 
            {
                if (k == 0 || k == i) 
                {
                    dp[i][k] = 1;
                }
            }
        }

        for (int i = 0; i <= rowIndex; i++) 
        {
            ans.push_back(pascalTriangle(rowIndex, i, dp));
        }

        return ans;
    }



int main() {

    int rowIndex;
    cout << "Enter the row index for Pascal's Triangle: ";
    cin >> rowIndex;

    vector<int> result = getRow(rowIndex);

    cout << "Row " << rowIndex << " of Pascal's Triangle: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
