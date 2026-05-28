#include <stdio.h>
//‚Q‚Â’Ç‰Á‚Ì‚¨‚Ü‚¶‚È‚¢
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int radNumber;

    //—”‚Ì‰Šú‰»
    srand((unsigned int)time(NULL));

    radNumber = rand() % 16;
    printf("ƒ‰ƒ“ƒ_ƒ€‚È”š‚Í%d‚Å‚·\n", radNumber);


    return 0;
}