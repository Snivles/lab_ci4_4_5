#include <stdio.h>
#include <string.h>
int main()
{   char s1[1000] = "Hello World!";
    char s2[1000] = "delo";
    int  s3[256] = {0}; // работаем с ним

    for (int i=0; s2[i]!='\0';i++){
            s3[(unsigned char)s2[i]]=1;}
    int index = 0;
    for(int i =0; s1[i] != '\0'; i++){
            if (s3[(unsigned char)s1[i]]==0){
                s1[index] = s1[i];
                index++;}
}
    printf("Hello World!\n");
    return 0;
}
