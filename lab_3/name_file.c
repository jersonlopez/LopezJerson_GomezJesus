#include "name_file.h"

void *nameFile(char *filename, char *name){
    for(int i=0;i<sizeof(filename);i++){
        if(*(filename+i)!='.'){
            *(name+i) = *(filename+i);
        }else{
            i = sizeof(filename);
        }
    }
};