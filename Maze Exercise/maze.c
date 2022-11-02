#include "./maze.h"

const int dirs[DIR_LEN][DIR_TYPE_LEN] = { {1, 0},{-1, 0},{0, 1},{0, -1} };

void printMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        printf("%c", maze[i][0]);
        for (int j = 1; j < COLS; j++) {
            printf(", %c", maze[i][j]);
        }
        printf("\n");
    }
}

int findPath(char maze[ROWS][COLS]) {
    Stack* moveStack = newStack();
    Stack* reverseStack = newStack();

    int currRow = 0, currCol = 0;
    int nextRow = 0, nextCol = 0;
    int foundKey = 0, foundExit = 0;
    int startRow = -1, startCol = -1;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 's') {
                startRow = i;
                startCol = j;
                break;
            }
        }
        if (startRow > -1)
            break;
    }

    if (startRow < 0 || startRow >= ROWS)
        return 0;
    if (startCol < 0 || startCol >= COLS)
        return 0;

    pushStack(moveStack, startRow, startCol);

    // If the stack is empty, you checked all possible paths.
    while (!isEmptyStack(moveStack)) {
        // If you found both the key and the exit, then you can stop checking.
        if (foundKey && foundExit)
            break;

        // Take out the next cell you need to check.
        popStack(moveStack, &currRow, &currCol);

        /*
        If the cell is an open path, mark it and push it to the reverse stack.
        The reverse stack will be used to undo all the markings.
        */
        if (maze[currRow][currCol] == 'o') {
            maze[currRow][currCol] = 'm';
            pushStack(reverseStack, currRow, currCol);
        }

        /*
        Go over all possible directions (held in the array dirs).
        For every possible direction from the current cell, check whether the
        next cell is a valid move, if yes push it to the stack to check later.
        If it is a key or an exit, mark the key and exit as found.
        */
        for (int i = 0; i < DIR_LEN; i++) {
            nextRow = currRow + dirs[i][0];
            nextCol = currCol + dirs[i][1];
            if (nextRow < 0 || nextRow >= ROWS || nextCol < 0 || nextCol >= COLS)
                continue;

            switch (maze[nextRow][nextCol]) {
            // If the next cell should not be checked, continue the loop.
            case 'x':
            case 'm':
            case 's':
                continue;
            // If the next cell has the key.
            case 'k':
                /*
                If you already found the key, then you already checked the key's cell.
                Therefore continue the loop to next cell to check.
                If you didn't find a key, then the next cell which contains the key can also
                continue to another valid path, so you break here and push it for the next check.
                */
                if (foundKey)
                    continue;
                foundKey = 1;
                break;
            case 'e':
                /*
                If you already found the exit, then you already checked the exist's cell.
                Therefore continue the loop to next cell to check.
                If you didn't find a exist until now, then the next cell which contains the exist can also
                continue to another valid path, so you break here and push this cell for the next check.
                */
                if (foundExit)
                    continue;
                foundExit = 1;
                break;
            }

            // push the next cell's row and collumn to the stack to check later.
            pushStack(moveStack, nextRow, nextCol);
        }
    }

    /*
    Go over all the cells in the reverse stack and undo the markings.
    */
    while (!isEmptyStack(reverseStack)) {
        popStack(reverseStack, &currRow, &currCol);
        if (maze[currRow][currCol] == 'm')
            maze[currRow][currCol] = 'o';
    }

    deleteStack(moveStack);
    deleteStack(reverseStack);
    return foundExit && foundKey;
}