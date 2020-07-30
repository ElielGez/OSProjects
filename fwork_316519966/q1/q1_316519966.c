 #define _BSD_SOURCE
 #include <stdio.h>
 #include <stdlib.h>
 
 char globBuf[65536];            /* 1.Uninitialized data segment */
 int primes[] = { 2, 3, 5, 7 };  /* 2.Initialized data segment */
 
 static int
 square(int x)                   /* 3.Allocated in text section , frame(scope) for square() */
 {
     int result;                 /* 4.Allocated in frame(scope) for square() */
 
     result = x * x;
     return result;              /* 5.Return value passed via register */
 }
 
 static void
 doCalc(int val)                 /* 6.Allocated in text section , frame(scope) for doCalc() */
 {
     printf("The square of %d is %d\n", val, square(val));
 
     if (val < 1000) {
         int t;                  /* 7.Allocated in frame(scope) for doCalc() */
 
         t = val * val * val;
         printf("The cube of %d is %d\n", val, t);
     }
 }
 
 int
 main(int argc, char *argv[])    /* 8.Allocated in text section , frame(scope) for main() */
 {
     static int key = 9973;      /* 9.Initialized data segment */
     static char mbuf[10240000]; /* 10.Uninitialized data segment */
     char *p;                    /* 11.Allocated in frame(scope) for main() */
 
     p = malloc(1024);           /* 12.Points to memory in heap segment */
 
     doCalc(key);
 
     exit(EXIT_SUCCESS);
 }