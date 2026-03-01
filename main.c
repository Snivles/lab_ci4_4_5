#include <stdio.h>
#include <string.h>
#include <stdbool.h>
// s1 = 124 s2 = 4 /кратно
// s1 =125 s2 = 4 / нет
// s1 = A1224 s2 = 4/ Ошибка
// s1 = 11124 s2 = 4 / кратно
int Multipleofanumber(char *s1, int chislo){
    if (chislo < 0){
      printf("Делитель должен быть положительныим числом ");
      return 0;}
    size_t len = strlen(s1); // объявляем длину s1
    for (int i =len-1 ; i>=0;i--){
        if(s1[i] < 48 || s1[i]> 57){
            printf("Строчка не в десятичной сис");
            return 0;}  }
    int ostat = 0;
    for (int i = 0; i <(int)len; i++){
        int delim = s1[i] - '0';
        ostat = (10 * ostat + delim) % chislo;}
    return (ostat);}

int main()
{
    char s1[1000] = "11124";
    int chislo = 4;
    if(Multipleofanumber(s1,chislo)==0){
      printf("Да число кратно 4");}

    else{
      printf("Нет число не кратно");}
    return 0;
}
