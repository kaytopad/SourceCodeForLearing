#include"20241104_header2_imai.h"

void initializePlayer(Player* player, const char* name)
{
     strcpy(player->name,name);
     player->hp = rand() % (55 - 15 + 1) + 15;
     player->attack = rand() % (55 - 15 + 1) + 15;
}

void damagePlayer(Player* player, int damege)
{
    player->hp -= damege;

    if (player->hp < 0)
    {
        player->hp = 0;
    }
}
void battle(Player* player, Player* enemy)
{
    int plyDamge,emyDamege;

    printf("=============戦闘開始=============\n");

    while (player->hp > 0 && enemy->hp >0)
    {
        plyDamge = rand() % (player->attack - 5 + 1) + 5;

        damagePlayer(enemy, plyDamge);
        printf("%sの攻撃！\n%sに%d点のダメージ！！\n%sの残りHP:%d\n",player->name,enemy->name,plyDamge,enemy->name,enemy->hp);

        if (enemy->hp <= 0)
        {
            printf("%sは倒されました。\n", enemy->name);
            break;
        }

        emyDamege = rand() % (enemy->attack - 5 + 1) + 5;
        damagePlayer(player, emyDamege);
        printf("%sの攻撃！\n%sに%d点のダメージ！！\n%sの残りHP:%d\n", enemy->name, player->name, emyDamege, player->name,player->hp);

        if (player->hp <= 0)
        {
            printf("%sは倒されました。\n", player->name);
            break;
        }

        printf("現在：%s HP : %d vs %s HP : %d\n", player->name, player->hp, enemy->name, enemy->hp);
    }

    printf("=============戦闘終了=============\n");
}