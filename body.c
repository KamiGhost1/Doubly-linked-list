#include "head.h"


void helpMenu(){
     printf("\tSTART WORK:\n -start\n\tEND WORK:\nexit\n");
     printf("\tOPTIONS:\nadd - add new item\nsearch - search item in list\n");
     printf("-i / -o  - in/out files\nshow - print list\n");
     printf("del - deleted Item in list\n");
     printf("inj - injection of Item in list\nhelp - help menu\n");
}

TList *createList(){
    TList *list;
    list = createChain(list);
    return list;
}

TList *createChain(TList *list){
    list = (TList*)malloc(sizeof(TList));
    list->key = NULL;
    list->next = NULL;
    list ->pre = NULL;
    return list;
}

TList *addItem(TList *list,int key){
    TList *ptr;
    if (key==NULL){
        printf("enter key:> ");
        scanf("%d",&key);
    }
    if (list->key != NULL){
        while(list->next != NULL)
            /*if (list->key==key){
                printf("Item exist!\n");
                return NULL;
            }*/
            list = list->next;
        list->next=createChain(list->next);
        ptr = list;
        list = list->next;
        list->pre=ptr;
        list->key = key;
        return list;
    }
    else{
        list->key=key;
    }
}


void printList(TList *list){
    while(1){
        printf("%d\n",list->key);
        if (list->next == NULL)
            break;
        else{
            list=list->next;
        }
    }
}


TList *searchItem(TList *list,int key){
    if (key==NULL){
        printf("enter key:> ");
        scanf("%d",&key);
    }
    while(1){
        if (list->key == key){
            printf("found!\n");
            return list;
        }
        else{
            if (list->next != NULL)
                list=list->next;
            else 
                return NULL;
        }
    }
}



int rmItem(TList *list, int key){
    TList *ptr1, *ptr2;
    printf("enter key:> ");
    scanf("%d",&key);
    list = searchItem(list,key);
    if (list != NULL){
        ptr1 = list->pre;
        ptr2 = list->next;
        list->key=NULL;
        list->next=NULL;
        list->pre=NULL;
        ptr1->next=ptr2;
        printf("deleted!\n");
    }
    else{
        printf("Item not found!\n");
        return 2;
    }
    free(list);
}

void inputFiles(TList *list){
    char *name;
    FILE *f;
    int key;
    name =(char*)malloc(sizeof(char)*BUF);
    printf("enter name of file:> ");
    scanf("%s",name);
    if (NULL==(f=fopen(name,"r"))){
        printf("file not found!\n");
        return 2;
    }
    while (!feof(f)){
        fscanf(f,"%d\n",&key);
        addItem(list,key);
    }
    printf("File add to list!\n");
    free(name);
    fclose(f);
}

void outputFiles(TList *list){
    char *name;
    FILE *f;
    name=(char*)malloc(sizeof(char)*BUF);
    printf("enter name of output file:> ");
    scanf("%s",name);
    f = fopen(name,"w");
    while(1){
        if (list==NULL)
            break;
        fprintf(f,"%d\n",list->key);
        list=list->next;
    }
    printf("list copy in '%s'\n",name);
    fclose(f);
    free(name);
}

TList *injectionItem(TList *list, int key){
    TList *ptr1, *ptr2;
    int injKey;
    if (key==NULL){
        printf("enter key:> ");
        scanf("%d",&key);
    }
    list = searchItem(list,key);
    if (list!=NULL){
        printf("enter key to inject:> ");
        scanf("%d",&injKey);
        ptr1=list;
        ptr2=list->next;
        list->next=createChain(list->next);
        list = list->next;
        list->pre = ptr1;
        list->next = ptr2;
        list->key = injKey;
        printf("Item injected!\n");
        return list;
    }
    printf("Item not found! injection canceled!\n");
    return NULL;
}
