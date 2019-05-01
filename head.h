#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF 20

typedef struct{
    int key;
    struct TList *pre, *next;
}TList;

void helpMenu();
TList *createList();
TList *createChain();
TList *addItem();
void printList(); 
TList *searchItem();
int rmItem(); 
void inputFiles();
void outputFiles();
TList *injectionItem();


typedef struct {
    char cmd[10];
    void (*func)();
}TRoute;



