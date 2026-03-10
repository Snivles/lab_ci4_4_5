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
int Multipleofanumber(char *s1){
    if (!s1){return -3;}
    if (s1[0]=='\0'){return -1;}
    int i = 0;
    int chislo =0;
    size_t len = strlen(s1);
    //int flag = 0;
    //if (s1[0] == '-'){
        //flag = 1;}
    //if (s1[0] == '\0' || s1[flag] =='\0'){return -1;}
    //i = flag;
    if (s1[i] == ' '){i++;}
    if (s1[len-1] >= 0 && s1[len-1]==' '){len--;}
    for (i; i < (int)len ; i++){
        if(s1[i] < 48 || s1[i]> 57){
            return -1;}
        else{
        int delim = s1[i] - '0';
        if (chislo > (2147483647 - delim) / 10) {
                return -1; }
        chislo = (10 * chislo + delim);}}
    return chislo;
}



int main()
{
    char s1[1000] = " 2147483644";
    char *null_test = NULL;
    int det = 213123;

    int res = Multipleofanumber(s1);
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
