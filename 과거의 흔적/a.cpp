#include <stdio.h>

void printStr(char* s){
   if(*s == '\0') return;
   putchar(*s);
   printStr(s+1);
}

int main(){
   char buf[100];
   scanf("%s", buf);
   printStr(buf);
   return 0;
}