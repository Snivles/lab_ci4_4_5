#include <stdio.h>
#include <string.h>

char* Stringcompaction(char *s1, char *s2){
    int s3[256] = {0};
    for (int i=0; s2[i]!='\0';i++){
            s3[(unsigned char)s2[i]]=1;}
    int index = 0;
    for(int i =0; s1[i] != '\0'; i++){
            if (s3[(unsigned char)s1[i]]==0){
                s1[index] = s1[i];
                index++;}}
    s1[index]='\0';
    return s1;}




int main()
{   char s1[1000] = "abcd";
    char s2[1000] = "abcd";


    Stringcompaction(s1,s2);
    printf("Строка s1 без символов s2 имеет вид %s\n",s1);
    return 0;
}
