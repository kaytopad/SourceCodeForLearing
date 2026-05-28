#include"map.h"

//定数定義

const int mapChipSize = 64;     //マップチップ1個の大きさ
const int mapXnum = 16;         //マップの横方向
const int mapYnum = 12;         //マップの縦方向
const int mapImgXnum = 2;       //マップチップの画像の横方向チップ数
const int mapImgYnum = 1;       //マップチップの画像の縦方向チップ数

//Map
const unsigned char map[][mapXnum] =
{
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

int mapChipImg[2];              //画像ハンドル配列

//マップの初期化
void mapInit()
{
    //マップの画像を読み込み
    //画像総枚数、横方向個数、縦方向個数、チップ１枚の縦サイズ、チップ１枚の横サイズ、画像配列先頭ポインタ
    LoadDivGraph("img/map.png",mapImgXnum*mapImgYnum,mapImgXnum,mapImgYnum,mapChipSize,mapChipSize,mapChipImg);
}

//マップの描画

void mapDraw()
{
    int x, y;

    for ( y = 0; y < mapYnum; y++)
    {
        for ( x = 0; x < mapXnum; x++)
        {
            //map配列よりブロックの種類を取得
            int imgIndex = map[y][x];
            //インデックスから使って画像ハンドル配列から画像ハンドルを取得
            int imgHandle = mapChipImg[imgIndex];

            DrawGraph(x * mapChipSize,y * mapChipSize,imgHandle,TRUE);
        }
    }
}

//マップの後始末

void mapFinalize()
{
    for (int i = 0; i < mapImgXnum * mapImgYnum; i++)
    {
        DeleteGraph(mapChipImg[i]);
    }
}