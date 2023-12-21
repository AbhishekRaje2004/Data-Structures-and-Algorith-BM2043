#include<iostream>
#include<vector>
using namespace std;
void solve(vector<int> input_arr,vector<int> output_arr,int index,vector<vector<int>> &powerset)
{
    if(index>=input_arr.size())
    {   
        powerset.push_back(output_arr);
        return;
    }
    solve(input_arr,output_arr,index+1,powerset);
    output_arr.push_back(input_arr[index]);
    solve(input_arr,output_arr,index+1,powerset);
}
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> input_arr(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> input_arr[i];
    }

    vector<int> output_arr;
    vector<vector<int>> powerset;

    solve(input_arr, output_arr, 0, powerset);

    cout << "Power Set:" << endl;
    for (const auto& subset : powerset) {
        cout << "[ ";
        for (const auto& element : subset) {
            cout << element << " ";
        }
        cout << "] ";
    }
    cout<<endl;
    return 0;
}
//Time Complexity O(2^n)
//Space Complexity O(2^n)