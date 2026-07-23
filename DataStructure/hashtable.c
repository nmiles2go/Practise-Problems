#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>



#define  MAX_NAME 256
#define TABLE_SIZE 10

typedef struct 
{
    char name[MAX_NAME];
    int age;
}person;

unsigned int hash (char* name)
{
    int length =strlen(name);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        /* code */
        hash_value += name[i];
        hash_value = (hash_value * name[i])% TABLE_SIZE;
    }

    return hash_value;
}

//void hash_function
int main()
{
    printf("\nJULIA hash value => %u", hash("julia"));
    printf("\nMARCO hash value => %u", hash("Macarana"));
    printf("\nGUILA hash value => %u", hash("Aguilarmo"));
    printf("\nPIZZA hash value => %u", hash("ofparis"));
    printf("\nSTORM hash value => %u", hash("STORMrifle"));
    printf("\nFLUFF hash value => %u", hash("FLUFFy"));
    printf("\nSIMBA hash value => %u", hash("SIMBAthesailorman"));
    printf("\nSINBA hash value => %u", hash("SINBAthedevil"));
    printf("\nRISHI hash value => %u", hash("RISHI"));
    printf("\nHENRY hash value => %u", hash("HENRYthe4th"));

    return 0;
}