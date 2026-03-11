#include <stdio.h>
#include <string.h>
#include <stdbool.h>
// s1 = 124 s2 = 4 /кратно
// s1 =125 s2 = 4 / нет
// s1 = A1224 s2 = 4/ Ошибка
// s1 = 11124 s2 = 4 / кратно
// s1 = 213123124124 s2 = 4 / кратно
// s1 = 1231241243  s2= 4 / Error
// s1 = NULL / s2 = 4 / Error with NULL
// s1 = Дима124 / s2= 4 / Error
// s1 = 2147483647 / s2 = 4 /No
// s1 = -12464 / s2 = 4 / Error
// s1 = -12465 / s2 = 4 / Error
// s1 = 0 / s2 =4 / Yes
// s1 = Abc124Дима; s2 = 4 / Error
// s1 = "" s2 = 4 ; Error
// s1 = "-" s2 = 4 ; Error
// s1 = "1234&" s2 = 4 ; Error
// s1 = a s2 = 4 ; Error
// s1 = 9999999999992 s2 = 4  ; Yes
// s1 = 4 s2 = 4 ; YES
// s1 = 13214124124124 s2 = 4 ; Error
// s1 = 2147483646 s2 = 4 ; NO
// s1 =  2147483644 s2 = 4 ; YES
// s1 = 2147483644 s2 = 4 ; YES
// s1 =      -2147483648   s2= 4; ERROR
// s1 =      -2147483647   s2= 4; NO
// s1 =     -5       s2 = 123123; NO
// s1 = 4444444444 s2 = 4444 ; ERROR string
// s1 = 4444 s2 = 44 ; YES
// s1 = 4444 s2 = -44 ; YES
// s1 = 4444 s2 = 0 ; division on zero
// s1 = 123 s2 = 123123 ; NO
// s1 = -4444 s2 = -44 ; YES
int MakingNumber(char *s1){
    if (!s1){return -3;}
    if (s1[0]=='\0'){return -1;}
    int i = 0;
    int chislo =0;
    int znak = 1;
    size_t len = strlen(s1);
    while (i<= (int)len -1 && s1[i] == ' '){
          i++;}
    if (s1[i]=='-' || s1[i] =='+'){
          if (s1[i]== '-'){
            znak = -1;}
          i++;
}
    while ((int)len - 1 >= i && s1[len-1] == ' '){
          len = (int)len -1;
}
    for (i; i < (int)len ; i++){
        if(s1[i] < 48 || s1[i]> 57){
            return -1;}
        else{
        int delim = s1[i] - '0';
        if (chislo > (2147483647 - delim) / 10) {
                return -1; }
        chislo = (10 * chislo + delim);}}
    return chislo*znak;
}



int main()
{
    char s1[1000] = "     -4444  ";
    char *null_test = NULL;
    int det = -44;

    int res = MakingNumber(s1);
    if (det<0){det = -det;}
    if (det == 0){
      printf("Division on zero");
      return 0;}
    if(res%det==0){
      printf("Yes");}
    else if(res==-1){
      printf("Error string");}
    else if (res==-3){
      printf("ERROR with NULL");}
    else{
      printf("No");}
    return 0;
}
