/*=============================================================================
|   Assignment:  pa02 - Calculating an 8, 16, or 32 bit checksum
|                       for a simple ASCII file containing only ASCII
|                       characters. This file is terminated by a NEWLINE
|                       character which has a hexadecimal value of ’0a’.
|
|       Author:  John Seredick
|     Language:  c
|
|   To Compile: gcc -o pa02 pa02.c
|
|   To Execute: c  -> ./pa02
|                         where inputFilename.txt is the ASCII text file
|                           and 8 is the checksum size in bits
|                           (Valid options are 8, 16, & 32)
|
|         Note:  All input files are simple 8 bit ASCII input
|
|        Class:  CIS3360 - Security in Computing - Summer 2021
|   Instructor:  McAlpin
|     Due Date:  Jul 26th
|+=============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int CalcEightBit(char *text)
{
    int result = 0;
    for (int i = 0; i < strlen(text); i++)
        result += text[i];
    return result;
}

int CalcSixteenBit(char *text, int checksum_size, unsigned long int result)
{
    for (int i = 0; i < strlen(text);)
    {
        result += text[i] << 8;
        result += (text[i + 1]);
        i += 2;
    }
    printf("%2d bit checksum is %8lx for all %4d chars\n", checksum_size, result & 0xffff, (int)strlen(text));
    return result;
}

int CalcThirtyTwoBit(char *text, int checksum_size, unsigned long int result)
{
    for (int i = 0; i < strlen(text);)
    {
        result += text[i] << 24;
        result += (text[i + 1]) << 16;
        result += (text[i + 2]) << 8;
        result += (text[i + 3]);
        i += 4;
    }
    printf("%2d bit checksum is %8lx for all %4d chars\n", checksum_size, result & 0xffffffff, (int)strlen(text));
    return result;
}

void print(char *text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (i % 80 == 0)
            printf("\n");
        printf("%c", text[i]);
    }
}

int main(int argc, char **argv)
{
    FILE *ifp = fopen(argv[1], "r");
    char *text, *output, *checksum, count = 'x';
    unsigned long int EightBit = 0, SixteenBit = 0, ThirtyTwoBit = 0;

    int i = 0;
    int size = 0;

    size = atoi(argv[2]);
    if (!(size == 8 || size == 16 || size == 32))
    {
        fprintf(stderr, "Valid checksum sizes are 8, 16, or 32\n");
        return -1;
    }

    text = malloc(sizeof(char) * 1024);

    while (fscanf(ifp, "%c", &count) != EOF && i < 1024)
    {
        text[i] = count;
        i++;
    }

    text[i] = '\0';
    fclose(ifp);

    switch (size)
    {
    case 8:
        EightBit = CalcEightBit(text);
        print(text);
        printf("\n%2d bit checksum is %8lx for all %4d chars\n", size, EightBit & 0xff, (int)strlen(text));
        break;
    case 16:
        if (strlen(text) % 2)
            strcat(text, "X");
        print(text);
        printf("\n");
        SixteenBit = CalcSixteenBit(text, size, SixteenBit);
        break;
    case 32:
        while (strlen(text) % 4)
            strcat(text, "X");
        print(text);
        printf("\n");
        ThirtyTwoBit = CalcThirtyTwoBit(text, size, ThirtyTwoBit);
        break;
    default:
        break;
    }
    return 0;
}

/*=============================================================================
|     I John Seredick (5331481) affirm that this program is
| entirely my own work and that I have neither developed my code together with
| any another person, nor copied any code from any other person, nor permitted
| my code to be copied  or otherwise used by any other person, nor have I
| copied, modified, or otherwise used programs created by others. I acknowledge
| that any violation of the above terms will be treated as academic dishonesty.
+=============================================================================*/