#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include "comparison.h"


int compare(){
    DIR *directory_per;
    struct dirent *entry_per;

    directory_per = opendir("output_personal");
    if (directory_per == NULL){
        printf("Error when opening directory_per\n");
        return 1;
    }

    DIR *directory_ori;
    struct dirent *entry_ori;

    directory_ori = opendir("output_original");
    if (directory_ori == NULL){
        printf("Error when opening directory_ori\n");
        return 1;
    }

    DIR *dir_an;
    struct dirent *entry_an;

    dir_an = opendir("analysis");
    if (dir_an == NULL){
        printf("Error when opening dir_an\n");
        return 1;
    }

    char path_per[30], path_ori[30], path_an[30];
    char ch_per[256], ch_ori[256];
    
    while ((entry_per = readdir(directory_per)) != NULL && \
    (entry_ori = readdir(directory_ori)) != NULL){
        
        if (entry_per->d_type == DT_REG && entry_ori->d_type == DT_REG){

            sprintf(path_ori, "output_original/%s", entry_ori->d_name);
            sprintf(path_per, "output_personal/%s", entry_ori->d_name);
            sprintf(path_an, "analysis/%s", entry_ori->d_name);

            FILE *fp_ori;
            fp_ori = fopen(path_ori, "r");
            if (fp_ori == NULL){
                printf("Error, fp_ori file couldn't be opened\n");
                return 1;
            }

            FILE *fp_per;
            fp_per = fopen(path_per, "r");
            if (fp_per == NULL){
                printf("Error, fp_per file couldn't be opened, attention to\
                sprintf. Files must be the same name\n");
                return 1;
            }

            FILE *fp_an;
            fp_an = fopen(path_an, "w");
            if (fp_an == NULL){
                printf("Error, fp_an file couldn't be opened\n");
                return 1;
            }

            int wrong_out = 0;
            int eof_per = 0;
            int eof_ori = 0;

            while (!eof_per || !eof_ori){
                // per == ori; per != ori; ch_ori EOF mas ch_per !EOF;
                // ch_per EOF mas ch_or !EOF; os dois EOF

                if (fgets(ch_per, 256, fp_per) == NULL)
                    eof_per = 1;
                if (fgets(ch_ori, 256, fp_ori) == NULL)
                    eof_ori = 1;
                if (eof_per && eof_ori)
                    break;

                if (ch_per == NULL && ch_ori != NULL){
                    wrong_out = 1;
                    fprintf(fp_an, "?\n");
                }
                else if (ch_per != NULL & ch_ori == NULL){
                    wrong_out = 1;
                    // placing "?" after line and skiping to the next one
                    int length = (int)strlen(ch_per) - 1;
                    ch_per[length] = ' ';
                    ch_per[length + 1] = '?';
                    ch_per[length + 2] = '\n';
                    ch_per[length + 3] = '\0';
                    fprintf(fp_an, ch_per);
                }
                else if(!strcmp(ch_per, ch_ori)){
                    fprintf(fp_an, ch_per);
                }
                else if (strcmp(ch_per, ch_ori)){
                    wrong_out = 1;
                    int length = (int)strlen(ch_per) - 1;
                    ch_per[length] = ' ';
                    ch_per[length + 1] = '?';
                    ch_per[length + 2] = '\n';
                    ch_per[length + 3] = '\0';
                    fprintf(fp_an, ch_per);
                }                
            }

            fclose(fp_an);
            fclose(fp_ori);
            fclose(fp_per);   

            if (wrong_out == 0)
                remove(path_an);

        }
    }
    if (closedir(directory_ori) == -1){
        printf("Error closing directory_ori\n");
        return 1;
    }
    if (closedir(directory_per) == -1){
        printf("Error closing directory_ori\n");
        return 1;
    }
    if (closedir(dir_an) == -1){
        printf("Error closing directory_ori\n");
        return 1;
    }
    return 0;
}