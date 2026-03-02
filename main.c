#include <stdio.h>
#include <string.h>
#include <locale.h>
// abcdE /Abcd / aE
//Dima and Kirill / il /DmaandKr
//АAВB // АB / A�
//Алфавит русский ас  ������ �����
// Russian language is a Русский язык sgaeс / Ruin lnu i  Р�кий �з�к
// Null / sgaeс / Ошибка
char* Stringcompaction(char *s1, char *s2){
    if(s1 && s2){
    int s3[256] = {0};
    int i = 0;
    while(s2[i] != '\0'){
        s3[(unsigned char)s2[i]]=1;
        i++;}

    int index = 0;
    i = 0;
    while (s1[i] != '\0'){
        if (s3[(unsigned char)s1[i]]==0){
            s1[index] = s1[i];
            index++;}
        i++;}
    s1[index]='\0';
    return s1;}
    else{
        return NULL;}
}



int main()
{   setlocale(LC_ALL, NULL);
    char s1[1000] = "Russian language is a Русский язык";
    char s2[1000] = "sgaeс";
    char *nullcheak = NULL;
    char *res = Stringcompaction(nullcheak,s2);
    if (!res){printf("Ошибка передаем NULL указатель!");}
    else{printf("String s1 with s2 removed: %s\n",s1);}
    return 0;
}
