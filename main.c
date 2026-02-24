#include <stdio.h>
#include <string.h>
int main()
{
    char s1[1000] = "00004";
    size_t len = strlen(s1); // вводим длину s1

    for (int i =len-1 ; i>=0;i--){
        if(s1[i] < 48 || s1[i]> 57){
            printf("Строчка не в десятичной сис");
            return 0;}}
    int count = -1; // финальная сумма , -1 тк 0 кратен любому число
    int posled = len-1; // последний символ


    if (len>=2){
          int predposled = len-2;
          count = (s1[posled]-'0') + (s1[predposled]-'0')*10;}
    else {count = s1[posled]-'0';}
    printf("Hello World!\n");
    return 0;
}
