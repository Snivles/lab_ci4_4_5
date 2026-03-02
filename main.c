#include <stdio.h>
#include <string.h>

char* Stringcompaction(char *s1, char *s2){
    int s3[256] = {0};
    int i = 0;
    while(s1[i] != '\0'){
        s3[(unsigned char)s2[i]]=1;
        i++;}

    int index = 0;
    int j = 0;
    while (s1[j] != '\0'){
        if (s3[(unsigned char)s1[j]]==0){
            s1[index] = s1[j];
            index++;}
        j++;}
    s1[index]='\0';
    return s1;}




int main()
{   char s1[1000] = "abcdE";
    char s2[1000] = "abcd";


    Stringcompaction(s1,s2);
    printf("Строка s1 без символов s2 имеет вид %s\n",s1);
    return 0;
}
