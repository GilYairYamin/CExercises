#include "./maze.h"
#include <stdio.h>

int main() {
    char maze[ROWS][COLS] = {
        {'k','o','o','o','e'},
        {'x','x','o','x','x'},
        {'o','o','o','o','o'},
        {'x','x','o','x','x'},
        {'s','o','o','o','o'}
    };

    int res = findPath(maze);
    printMaze(maze);
    if (res)
        printf("Yes");
    else
        printf("no");
}
