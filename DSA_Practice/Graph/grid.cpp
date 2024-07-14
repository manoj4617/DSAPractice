#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Coordinates{
    int x;
    int y;
};

queue<Coordinates> q;

vector<vector<bool>> visited;
vector<vector<char>> final_matrix;
vector<vector<int>> distance_from;
vector<vector<Coordinates>> parent;

int dr[] = {-1,1,0,0};
int dc[] = {0,0,1,-1};

int ROW, COL;
bool reached_end = false;

// This function takes a 2D vector of any type T and prints it in a grid format.
// It is a templated function that can be used to print any 2D vector.
// The function uses nested loops to iterate through the rows and columns of the grid.
// For each element in the grid, the function uses cout to print the element followed by a space.
// After printing each row, the function prints a newline character to move to the next line.
// The function does not return anything, so it is declared as void.
// The function is templated using the typename keyword and the template parameter is T.
// The function is also defined within angle brackets <> to indicate that it is a template.
// The function is named print_grid and is defined outside of any class.
template<typename T>
void print_grid(vector<vector<T>> grid){
    // Iterate through each row of the grid
    for(int i=0; i<grid.size(); ++i){
        // Iterate through each column of the current row
        for(int j=0; j<grid[i].size(); ++j){
            // Print the element at the current position in the grid followed by a space
            cout << grid[i][j] << " ";
        }
        // Print a newline character to move to the next line
        cout << "\n";
    }
}


void transform_matrix(vector<vector<int>>& matrix, Coordinates& start, Coordinates &end){
    final_matrix = vector<vector<char>>(ROW, vector<char>(COL, '.'));
    for(int i=0 ; i < ROW; ++i){
        for(int j=0 ; j < COL ;++j){
            if(start.x == i && start.y == j){
                final_matrix[i][j] = 'S';
                continue;
            }
            if(end.x == i && end.y == j){
                final_matrix[i][j] = 'E';
                continue;
            }
            if(matrix[i][j] == 1){
                final_matrix[i][j] = '#';
            }
        }
    }
}

/**
 * Explores all four directions from a given point in a grid and performs the
 * following operations:
 * 1. Marks the point as visited.
 * 2. Checks if the point is the end point.
 * 3. Calculates the distance from the start point to the current point.
 * 4. Sets the parent of the current point to the point from which it was
 *    reached.
 * @param row The row index of the point to explore.
 * @param col The column index of the point to explore.
 */
void explore_direction(int row, int col){
    int new_row;
    int new_col;
    for(int i=0;i<4;i++){
        new_row = row + dr[i];
        new_col = col + dc[i];

        // skip if the point is out of bounds
        if(new_row < 0 || new_col < 0 || new_row >= ROW || new_col >= COL) {
            continue;
        }

        // skip if the point is already visited or is a wall
        if(visited[new_row][new_col] == true || final_matrix[new_row][new_col] == '#') {
            continue;
        }

        // mark the point as visited
        visited[new_row][new_col] = true;

        // add the point to the queue
        q.push(Coordinates{new_row, new_col});

        // calculate the distance from the start point to the current point
        distance_from[new_row][new_col] = distance_from[row][col] + 1;

        // set the parent of the current point to the point from which it was
        // reached
        parent[new_row][new_col] = Coordinates{row,col};
    }
}

/**
 * @brief Performs a breadth-first search of the grid.
 *
 * @details
 * This function performs a breadth-first search of the grid starting from the
 * given starting coordinates. It uses a queue to keep track of the nodes to
 * visit. It marks the starting point as visited and then enters a loop where it
 * pops the next node from the queue, marks it as visited, and then adds all of
 * its unvisited neighbors to the queue. It repeats this process until it has
 * visited all nodes in the queue or until it has found the end point.
 *
 * @param startingCoordinates The coordinates of the starting point.
 * @return The coordinates of the end point if it was found, otherwise (-1,-1).
 */
