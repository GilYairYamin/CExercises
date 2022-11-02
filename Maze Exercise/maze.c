#include "./maze.h"

const int dirs[DIR_LEN][DIR_TYPE] = { {1, 0},{-1, 0},{0, 1},{0, -1} };

void printMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        printf("%c", maze[i][0]);
        for (int j = 1; j < COLS; j++) {
            printf(", %c", maze[i][j]);
        }
        printf("\n");
    }
}

void printArr(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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

    if (startRow < 0 || startRow > ROWS)
        return 0;
    if (startCol < 0 || startCol > COLS)
        return 0;

    pushStack(moveStack, startRow, startCol);

    while (!isEmptyStack(moveStack)) {
        if (foundKey && foundExit)
            break;
        popStack(moveStack, &currRow, &currCol);

        if (maze[currRow][currCol] == 'o') {
            maze[currRow][currCol] = 'm';
            pushStack(reverseStack, currRow, currCol);
        }

        for (int i = 0; i < DIR_LEN; i++) {
            nextRow = currRow + dirs[i][0];
            nextCol = currCol + dirs[i][1];
            if (nextRow < 0 || nextRow >= ROWS || nextCol < 0 || nextCol >= COLS)
                continue;
            switch (maze[nextRow][nextCol]) {
            case 'x':
            case 'm':
            case 's':
                continue;
            case 'k':
                if (foundKey)
                    continue;
                foundKey = 1;
                break;
            case 'e':
                if (foundExit)
                    continue;
                foundExit = 1;
                break;
            }
            pushStack(moveStack, nextRow, nextCol);
        }
    }

    while (!isEmptyStack(reverseStack)) {
        popStack(reverseStack, &currRow, &currCol);
        if (maze[currRow][currCol] == 'm')
            maze[currRow][currCol] = 'o';
    }

    deleteStack(moveStack);
    deleteStack(reverseStack);
    return foundExit && foundKey;
}


