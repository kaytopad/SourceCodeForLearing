#include"20241001_header2_imai.h"

//キャラクター表示
void displayStatus(Character chara)
{
    printf("Name:%S\nHP:%d\nATK:%d\nDEF:%d\nAGL:%d\n",chara.name,chara.HP,chara.ATK,chara.DEF,chara.AGL);
}

void initalizeCharacter(Character chara)
{
    printf("プレイヤー名前を入力してください\n");
    scanf("%S", &chara.name);
    chara.HP = rand() % 41 + 15;
    chara.ATK = rand() % 11 + 5;
    chara.DEF = rand() % 11 + 5;
    chara.AGL = rand() % 11 + 5;

}

int randomValu()
{
    return rand() % 12 + 1;
}

Character checkSkillActication(Character chara, int rand, bool atAnddf)
{
    //攻撃
    if (atAnddf)
    {
        if (rand == 12)
        {
            chara.SKILLFLG |= SKILL_ATTACK;
            printf("%Sは攻撃スキルが発動しました。！\n", chara.name);
        }

    }
    else
    {
        if (rand == 12)
        {
            chara.SKILLFLG |= SKILL_AGILLITY;
            printf("%Sは回避スキルが発動しました。！\n", chara.name);
        }
    }

    if (chara.HP <= chara.HP/2)
    {
        chara.SKILLFLG |= SKILL_DEFENCE;
        printf("%Sは防御スキルが発動しました。！\n", chara.name);

    }

    if (chara.HP <= chara.HP/3)
    {
        chara.SKILLFLG = 0;
        chara.SKILLFLG |= SKILL_KAIOKEN;
        printf("%Sは界王拳が発動しました。！\n", chara.name);

    }

    return chara;
}

Character applySkillBonuses(Character chara)
{
    if (chara.SKILLFLG & SKILL_ATTACK)
    {
        chara.ATK *= 1.5;
    }
    if (chara.SKILLFLG & SKILL_DEFENCE)
    {
        chara.DEF *= 1.5;
    }
    if (chara.SKILLFLG & SKILL_AGILLITY)
    {
        chara.AGL *= 1.5;
    }
    return chara;
}

int calculateDamege(Character attacker, Character deffence, int atkRand, int defRand)
{
    int damege = (attacker.ATK + atkRand) - (deffence.DEF + defRand);

    return damege;


}

void battle(Character player, Character enemy)
{
    int round = 1;
    int playerAction;
    bool plyflg = true;
    bool enyflg = false;

    int plyrand;
    int enyrand;
    while (player.HP > 0 && enemy.HP > 0)
    {
        printf("=====ROUND %d=====\n", round++);

        displayStatus(player);
        printf("\n");
        displayStatus(enemy);

        printf("攻撃もしくは防御を選んでください。攻撃：0　防御：1\n");
        scanf("%d", &playerAction);

        if (playerAction == 0)
        {
            plyrand = randomValu();
            enyrand = randomValu();

            int atk, def;
            atk = player.ATK + plyrand;
            def = enemy.AGL + enyrand;

            if (atk > def or plyrand == 12)
            {
                enemy.HP -= calculateDamege(player,enemy,plyrand,enyrand);
            }
            else if(plyrand >=1)
            {
                printf("Fumble\n");
            }
            else
            {
                printf("交わされました。\n");
            }

            player = checkSkillActication(player, plyrand, plyflg);
            player = applySkillBonuses(player);
            enemy = checkSkillActication(enemy, enyrand, enyflg);
            enemy = applySkillBonuses(enemy);
            plyflg = false;
            enyflg = true;
        }
        if (playerAction == 1 or !plyflg)
        {
            plyrand = randomValu();
            enyrand = randomValu();

            int atk, def;
            atk = enemy.ATK + enyrand;
            def = player.AGL + plyrand;

            if (atk > def or enyrand == 12)
            {
                player.HP -= calculateDamege(enemy, player, enyrand,plyrand);
            }
            else if (enyrand >= 1)
            {
                printf("Fumble\n");
            }
            else
            {
                printf("交わされました。\n");
            }

            player = checkSkillActication(player, plyrand, plyflg);
            player = applySkillBonuses(player);
            enemy = checkSkillActication(enemy, enyrand, enyflg);
            enemy = applySkillBonuses(enemy);


            plyflg = true;
            enyflg = false;

        }
        printf("\n");
    }

    if (player.HP <= 0)
    {
        printf("%Sは勝利しました。\n", player.name);
    }
    else
    {
        printf("%Sは勝利しました。\n", enemy.name);
    }
}