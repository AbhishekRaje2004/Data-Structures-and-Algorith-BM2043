#include <iostream>
#include <vector>

using namespace std;

int longestPalindromeSubstring(const string& s)
 {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) 
    {
        dp[i][i] = 1;
    }
    int max_len = 1; 
    for (int i = 0; i < n - 1; i++)
     {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
            max_len = 2;
        }
    }
    for (int len = 3; len <= n; len++) 
    {
        for (int i = 0; i <= n - len; i++) 
        {
            int j = i + len - 1;
            if (dp[i + 1][j - 1] && s[i] == s[j]) 
            {
                dp[i][j] = 1;
                max_len = len;
            }
        }
    }
    return max_len;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    int result = longestPalindromeSubstring(s);
    cout << "Length of the longest palindromic substring: " << result << endl;
    return 0;
}
