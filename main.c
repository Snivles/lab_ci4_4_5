#include <stdio.h>
#include <string.h>
int main()
{
    char s1[1000] = "4";
    size_t len = strlen(s1); // вводим длину s1

    for (int i =len-1 ; i>=0;i--){
        if(s1[i] < 48 || s1[i]> 57){
            printf("Строчка не в десятичной сис");
            return 0;}}
    int count = -1; // переменная на которую делим  , -1 тк 0 кратен любому число
    int posled = len-1; // последний символ


    if (len>=2){
          int predposled = len-2;
          count = (s1[posled]-'0') + (s1[predposled]-'0')*10;}
    else {count = s1[posled]-'0';}

    if (count%4==0){
      printf("Да, тк число %d кратно 4 ",count);}
    else{
      printf("Нет, тк число %d не кратно 4 ",count);}
    return 0;
}
