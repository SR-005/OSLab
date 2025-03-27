#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char file[300];
    struct stat sfile;
    printf("Enter the path to file: ");
    scanf("%s", file);
    if(stat(file, &sfile)==-1)
    {
        printf("Error\n");
        return EXIT_FAILURE;
    }
    else
    {
        printf("sf_mods=: %o\n",sfile.st_mode);
        printf("Size: %ld\n",sfile.st_size);
        printf("File Last Accessed: %s\n", ctime(&sfile.st_atime));
        printf("File Last Modified: %s\n", ctime(&sfile.st_mtime));
        printf("User ID: %d\n", sfile.st_uid);
        printf("Number of Links: %d\n", sfile.st_nlink);
        return EXIT_SUCCESS;
    }
}
