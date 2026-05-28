#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)


//íËêî
const int INITIAL_OXYGEN = 3200;
const int MAX_DEPTH = 1000;
const int MIN_MOVE_DIST = 10;
const int MAX_MOVE_DIST = 100;
const int DIST_STEP = 10;
const int OXYGEN_PER_UNIT = 1;
const int POINT_MULTIPLIER = 2;
const int PENALTY_DIVISOR = 10;

/// <summary>
/// 
/// </summary>
/// <param name="depth"></param>
/// <param name="oxygen"></param>
/// <param name="points"></param>
void display_status(int depth, int oxygen, int points);
/// <summary>
/// 
/// </summary>
/// <param name="distance"></param>
/// <param name="points"></param>
/// <returns></returns>
int calculate_consumption(int distance, int points);

/// <summary>/// 
/// </summary>///
/// <param name="move"></param>/// 
/// <returns></returns>
bool is_valid_move(int move);

/// <summary>/// 
/// </summary>/// 
/// <param name="depth"></param>/// 
/// <param name="oxygen"></param>/// 
/// <param name="points"></param>/// 
/// <returns></returns>
int perform_ascent(int depth, int oxygen, int points);



int checkInput(int min, int max);