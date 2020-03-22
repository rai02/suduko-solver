#include <bits/stdc++.h>
using namespace std;

bool vacantCell(vector<vector<int>> mat, int &X, int &Y)
{
    for(X = 0; X<mat.size(); X++)
    {
        for(Y = 0; Y<mat[0].size(); Y++)
        {
            if(mat[X][Y] == 0)
            return true;
        }
    }
    return false;
}

bool possible(vector<vector<int>> &mat, int X, int Y, int num)
{
    int N = mat.size();
    for(int i = 0 ; i<N; i++)
    {
        if(num == mat[X][i])
            return false;
    }
    for(int i = 0 ; i<N; i++)
    {
        if(num == mat[i][Y])
            return false;
    }
    int begX = X - (X%3), begY = Y - (Y%3);
    for(int i = begX; i<begX+3;i++)
    {
        for(int j = begY; j<begY+3; j++)
        {
            if(num == mat[i][j])
                return false;
        }
    }
    return true && mat[X][Y] == 0;
}


void printSol(vector<vector<int>> mat)
{
    for(auto x: mat)
    {
        for(auto y : x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
}

bool solve(vector<vector<int>> &mat)
{
    printSol(mat);
    int X, Y;
    if(!vacantCell(mat,X,Y))
        return true;
    for(int i = 1; i<=9; i++)
    {
        if(possible(mat,X,Y,i))
        {
            mat[X][Y] = i;
            if (solve(mat))
            {
                return true;
            }
        }
        mat[X][Y] = 0;

    }
    return false;
}


int main()
{
    vector<vector<int>> mat = 
                     {{3, 0, 6, 5, 0, 8, 4, 0, 0},  
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},  
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    vector<vector<int>> mat1 = 
    {{5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5}
    ,{0,0,0,0,8,0,0,7,9}};
    vector<vector<int>> mat2 = 
    {
    {0,0,0,0,0,5,0,8,0},
    {0,0,0,6,0,1,0,4,3},
    {0,0,0,0,0,0,0,0,0},
    {0,1,0,5,0,0,0,0,0},
    {0,0,0,1,0,6,0,0,0},
    {3,0,0,0,0,0,0,0,5},
    {5,3,0,0,0,0,0,6,1},
    {0,0,0,0,0,0,0,0,4},
    {0,0,0,0,0,0,0,0,0}};
    if(solve(mat2) == true)
        printSol(mat2);
    else 
        cout<<"NO solution";    
}