/*********************************************
 * Name:Abhishek Raje
 * Roll No:bm22btech11002
 * Assignment 7
 * Graphs
 * Q3
*********************************************/
#include <iostream>
#include <vector>
using namespace std;
    /****************************************************
    *  Function to applyt depth first search on that index of image
    *****************************************************/
    void dfs(vector<vector<int>>& image, int color_orig, int color, int x, int y) {
        if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] != color_orig) 
        {
            return;//return if index is not inbound of image[i][j] is not the orignal color
        } 
        else {
            image[x][y] = color;//change the color of index cordinates
            //recursively do the same for all neighbours
            dfs(image, color_orig, color, x + 1, y);
            dfs(image, color_orig, color, x, y + 1);
            dfs(image, color_orig, color, x - 1, y);
            dfs(image, color_orig, color, x, y - 1);
            //Time Complexity O(rows *colums)
        }
    }
    /****************************************************
    *  Function to return the correct image after applying the operations
    *****************************************************/
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image.empty() || image[0].empty()) 
        {
            return image;//return the orignal image if size of image is 0 
        }

        int color_orig = image[sr][sc];
        if (color_orig == color) 
        {
            return image;//if color of that index is same as of changed color then return the image
        }
        vector<vector<int>> result_image = image;
        //call the dfs fuction to change the color of the neighbours 
        dfs(result_image, color_orig, color, sr, sc);
        return result_image;
        //Time Complexity O(rows *colums)
    }



int main() {
    int rows, cols, sr, sc, color;

    cout << "Enter the number of rows in the image: ";
    cin >> rows;
    cout << "Enter the number of columns in the image: ";
    cin >> cols;

    vector<vector<int>> image(rows, vector<int>(cols));
    
    cout << "Enter the elements of the image matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> image[i][j];
        }
    }

    cout << "Enter the starting row for flood fill: ";
    cin >> sr;
    cout << "Enter the starting column for flood fill: ";
    cin >> sc;

    cout << "Enter the color for flood fill: ";
    cin >> color;

    vector<vector<int>> result = floodFill(image, sr, sc, color);

    cout << "Resulting Image:" << endl;
    for (const auto& row : result) {
        for (const auto& pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}
