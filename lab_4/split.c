#include "split.h"

void split(char *original, char *partition, char character){
    char tag = MAX_SIZE;
    for(int i=0;i<MAX_SIZE;i++){
        if(*(original+i) != character){
            if(tag==MAX_SIZE){
                *(partition+i) = *(original+i);
            }else{
                *(original+i-tag-1) = *(original+i);                
            }                
        }else{            
            tag = i;
        }
    }
}