#include "head.h"

int main(int C, char **V){
    if (C==1){
        printf("lab2 by Ghost\nVer 0.1\nEnjoy!\n");
        return 0;
    }
    if (C==2){
        if(!strcmp(V[1],"-help")){
            helpMenu();
            return 0;
        }
        if(!strcmp(V[1],"-start")){
            work();
            return 0;
        }
    }
    printf("unknown parameters!\n");
    return 1;
}