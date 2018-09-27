#include "main.h"

int main(int argc, char *argv[])
{  
    FILE *outFile;        
    char address[MAX_SIZE];
    char name[MAX_SIZE] = "psinfo-report";
    proc proc_info[10];
    switch(argc){
        case 2:            
            sprintf(address, "/proc/%s/status", argv[1]);
            load_process(address, proc_info);
            show_process(proc_info);
        break;

        case 1:
            show_error();
        break;

        default:
            if (strstr(argv[1], "-l")){
                for(int i=0;i<argc-2;i++){
                    sprintf(address, "/proc/%s/status", argv[i+2]);
                    load_process(address, proc_info);
                    if(!strstr(proc_info->name, "")){
                        show_process(proc_info);
                    }                    
                }
            }else if (strstr(argv[1], "-r")){
                for(int i=0;i<argc-2;i++){
                    strcat(name,"-");                    
                    strcat(name,argv[i+2]);
                }
                strcat(name,".info");
                outFile = fopen (name, "w" );
                for(int i=0;i<argc-2;i++){
                    sprintf(address, "/proc/%s/status", argv[i+2]);
                    load_process(address, proc_info);
                    if(!strstr(proc_info->name, "")){
                        save_process(outFile,proc_info);
                    }else{
                        remove(name);
                    }
                }
                fclose(outFile);
            }else {
                show_error();
            }
        break;                    
    }
    return 0;
};
