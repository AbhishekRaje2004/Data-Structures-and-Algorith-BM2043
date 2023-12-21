#include <iostream>
#include <vector>
using namespace std;

int changeCombinations(int amount, vector<int>& coins) 
{
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int coin : coins) 
    {
        for (int i = coin; i <= amount; i++) 
        {
            dp[i] += dp[i - coin];
        }
    }

    return dp[amount];
}

int main() 
{
    int amount;
    cout << "Amount of money: ";
    cin >> amount;

    int num_coins;
    cout << "Number of coin denominations: ";
    cin >> num_coins;

    vector<int> coins(num_coins);
    cout << "Enter the denominations: ";
    for (int i = 0; i < num_coins; i++) 
    {
        cin >> coins[i];
    }

    int ans = changeCombinations(amount, coins);
    cout << "Number of combinations: " << ans << endl;

    return 0;
}
