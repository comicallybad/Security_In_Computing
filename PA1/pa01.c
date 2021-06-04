/*=============================================================================
|   Assignment:  pa01 - Encrypting a plaintext file using the Vigenere cipher
|
|     Author:  John Seredick
|     Language:  c
|
|   To Compile: gcc pa01.c -o pa01 -lm
|
|   To Execute: c  -> ./pa01 kX.txt pX.txt
|                         where kX.txt is the keytext file
|                           and pX.txt is plaintext file
|
|         Note:  All input files are simple 8 bit ASCII input
|
|     Class:  CIS3360 - Security in Computing - Summer 2021
|     Instructor:  McAlpin
|     Due Date:  per assignment
|+=============================================================================*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLEN 512

void readVigenereKey(FILE *keyText, char *key)
{
    int i = 0;
    char temp;

    while ((temp = fgetc(keyText)) != EOF)
        if (isalpha(temp))
            key[i++] = tolower(temp);
    key[i++] = '\0';
}

void readPlainText(FILE *plainText, char *plain)
{
    int i = 0;
    char temp;

    while ((temp = fgetc(plainText)) != EOF)
        if (isalpha(temp))
            plain[i++] = tolower(temp);
    while (i < MAXLEN)
        plain[i++] = 'x';
}

void printVigenere(char *key)
{
    int i = 0, j = 0;
    while (key[i] != '\0')
    {
        if (j == 80)
        {
            printf("\n");
            j = 0;
        }
        printf("%c", key[i]);
        i++;
        j++;
    }
}

void print80PerLine(char *plain)
{
    for (int i = 0; i < MAXLEN; i++)
    {
        if (i % 80 == 0)
            printf("\n");
        if (plain[i] != '\n')
            printf("%c", plain[i]);
        else
            printf("x");
    }
}

void readCiphertext(char *plain, char *key, char *cipher)
{
    for (int i = 0, j = 0; i < strlen(plain) - 1; i++)
        if (plain[i] >= 'a' && plain[i] <= 'z')
        {
            cipher[i] = ((char)((plain[i] + key[j] - 2 * 'a') % 26 + 'a'));
            j = ++j % strlen(key);
        }
}

int main(int *argsc, char **argsv)
{
    if (argsc > 3)
    {
        printf("Too many arguments provided.");
        exit(1);
    }

    FILE *keyText = fopen(argsv[1], "r");
    if (keyText == NULL)
    {
        printf("Could not read file: %s", argsv[1]);
        exit(1);
    }

    FILE *plainText = fopen(argsv[2], "r");
    if (keyText == NULL)
    {
        printf("Could not read file: %s", argsv[2]);
        exit(1);
    }

    char *key = malloc(512);
    readVigenereKey(keyText, key);
    printf("\n\nVigenere Key:\n\n");
    printVigenere(key);
    printf("\n");

    char *plain = malloc(512);
    readPlainText(plainText, plain);
    printf("\n\nPlaintext:\n");
    print80PerLine(plain);
    printf("\n");

    char *cipher = malloc(512);
    readCiphertext(plain, key, cipher);
    printf("\n\nCiphertext:\n");
    print80PerLine(cipher);

    printf("\n");

    fclose(keyText);
    fclose(plainText);
    return 0;
}

//512 output

/*=============================================================================
|     I John Seredick (5331481) affirm that this program is
| entirely my own work and that I have neither developed my code together with
| any another person, nor copied any code from any other person, nor permitted
| my code to be copied  or otherwise used by any other person, nor have I
| copied, modified, or otherwise used programs created by others. I acknowledge
| that any violation of the above terms will be treated as academic dishonesty.
+=============================================================================*/