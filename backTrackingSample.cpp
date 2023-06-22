#include <iostream>
using namespace std;
#define N 4 // Set the maze size
 
bool solveMazeUtil(int maze[N][N], int x, int y,int sol[N][N]);
 
// A utility function to print solution matrix sol[N][N] 

void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout<<" "<<sol[i][j]<<" ";
        cout<<endl;
    }
}

// Check if x and y is valid index for maze
bool isSafe(int maze[N][N], int x, int y)
{
    // if x and y is out of range return false
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;
    return false;
}
 
// Function to solve the maze. It will look for the right pathway for the object and its destination
bool solveMaze(int maze[N][N])
{
    int sol[N][N] = { { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 } };
    if (solveMazeUtil(maze, 0, 0, sol) == false) {
        cout<<"Solution doesn't exist";
        return false;
    }
    printSolution(sol);
    return true;
}
 
// Recursive function for solving the problem.
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{

    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }
    
    if (isSafe(maze, x, y) == true) {
       //Chech if the current path is already confirmed.
        if (sol[x][y] == 1)
            return false;
        // Mark the block as a confirmed path.
        sol[x][y] = 1;
       // move forward in x dirextion
        if (solveMazeUtil(maze, x + 1, y, sol) == true)
            return true;
        // if there are no confirmed path, go down in y direction
        if (solveMazeUtil(maze, x, y + 1, sol) == true)
            return true;
        /// If there is no path, unmark the path.
        sol[x][y] = 0;
        return false;
    }
    return false;
}
 
int main()
{
    int maze[N][N] = { { 1, 0, 0, 0 },
                       { 1, 1, 1, 1 },
                       { 0, 0, 1, 0 },
                       { 1, 0, 1, 1 } };
    solveMaze(maze);

    return 0;
}