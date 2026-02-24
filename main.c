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
    s1[index] ='\0';
    printf("Строка s1 без символов s2 имеет вид %s\n",s1);
    return 0;
}
