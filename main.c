#include <stdio.h>
#include <string.h>
int main()
{
    char s1[1000] = "125";
    int chislo = 5;
    size_t len = strlen(s1); // вводим длину s1
    for (int i =len-1 ; i>=0;i--){
        if(s1[i] < 48 || s1[i]> 57){
            printf("Строчка не в десятичной сис");
            return 0;}  }
    int ostat = 0;
    for (int i = 0; i <(int)len; i++){
        int delim = s1[i] - '0';
        ostat = (10 * ostat + delim) % chislo;}
    if (ostat == 0){
      printf("Да число кратно 4 тк остаток равен %d",ostat);}
    else{printf("Нет число не кратно тк остаток равкен %d",ostat);}

    return 0;
}
