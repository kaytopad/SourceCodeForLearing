#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

struct Character 
{
    char Name[20];
    int Hp;
    int atk;
    int def;

};

/// <summary>
/// キャラクター追加
/// </summary>
/// <param name="characters">キャラクター構造体</param>
/// <param name="count">人数</param>
/// <param name="capacity">容量</param>
void addCharacter(Character * characters,int *count,int *capacity);

/// <summary>
/// キャラクターの削除
/// </summary>
/// <param name="characters">キャラクター構造体</param>
/// <param name="count">人数</param>
/// <param name="index">インデックス</param>
void deletCharacter(Character *characters,int *count,int index);

/// <summary>
/// キャラクターの表示
/// </summary>
/// <param name="characters">キャラクター構造体</param>
/// <param name="count">人数</param>
void displayCharacter(Character* characters, int* count);
