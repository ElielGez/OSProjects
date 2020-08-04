 #include <stdio.h>
 #include <errno.h>
 #include <stdlib.h>
 
 int main(int argc, char *argv[])
 {
     int pid = atoi(argv[1]);
     if(!pid) {
         printf("Please insert numbers only");
         return 0;
     }
     kill(pid,0);
     if(errno == EPERM){
         printf("Process <%d> exists but we have no permission.\n",pid);
         return 0;
     }
     else if(errno == ESRCH){
         printf("Process <%d> does not exist.\n",pid);
         return 0;
     }
     printf("Process <%d> exists.\n",pid);
     return 0;
 }