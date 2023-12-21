#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySum(const vector<int>& nums) {
    int n = nums.size();
    int maxSum = 0;
    int curr_sum = 0;

    for (int i = 0; i < n; i++) 
    {
        curr_sum = max(nums[i], curr_sum + nums[i]);
        maxSum = max(maxSum, curr_sum);
    }

    return maxSum;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> nums[i];
    }

    int result = maxSubarraySum(nums);
        if (result < 0) 
    {
        result = 0;
    }

    cout << "Maximum subarray sum: " << result << endl;

    return 0;
}
