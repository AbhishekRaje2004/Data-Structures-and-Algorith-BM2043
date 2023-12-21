#include<iostream>
using namespace std;

bool is_safe(char **board, int x_cord, int y_cord, int n) {
    for (int row = 0; row < n; row++) {
        if (board[row][y_cord] == 'Q') {
            return false;
        }
        int col_diff = x_cord - row;
        if (y_cord - col_diff >= 0 && board[row][y_cord - col_diff] == 'Q') {
            return false;
        }
        if (y_cord + col_diff < n && board[row][y_cord + col_diff] == 'Q') {
            return false;
        }
    }
    return true;
}
void nqueen(char **board, int x_cord, int n,int &index) {
    if (x_cord == n) {
        cout<<"Solution "<<index<<endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        index++;
        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (is_safe(board, x_cord, col, n)) {
            board[x_cord][col] = 'Q';
            nqueen(board, x_cord + 1, n,index);
            board[x_cord][col] = '.'; 
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the chessboard: ";
    cin >> n;

    char **board = new char *[n];
    for (int i = 0; i < n; i++) {
        board[i] = new char[n];
        for (int j = 0; j < n; j++) {
            board[i][j] = '.';
        }
    }
    int index=1;
    nqueen(board, 0, n,index);
    return 0;
}
//Time Complexity O(n!)
//Space Complexity O(n^2)