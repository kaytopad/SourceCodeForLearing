#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#pragma warning(disable:4996)

//構造体Player
struct  Player
{
    char name[50];
    int hp;
    int attack;
};

/// <summary>
/// プレイヤー初期化
/// </summary>
/// <param name="player">プレイヤー構造体変数</param>
/// <param name="name">プレイヤー名前入力値</param>
void initializePlayer(Player* player, const char* name);

/// <summary>
/// プレイヤーにダメージを与える
/// </summary>
/// <param name="player">プレイヤー構造体変数</param>
/// <param name="damege">ダメージ</param>
void damagePlayer(Player *player,int damege);

/// <summary>
/// 戦闘処理
/// </summary>
/// <param name="player"></param>
/// <param name="enemy"></param>
void battle(Player *player,Player *enemy);
