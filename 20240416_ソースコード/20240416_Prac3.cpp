#include <stdio.h>

int main(void)
{
    //•Ï”éŒ¾
    //int a = 5;
    //int b = 3;

    //printf("a + b = %d\n", a + b);
    //printf("a - b = %d\n", a - b);
    //printf("a * b = %d\n", a * b);
    //printf("a / b = %d\n", a / b);
    //printf("a %% b = %d\n", a % b);

    double a = 5.0;
    double b = 3.0;
    float fa = 5.0f;
    float fb = 3.0f;

    printf("a + b = %f\n", a + b);
    printf("a - b = %f\n", a - b);
    printf("a * b = %f\n", a * b);
    printf("fa / fb = %.32f\n", fa / fb);
    printf("a / b = %.32f\n", a / b);
    printf("a / b = %f\n", a / 0.0);

    return 0;
}