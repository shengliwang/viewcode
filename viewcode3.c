/*
* This is a program which show the file 
* integer and byte, developed by vicking 
* at 10-26-2017
* modify at 1-30-2018
* version 1.1
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>



int main(int argc, char * argv[])
{
    size_t len;     //length of you want
    int fd;         //file
    char * file;    //file


    if(argc == 1)
    {
        printf("Usage: %s [-n] file\n", argv[0]);
        return 1;
    }
    //get the number of length
    if (argv[1][0] == '-')
    {
        char tmp[ strlen(argv[1]) ];
        memset(tmp, 0, strlen(argv[1]));

        for(int i = 1; i < strlen(argv[1]); i++)
        {
            tmp[i-1] = argv[1][i];
        }
        len = atoi(tmp);
        file = argv[2];
        fd = open(file, O_RDONLY);
    }
    else
    {
        len = 0;
        file = argv[1];
        fd = open(file, O_RDONLY);
    }

    if(fd < 0)
    {
        perror(file);
        exit(1);
    }
    //set default number of length
    if(len == 0){
        len = lseek(fd, 0, SEEK_END);
        lseek(fd, 0, SEEK_SET);
    }
    //print the result
    unsigned char tmp;
    printf("index\t:int\t,hex\t,char\n");
    for(size_t i = 0; i < len; i++)
    {
        read(fd, &tmp, 1);
        if(tmp == 10)
            printf("%ld\t:%d\t,%x\t,\n", i+1, tmp, tmp);
        else
            printf("%ld\t:%d\t,%x\t,%c\n", i+1, tmp, tmp, tmp);
    }
    close(fd);
}
