#include "head.h"

void work(){
    _Bool found;
    int i,key=NULL;
    char cmd[10];
    TList *list;
    TRoute route_table[] = {
        {"add",addItem},
        {"show", printList},
        {"search",searchItem},
        {"del",rmItem},
        {"help",helpMenu},
        {"-i",inputFiles},
        {"-o",outputFiles},
        {"inj", injectionItem}
    };
    list = createList();
    printf("\tSTART WORK!\n");
    while(strcmp(cmd,"exit")){
        found = 0;
        key=NULL;
        printf(">");
        scanf("%s",cmd);
        while(1){
            for(i = 0; i<sizeof(route_table)/sizeof(TRoute);i++){
                if (!strcmp(route_table[i].cmd,cmd)){
                    found =1;
                    route_table[i].func(list,key);
                }
            }
            if (!strcmp(cmd,"exit"))
                break;
            if (!found)
                printf("unknown parameters!\nuse help!\n");
            break;
        }
        if (!strcmp(cmd,"exit"))
                break;
    }
    printf("\tEND WORK! Bye! =)\n");
    free(list);
}