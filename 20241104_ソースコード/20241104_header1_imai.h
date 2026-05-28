#pragma once
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#pragma warning(disable:4996)

struct Student
{
    char name[128];
    int score;
    char grade;
};

/// <summary>
/// ¶“k“ü—ÍŠÖ”
/// </summary>
/// <param name="student">¶“k‚Ì¬Ñ\‘¢‘Ì</param>
void studentInput(Student* student);

/// <summary>
/// ¬Ñ•]‰¿
/// </summary>
/// <param name="student">¶“k‚Ì¬Ñ\‘¢‘Ì</param>
void grade(Student *student);

