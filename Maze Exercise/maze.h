#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "./stack.h"

#define ROWS 5
#define COLS 5

#define DIR_LEN 4
#define DIR_TYPE_LEN 2

int findPath(char[ROWS][COLS]);
void printMaze(char[ROWS][COLS]);