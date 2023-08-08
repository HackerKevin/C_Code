#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
//把头文件都放在"game.h"里面，这样在其他文件直接包含"game.h"即可
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10


//函数的声明
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);//初始化棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);//打印棋盘
void SetMine(char mine[ROWS][COLS], int row, int col);//布置雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//排查雷
void ExplosionSpread(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y, int* pw);//爆炸式展开

