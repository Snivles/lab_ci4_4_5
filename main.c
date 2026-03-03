#include <stdio.h>
#include <string.h>
#include <stdbool.h>
// s1 = 124 s2 = 4 /кратно
// s1 =125 s2 = 4 / нет
// s1 = A1224 s2 = 4/ Ошибка
// s1 = 11124 s2 = 4 / кратно
// s1 = 213123124124 s2 = 4 / кратно
// s1 = 1231241243  s2= 4 / Error
// s1 = NULL / s2 = 4 / Error
// s1 = Дима124 / s2= 4 / Error
// s1 = 2147483647 / s2 = 4 /No
// s1 = -12464 / s2 = 4 / Yes
// s1 = -12465 / s2 = 4 / No
// s1 = 0 / s2 =4 / Yes
// s1 = Abc124Дима; s2 = 4 / Error
// s1 = "" s2 = 4 ; Error
// s1 = "-" s2 = 4 ; Error
// s1 = "1234&" s2 = 4 ; Error


bool Validation(char *s1)
{
  if (s1 == NULL){ return false;}

  if (s1[0]=='\0'){return false;}
  int i = 0;
  if (s1[i]=='-'){
      i = 1;
      if (s1[i] == '\0'){return false;}}

  while (s1[i] != '\0'){
      if (s1[i] < 48 || s1[i] > 57){
          return false;
          }
      i++;}
  return true;
}


int Multipleofanumber(char *s1, int chislo){
    if (!Validation(s1)){return -1;}

    if(chislo< 0){
          chislo = -chislo;
          }
    if (chislo==0){
        return -1;}
    int flag = 0;

    if (s1[0] == '-'){
        flag = 1;}
    if (s1[0] == '\0' || s1[flag] =='\0'){return -1;}
      int i = flag;
      while(s1[i]!='\0'){
          if(s1[i] < 48 || s1[i]> 57){
              return -1;}
          i++;}
      i = flag;
      int ostat = 0;
      while(s1[i] != '\0'){
          int delim = s1[i] - '0';
          ostat = (10 * ostat + delim) % chislo;
          i++;}
      return (ostat);
}



int main()
{
    char s1[1000] = "-";
    char *null_test = NULL;
    int chislo = 4;

    int res = Multipleofanumber(s1,chislo);
    if(res==0){
      printf("Yes");}
    else if(res==-1){
      printf("Error");}
    else{
      printf("No");}
    return 0;
}