Coordinates GridBFS(const Coordinates& startingCoordinates){
    // mark the starting point as visited
    visited[startingCoordinates.x][startingCoordinates.y] = true;

    // add the starting point to the queue
    q.push(startingCoordinates);

    // set the parent of the starting point to (-1,-1)
    parent[startingCoordinates.x][startingCoordinates.y] = Coordinates{-1,-1};

    // loop until the queue is empty
    while(!q.empty()){
        // get the next point from the queue
        Coordinates current = q.front();
        q.pop();

        // check if the current point is the end point
        if(final_matrix[current.x][current.y] == 'E'){
            // set a flag to indicate that we have reached the end
            reached_end = true;

            // return the coordinates of the end point
            return Coordinates{current.x, current.y};
        }

        // explore all of the neighbors of the current point
        explore_direction(current.x, current.y);
    }

    // return (-1,-1) if we did not find the end point
    return Coordinates{-1,-1};
}

/**
 * @brief Reconstructs the path from the end point back to the start point.
 *
 * @details
 * This function takes in the end point coordinates and reconstructs the path
 * from the end to the start by following the parent pointers. It starts by
 * setting the current point to the end point and then repeatedly updates the
 * current point to be its parent until it reaches the start point or a point
 * with no parent (indicating that it is the start point). It stores each point
 * in the path vector and then reverses the order of the points so that the
 * path is in the correct order from start to end.
 *
 * @param end The coordinates of the end point.
 * @return A vector containing the coordinates of each point in the path from
 *         the start point to the end point.
 */
vector<Coordinates> reconstruct_path(const Coordinates& end){
    // Initialize an empty vector to store the path
    vector<Coordinates> path;
    // Set the current point to the end point
    Coordinates current = end;

    // Loop until the current point is the start point or has no parent
    while(current.x != -1 && current.y != -1){
        // Add the current point to the path
        path.push_back(current);
        // Update the current point to be its parent
        current = parent[current.x][current.y];
    }
     // Reverse the order of the points in the path so that it is in the correct order
     reverse(path.begin(), path.end());

     // Return the path
     return path;

}

void print_path(const vector<Coordinates>& path){
    cout << "Path form start to end: \n";
    for(const auto& coord : path){
        cout << "(" << coord.x << ", " << coord.y << ") ";
    }
    cout << endl;
}

int main(){

    // cout << "Enter the number of rows and columns: \n";
    // cin >> ROW >> COL;
    ROW = 5;
    COL = 5;
    
    // cout << "Enter the grid (0 for valid path and 1 for invalid path): \n";
    vector<vector<int>> matrix(ROW, vector<int>(COL, 0));
    distance_from = vector<vector<int>>(ROW, vector<int>(COL, -1));
    visited = vector<vector<bool>>(ROW, vector<bool>(COL, false));

    
    matrix = {
        {0,0,0,1,0},
        {1,1,0,0,1},
        {0,1,1,0,1},
        {1,1,0,0,1},
        {1,0,0,1,1}
    };

    // for(int i=0; i<ROW; ++i){
    //     for(int j=0; j<COL; ++j){
    //         cin >> matrix[i][j];
    //     }
    // }
    print_grid(matrix);
    Coordinates start, end;
    start.x = 0;
    start.y = 0;

    end.x = 4;
    end.y = 2;

    // cout << "Enter the starting coordinates: \n";
    // cin >> start.x >> start.y;
    // cin >> end.x >> end.y;
    transform_matrix(matrix, start, end);
    cout << endl;
    print_grid(final_matrix);
    parent  = vector<vector<Coordinates>>(ROW, vector<Coordinates>(COL, Coordinates{-1,-1}));
    Coordinates end_point =  GridBFS(start);
    if(end_point.x != -1 && end_point.y != -1){
        cout << "Total moves needed to reach the end: " << distance_from[end_point.x][end_point.y] << "\n";
        vector<Coordinates> path = reconstruct_path(end_point);
        print_path(path);
        for(const auto& coord : path){
            if(final_matrix[coord.x][coord.y] != 'S' && final_matrix[coord.x][coord.y] != 'E'){
                final_matrix[coord.x][coord.y] = '*';
            }
        }
        cout << "\nMatrix with path marked:\n";
        print_grid(final_matrix);
    }
    return 0;
}