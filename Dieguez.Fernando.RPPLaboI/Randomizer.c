#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Randomizer.h"

void startRandomizer()
{
    srand(time(NULL));
    // rand() % (max-min+1) + min
    // min 18
    // max 65
}

char getRandomGender()
{
    int value = rand()% (1-0+1) + 0;
    char ret = 'f';
    if (value == 1)
    {
        ret = 'm';
    }
    return ret;
}

int getRandomAge(int min, int max)
{
    int value = rand()% (max-min+1) + min;
    return value;
}

int getRandomNumber(int min, int max){
    int value = rand()% (max-min+1) + min;
    return value;
}
