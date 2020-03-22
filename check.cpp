#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << ':' << x << endl;
#define loop3(i, k, n) for(i=k; i<n; i++)
#define ll  long long 
#define loop(i,n) for(int i=0;i<n;i++)
#define loop2(i,n) for(int i = 1;i<=n;i+=1)
#define pb push_back
#define mp make_pair
#define v1d vector<ll> 
#define v2d vector<vector<ll>>
const int INF = 1e9 +5 ;

/*void fun(vector<vector<int>> &mat)
{
    mat[0][0] = 100;
}*/

void fun(int mat[3][3])
{
    cout<<"this one ";
    mat[0][0] = 100;
}
/*
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
*/
void printSol(int mat[3][3])
{
    for(int i = 0 ; i<3; i++)
    {
        for(int j = 0 ; j<3; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    vector<vector<int>> mat = {{1,2,3},
                               {4,5,6},
                               {7,8,9}};
    int mat1[3][3] = {{1,2,3},
                {4,5,6},
                {7,8,9}};
    fun(mat1);
    printSol(mat1);
    //printSol(mat1);    
}