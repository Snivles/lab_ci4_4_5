#include <stdio.h>
#include <string.h>
#include <stdbool.h>
// s1 = 124 s2 = 4 /кратно
// s1 =125 s2 = 4 / нет
// s1 = A1224 s2 = 4/ Ошибка
// s1 = 11124 s2 = 4 / кратно
int Multipleofanumber(char *s1, int chislo){
    int i = 0;
    while(s1[i]!='\0'){
        if(s1[i] < 48 || s1[i]> 57){
            return -1;}
        i++;}
    int ostat = 0;
    while(s1[i] != '\0'){
        int delim = s1[i] - '0';
        ostat = (10 * ostat + delim) % chislo;
        i++;}
    return (ostat);}

int main()
{
    char s1[1000] = "11124";
    int chislo = 4;
    if(Multipleofanumber(s1,chislo)==0){
      printf("Да число кратно 4");}
    else if(Multipleofanumber(s1,chislo)==-1){
      printf("Строчка не в десятичной сис");}
    else{
      printf("Нет число не кратно");}
    return 0;
}
