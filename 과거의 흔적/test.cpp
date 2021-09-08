/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
unsigned int n, t;   //n은 비트수 t는 차이에 해당하는 자연수
unsigned int i;
char* a;
char* b;

int main(void)
{
   int T, test_case;
       freopen("input.txt", "r", stdin);

      setbuf(stdout, NULL);

   scanf("%d", &T);
   for (test_case = 0; test_case < T; test_case++)
   {      
      /////////////////////////////////////////////////////////////////////////////////////////////
      scanf("%d %d", &n, &t);
      a = (char*)malloc(sizeof(char) * (n + t + 5));
      b = (char*)malloc(sizeof(char) * (n + t + 5));
   
      scanf("%s", &b[1]);
      
      /*
      for (i = 0; b[i]; i++)
      {
         if (i <= t)
         {
            a[i + t] = b[i];
         }
         else if (n - t< i )
         {
            a[i - t] = b[i];
         }
         else      // two a가 되는 인덱스
         {
            if (b[i] == '0')
            {
               a[i - t] = 0;
               a[i + t] = 0;
            }
            else
            {
               if (a[i - t] == 0)
               {
                  a[i + t] = 1;
               }
               else
               {

               }
               if (a[i + t] == 0)
               {

               }
               else
               {

               }
               a[i - t] = 0;
               
            }
         }
      }
      */
      for (i = 1; i <= t; i++)   //one a
      {
         if(i + t <= n)
         a[i + t] = b[i];
      }

      for (i = n; n - t < i; i--)   //one a
      {
         if (i - t >= 1)
         a[i - t] = b[i];
      }
      
      for (i = t + 1; i <= n - t && i + t <= n && i - t >= 1; i++)   //two a
      {
         if (*(b + i) == '0')   //불변
         {
            a[i - t] = '0';
            a[i + t] = '0';
         }
      }

      for (i = t + 1; i <= n - t && i + t <= n && i - t >= 1; i++)   //two a
      {   
         if (*(b + i) == '1')
         {
            if (a[i - t] == '0')   //불변. 오른쪽 빈칸 채움
            {
               a[i + t] = '1';
            }
            else if (a[i - t] == '1')   //가변. 오른쪽 빈칸 채움
            {
               if (a[i + t] != '1')
                  a[i + t] = '0';
            }

            if (*(a + i + t) == '0')   //불변. 왼쪽 빈칸 채움
            {
               a[i - t] = '1';
            }
            else if (*(a + i + t) == '1')   //가변. 왼쪽 빈칸 채움
            {
               if (a[i - t] != '1')
                  a[i - t] = '0';
            }

            if (a[i - t] != '1' && a[i + t] != '1')   //가변. 양 쪽 다 빈칸
            {
               a[i - t] = '0';
               a[i + t] = '1';
            }
         }
      }      
      a[n + 1] = 0;   
       /////////////////////////////////////////////////////////////////////////////////////////////

             // Print the answer to standard output(screen).

      printf("Case #%d\n", test_case + 1);
      printf("%s\n", &a[1]);
      
      free(a);
      free(b);
   }

   return 0;//Your program should return 0 on normal termination.
}