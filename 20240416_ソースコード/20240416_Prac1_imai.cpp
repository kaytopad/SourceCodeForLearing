#include <stdio.h>

int main(void)
{
    //”¼Œa r=5‚Ì‰~‚Ì–ÊÏS‚ğ‹‚ß‚Ü‚µ‚å‚¤B‰~ü—¦‚ÍƒÎ=3.14‚Æ‚µ‚Ü‚·
    //’·•ûŒ`‚Ì–ÊÏ‚ğ‹‚ß‚Ü‚µ‚å‚¤Bc10A‰¡15‚Å‚·B
    //•Ï”éŒ¾
    int r = 5;//”¼Œa
    double Pai = 3.174;//‰~ü—¦
    double S;//‰~‚Ì–ÊÏ
    int vertical = 10;//c‚Ì’·‚³
    int beside = 15;//‰¡‚Ì’·‚³
    int area;//’·•ûŒ`‚Ì–ÊÏ
    //ŒvZ
    S = 2 * r * Pai;
    area = vertical * beside;
    //‰æ–Ê‚É•\¦
    printf("‰~‚Ì–ÊÏ‚Í%.3f‚Å‚·\n’·•ûŒ`‚Ì–ÊÏ‚Í%d‚Å‚·",S,area);
    return 0;
}