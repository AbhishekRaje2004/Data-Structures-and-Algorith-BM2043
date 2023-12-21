
#include<iostream>
#include<vector>
using namespace std;

bool is_valid(int x_cord, int y_cord, int n, int m, int Matrix[4][4], vector<vector<bool>>& visited) {
    if (x_cord >= 0 && x_cord <=n && y_cord >= 0 && y_cord <=m && Matrix[x_cord][y_cord] == 0 && !visited[x_cord][y_cord])
    {
        return true;
    }
    return false;
}
//Time Complexity O(1)

void solve(int Matrix[4][4], int x_cord, int y_cord, int x_max, int y_max, vector<char>& path, vector<vector<bool>>& visited) {
    if (x_cord == x_max && y_cord == y_max) {

        for (char c : path) {
            cout << c << " ";
        }
        cout << endl;
        return;
    }

    if (is_valid(x_cord + 1, y_cord, x_max, y_max, Matrix, visited)) {
        path.push_back('D');
        visited[x_cord + 1][y_cord] = true;
        solve(Matrix, x_cord + 1, y_cord, x_max, y_max, path, visited);
        visited[x_cord + 1][y_cord] = false;
        path.pop_back();
    }

    if (is_valid(x_cord - 1, y_cord, x_max, y_max, Matrix, visited)) {
        path.push_back('U');
        visited[x_cord - 1][y_cord] = true;
        solve(Matrix, x_cord - 1, y_cord, x_max, y_max, path, visited);
        visited[x_cord - 1][y_cord] = false;
        path.pop_back();
    }

    if (is_valid(x_cord, y_cord - 1, x_max, y_max, Matrix, visited)) {
        path.push_back('L');
        visited[x_cord][y_cord - 1] = true;
        solve(Matrix, x_cord, y_cord - 1, x_max, y_max, path, visited);
        visited[x_cord][y_cord - 1] = false;
        path.pop_back();
    }

    if (is_valid(x_cord, y_cord + 1, x_max, y_max, Matrix, visited)) {
        path.push_back('R');
        visited[x_cord][y_cord + 1] = true;
        solve(Matrix, x_cord, y_cord + 1, x_max, y_max, path, visited);
        visited[x_cord][y_cord + 1] = false;
        path.pop_back();
    }
}
//Time Complexity O(3^(n^2))

int main() {
    int n = 4, m = 4; 
    cout<<"Maze Solver"<<endl
    cout<<"(0) represents space and (1) represents cell "<<endl;
    vector<char> path;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int Matrix[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    visited[0][0] = true; 

    cout << "Starting Position: (0, 0)" << endl;
    solve(Matrix, 0, 0, n - 1, m - 1, path, visited);

    return 0;
}
//Time Complexity O(3^(n^2))
//space complexity O(n^2)