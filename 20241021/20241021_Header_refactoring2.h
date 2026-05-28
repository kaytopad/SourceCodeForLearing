#pragma once


struct sMapLayer
{
    int** mapDate;
    int mapXNum;
    int mapYNum;
};

/// <summary>
/// 構造体でマップを読み込み
/// </summary>
/// <param name="csvFileName">mapDate</param>
/// <returns>読み込んだファイル</returns>

sMapLayer mapLayerLoader(const char* csvFileName);
