#include <stdio.h>
#include <string.h>
int main()
{
    char s1[1000] = "abc, abc abc dabc abcd";// строка в которой пропускаем
    char w[1000] = "abc";// символ который пропускаем
    size_t lenw = strlen(w);
    char news1[1000] = "";

    for (int i = 0; s1[i] != '\0'; i++){
          if (s1[i]=='.'){s1[i+1]='\0';} // конец строки дальше не смотрим
          char slovo[1000] = "";
          int count = 0;//счетчик длины нынешнего слова
          int flag = 1;
          if(s1[i] != ' ' || s1[i] != ','){
              while (s1[i] != ' ' || s1[i] != ',' || s1[i] !='.'){
                  slovo[count] = s1[i];
                  if ( count > (int)lenw && s1[i+count] !=w[count]){
                    flag = 0;
          if (flag ==1){
                  i += lenw -1;}
          else{
                  i += count -1;}}}}
                  printf("Слово отличное от w: %s",slovo);}

    return 0;
}
