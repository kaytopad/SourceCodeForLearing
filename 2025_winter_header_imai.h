#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

//定数
// 全カード枚数 (3～35)
const int TOTAL_CARDS = 33;
// 1ゲームで使用する枚数 (33 - 9枚除外)
const int PLAYER_CARDS = 24;
// 初期所持チップ
const int START_CHIPS = 11;
// プレイヤー人数
const int PLAYER_NUM = 2;
// カードの最小値
const int MIN_CARD_VALUE = 3;
/// <summary>
/// 
/// </summary>
/// <param name="deck"></param>
void initialize_deck(int deck[]);
/// <summary>
/// 
/// </summary>
/// <param name="deck"></param>
void shuffle_deck(int deck[]);
/// <summary>
/// 
/// </summary>
/// <param name="player_cards"></param>
/// <param name="chips"></param>
/// <returns></returns>
int calculate_score(int player_cards[], int chips);
/// <summary>
/// 
/// </summary>
/// <param name="p_id"></param>
/// <param name="chips"></param>
/// <param name="current_card"></param>
/// <param name="chips_on_table"></param>
void display_status(int p_id, int chips[], int current_card, int chips_on_table);

// 各ファイルの関数を橋渡しするプロトタイプ宣言