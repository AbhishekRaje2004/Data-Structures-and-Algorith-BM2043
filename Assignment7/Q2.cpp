/*********************************************
 * Name:Abhishek Raje
 * Roll No:bm22btech11002
 * Assignment 7
 * Graphs
 * Q2
*********************************************/
#include <iostream>
#include <vector>
using namespace std;
/**************************************************************
 * Function to find all the neighbour of the index containing 1 
***************************************************************/
void findneighbours(vector<vector<char>> &grid, int x, int y) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '0') //checking if the index is within bounds and if the index of grid  is 0( water)
    {
        return;
    } 
    else {
        grid[x][y] = '0';//if index of grid is in bounds and 1(land) then turn it to 0(water)
        //recursively do it for the neighbours of (x,y)
        findneighbours(grid, x + 1, y);
        findneighbours(grid, x, y + 1);
        findneighbours(grid, x - 1, y);
        findneighbours(grid, x, y - 1);
        //Time Complexity O(rows *colums)
    }
}
/**************************************************************
 * Function to return the number of islands
***************************************************************/
int number_of_islands(vector<vector<char>> &grid) {
    if (grid.empty() || grid[0].empty()) 
    {
        return 0;//returning 0 if the grid is empty
    }
    int islands = 0;
    for (int i = 0; i < grid.size(); i++) 
    {
        for (int j = 0; j < grid[0].size(); j++) 
        {
            if (grid[i][j] == '1') 
            {
                islands++;//incrementing islands by 1 if grid index is 1(land) 
                findneighbours(grid, i, j);//call findneighbours to include all the indexes of the island
            }
        }

    }
    return islands;
    //Time Complexity O(rows *colums)
}


int main() {
    int rows, cols;
    cout << "Enter the number of rows : ";
    cin >> rows;
    cout << "Enter the number of column : ";
    cin >> cols;

    vector<vector<char>> grid(rows, vector<char>(cols));
    
    cout << "Enter the elements of the grid ('1' for land, '0' for water):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    int islands = number_of_islands(grid);
    cout << "Number of Islands: " << islands << endl;

    return 0;
}
