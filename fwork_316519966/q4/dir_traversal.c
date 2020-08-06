#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define NOPENFD 8 // maximum number of directories that nftw() will hold open simultaneously
#include <libgen.h>
 
int nftwfunc (const char *fpath, const struct stat *sb,
                          int typeflag, struct FTW *ftwbuf)
{
    if(typeflag == FTW_D) //Directory
        printf("D %d %s \n",sb->st_ino,basename(fpath));
    else if(typeflag == FTW_SL) // found symbol link , ignore!!
        return 0;
    else if(typeflag == FTW_F) //File
        printf("F %d %s \n",sb->st_ino,basename(fpath));
 
   return 0;           /* To tell nftw() to continue */
}
 
int main(int argc, char* argv[])
{
    char *dirpath = argv[1];
    int flags = FTW_PHYS; //If  set, do not follow symbolic links. (from man nftw)
 
    nftw(dirpath, nftwfunc, NOPENFD, flags);
}