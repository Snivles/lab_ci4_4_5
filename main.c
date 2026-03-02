#include <stdio.h>
#include <string.h>
//s1 = "a ab abc abcd" s2 = abc / a ab abcd
// s1 = "abc abcd abcd, abcde,abc, a bc adbc. adb" s2 = abc// abcd abcd abcde a bc adbc
// s1 = "abc" s2 = "abcd" / abc
// s1 = "Abc abcd abc" s2 = "abc" /
// s1 = adaf,jjhjabc, abc, , ,abcF. fggh s2= abc / Ошибка
// s1 = i pass point, sorry s2 = sorry / i pass point
char* Validation(char *s1){ // Валидация строки
      int i = 0;
      while (s1[i] != '\0'){
          if (s1[i] == '.'){s1[i] = '\0';
              break;}
          else if (s1[i] == ','){s1[i] = ' '; i++;}
          else if (s1[i] >= 97 && s1[i] <= 122) { i++;}
          else if (s1[i] == ' '){i++;}
          else{
              s1[0] = '\0';
              return "\0";}}

      return s1;}


char* WritestringwithoutW(char *s1,char *w,char *news1){
    size_t lenw = strlen(w);
    int i = 0;
    int k = 0;
    while(s1[i]!='\0'){
          if (s1[i] == ' ') {
              i++;  // просто пропускаем разделитель
              continue;}
          char slovo[1000] = "";
          int count = 0;//счетчик длины нынешнего слова
          int flag = 1;
            while (s1[i+count] != ' ' && s1[i+count] != '\0'){
                  slovo[count] = s1[i+count];
                  count++;}
          slovo[count] = '\0';// слово отлично от w

          if (count != (int)lenw){flag = 0;}
          else{
            for (int j =0; j < count; j++){
                if (slovo[j]!= w[j]){flag = 0; break;}}}
          if (flag == 0){
              if (k>0){news1[k] = ' '; k++;}
              for (int h = 0; slovo[h] != '\0'; h++){
                    news1[k] = slovo[h];
                    k++;}
              news1[k] ='\0';}
        i+= count;}
    return news1;
}
int main()
{
    char s1[1000] = "i pass point, sorry";// строка в которой пропускаем
    char w[1000] = "sorry";// символ который пропускаем
    char news1[1000] = "";
    Validation(s1);
    if (s1[0] == '\0'){printf("Eror"); return 0;}
    WritestringwithoutW(s1,w,news1);
    printf("Remaining words:%s",news1);
    return 0;
}
