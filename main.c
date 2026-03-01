#include <stdio.h>
#include <string.h>

char* Validation(char *s1){ // Валидация строки
      int i = 0;
      while (s1[i] != '\0'){
          if (s1[i] == '.'){s1[i] = '\0';
              break;}
          else if (s1[i] == ','){s1[i] = ' '; i++;}
          else if (s1[i] >= 97 && s1[i] <= 122){ i++;}
          else if (s1[i] == ' '){i++;}
          else{
              s1[0] = '\0';
              break;}}

      return s1;}

int main()
{
    char s1[1000] = "abcd, abc abc dabc fbcd. abcde";// строка в которой пропускаем
    char w[1000] = "abc";// символ который пропускаем
    size_t lenw = strlen(w);
    char news1[1000] = "";
    int i = 0;

    Validation(s1);


    while(s1[i]!='\0'){
          if (s1[i] == ' ') {
              i++;  // просто пропускаем разделитель
              continue;} // конец строки дальше не смотрим
          char slovo[1000] = "";
          int count = 0;//счетчик длины нынешнего слова
          int flag = 1;
            while (s1[i+count] != ' ' && s1[i+count] != '\0'){
                  slovo[count] = s1[i+count];
                  if ( count > (int)lenw || slovo[count] !=w[count]){
                    flag = 0;}
                  count++;}

          slovo[count] = '\0';

          if (flag ==1){
                i += count;}
          else{
                i += count;
                printf("Слово отличное от w: %s\n",slovo);}}

    return 0;
}
