#include<stdio.h>
#define ST_POISON       0x01
#define ST_SLEEP        0x02
#define ST_STONE        0x04
#define ST_PARALYSIS    0x08
#define ST_ALL          0x0f
void setStatus(unsigned char &status,unsigned char set)
{
    status = status | set;
}

void resetStatus(unsigned char& status, unsigned char reset)
{
    status = status & (~reset);
}

void showStatus(unsigned char status)
{
    printf("\n現在のステータス:");

    if (!status)
    {
        printf("正常");
        return;
    }

    if (status & ST_POISON)
    {
        printf("どく");
    }
    if (status & ST_SLEEP)
    {
        printf("すいみん");
    }
    if (status & ST_STONE)
    {
        printf("せきか");
    }
    if (status & ST_PARALYSIS)
    {
        printf("まひ");
    }
}

int main() 
{
    unsigned char status = 0;
    showStatus(status);
    setStatus(status, ST_PARALYSIS);
    setStatus(status, ST_POISON|ST_SLEEP);
    showStatus(status);
    resetStatus(status, ST_ALL);
    showStatus(status);
    setStatus(status, ST_ALL);
    showStatus(status);

    return 0;
}