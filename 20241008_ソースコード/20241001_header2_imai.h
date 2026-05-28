#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

#define SKILL_ATTACK 0x01
#define SKILL_DEFENCE 0x02
#define SKILL_AGILLITY 0x04
#define SKILL_KAIOKEN 0x07

typedef struct character
{
    char name[20];
    int HP;
    int ATK;
    int DEF;
    int AGL;
    int SKILLFLG;
}Character;
/// <summary>
/// キャラクターステータス表示
/// </summary>
/// <param name="chara">表示するキャラクター</param>
/// <returns></returns>
void displayStatus(Character chara);
/// <summary>
/// キャラクター初期化
/// </summary>
/// <param name="chara">生成するキャラクター</param>
/// <returns>生成したキャラクター</returns>
void initalizeCharacter(Character chara);
/// <summary>
/// ランダム数値生成
/// </summary>
/// <returns>ランダムな数字</returns>
int randomValu();

/// <summary>
/// スキルを発動
/// </summary>
/// <param name="chara">発動キャラクター</param>
/// <param name="rand">ランダムな数字</param>
/// <param name="atAnddf">攻守状態</param>
/// <returns></returns>
Character checkSkillActication(Character chara, int rand,bool atAnddf);

/// <summary>
/// ダメージ計算
/// </summary>
/// <param name="attacker">攻撃した数値</param>
/// <param name="deffence">防御した数値</param>
/// <returns>計算結果</returns>
int calculateDamege(Character attacker, Character deffence, int atkRand, int defRand);

/// <summary>
/// スキル倍率適用
/// </summary>
/// <param name="chara">発動中のキャラクター</param>
/// <returns>倍率付与状態</returns>
Character applySkillBonuses(Character chara);

/// <summary>
/// 戦闘処理
/// </summary>
/// <param name="player">プレイヤー</param>
/// <param name="enemy">CPU</param>
void battle(Character player, Character enemy);
