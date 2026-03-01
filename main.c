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


char* WritestringwithoutW(char *s1,char *w,char *news1){ //функция отбора слов отличных от w в строчке s1
    size_t lenw = strlen(w);
    int i = 0;
    int k = 0;
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

          slovo[count] = '\0';// слово отлично от w
          if (flag != 1){
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
    char s1[1000] = "abcd, abc abc dabc fbcd. abcde";// строка в которой пропускаем
    char w[1000] = "abc";// символ который пропускаем
    char news1[1000] = "";
    Validation(s1);
    WritestringwithoutW(s1,w,news1);
    printf("Слова которые остались: %s",news1);
    return 0;
}
