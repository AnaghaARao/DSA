/* Implement the class SubrectangleQueries which receives a rows x cols rectangle as a matrix of integers in the constructor 
    and supports two methods:

    1. updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)
        Updates all values with newValue in the subrectangle whose upper left coordinate is (row1,col1) and 
        bottom right coordinate is (row2,col2).
    2. getValue(int row, int col)
        Returns the current value of the coordinate (row,col) from the rectangle. */

#include<bits/stdc++.h>
using namespace std;

class SubrectangleQueries {
private:
    vector<vector<int>> rectangle;
public:
    SubrectangleQueries(vector<vector<int>>& rect) {
        this->rectangle = rect;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i = row1 ; i <= row2 ; i++){
            for(int j = col1 ; j <= col2 ; j++){
                rectangle[i][j] =
            }
        }
    }
    
    int getValue(int row, int col) {
        return rectangle[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */