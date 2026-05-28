#include <stdio.h>
#pragma warning(disable:4996)

typedef struct Person
{
    char name[128];
    int age;
    float height;
    float weight;

}Person;

int main(void)
{
    //構造体型を変数にしてあげる
    Person person;

    //名前の入力
    printf("名前を入力してください。\n");
    scanf("%s", &person.name);
    printf("年齢を入力してください。\n");
    scanf("%d", &person.age);
    printf("身長を入力してください。\n");
    scanf("%f", &person.height);
    printf("体重を入力してください。\n");
    scanf("%f", &person.weight);

    printf("名前：%s\n年齢：%d\n身長＆体重：%.2fcm,%.2fkg", person.name, person.age, person.height, person.weight);

    return 0;
}