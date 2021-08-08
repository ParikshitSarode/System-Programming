#include <stdio.h>

int fibonacci(int n);
int fibarr[100]={1};

int main (int argc, char **argv)
{
   int fib;
   int n;
   for (n = 0; n <= 42; n++) {
      fib = fibonacci(n);
      printf("fibonnaci(%d) = %d\n", n, fib);
   }

   return 0;
}

int fibonacci(int n)
{
   
   int fib;
   if (n <= 0) {
      fib = 0;
      fibarr[0]=0;
   }
   else if (n == 1) {
      fib = 1;
      fibarr[1]=1;
   }
   else {
         fib = fibarr[n -1] + fibarr[n - 2];
         fibarr[n] = fib;
   }
   
   return fib;
}
