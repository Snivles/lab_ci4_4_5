#include <stdio.h>
#include <string.h>
// abcdefg | cde -> abcdefg с 1 словом отличным от w работает исправно
// abcdefg. | cde -> abcdefg с 1 словом отличным от w и точкой на конце работает хорошо и работает исправно
// abcdefg. cdef | cde -> abcdefg с 1 словом словом до точки и 1 после отличными от w работает исправно тк мы не обрабатываем слова за точкой
// abcdefg. FDS | cde -> abcdefg с 1 словом словом до точки и 1 после отличными (c недопустимыми символами) от w работает исправно тк мы не обрабатываем слова за точкой
// abcdefg abcdefg | cde -> abcdefg abcdefg с 2 словам отличными от w работает тоже исправно

// cde | cde -> пустая строка тк слово(одно единственное) совпадает с w все хорошо

// "" | cde -> пустая строка тк мы не вводим никакую строку чтобы в ней что-то менять
// cde | "" -> вся строка cde тк мы ничего не удаляем
// cde | " ", "," -> Error with string w ошибка тк строка не может содержать разделитель она должна быть словом


//a ab abc ab a. a ab abc ab a. | abc -> a ab ab a программа отрабатывает штатно тк идем до точки ( если их несколько до 1 тк дальше уже не смотрим) и удаляем w
//a ab abc ab a. a ab abc ab a. | abc, / abc" " / " "abc / ,abc -> a ab ab a программа отрабатывает штатно и выводит ошибку тк w не может содержать разделители


//FDS . abc | abc -> Error with string s1 работает штатно тк видим не строчную букву и идем к ошибке
//fds . a abc | abc -> fds все работает верно доходим до точки и заканчиваем проходку

// abc abcd. АБС | abc -> abcd работает штатно убираем первое слово , сохраняем 2 и игнорируем все что дальше (из-за того что стоит точка не кидаем в ошибку ввода )
// abc abcd АБС | abc -> Error with string s1 работает штатно убираем первое слово , сохраняем 2 и игнорируем все что дальше (из-за того что стоит точка не кидаем в ошибку ввода)

//abcЛ | abc -> Error with string s1 тк появилась кириллица
// abc | abcЛ -> Error with string w аналогично

// abc,,,,abcd,,,,,,abcde,,,,,,abc | abc -> abcd abcde независимо от кол-во разделителей программа работает штатно

int Compress(char *s1){ // Валидация строки
      int i = 0;
      int flag= 1;
      while (s1[i] != '\0'){
          if (s1[i] == '.'){
              s1[i] = '\0';
              flag = 0;}
          else if (s1[i] == ','){
              s1[i] = ' '; i++;}
          else if (s1[i] >= 97 && s1[i] <= 122){
              i++;}
          else if (s1[i] == ' '){
              i++;}
          else{
              s1[0] = '\0';
              return -1;}
          if (flag==0){
              return 1;}}
      return 1;}


int CleanW(char *w){
      int i=0;
      while (w[i] != '\0'){
          if(w[i] == ' ' || w[i] == ','){
            return -2;}
         if (!(w[i] >= 97 && w[i] <= 122)) {
             return -2;}
          i++;}
      return 1;
}


char* WritestringwithoutW(char *s1,char *w,char *news1){
    if(s1&& w && news1){
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
                if (slovo[j]!= w[j] && flag ==1){flag = 0;}}}
          if (flag == 0){
              if (k>0){news1[k] = ' '; k++;}
              for (int h = 0; slovo[h] != '\0'; h++){
                    news1[k] = slovo[h];
                    k++;}
              news1[k] ='\0';}
        i+= count;}
    return news1;}
    return NULL;
}
int main()
{
    char s1[1000] = "abc,,,,abcd,,,,,,abcde,,,,,,abc ";// строка в которой пропускаем
    char w[1000] = "abc";// символ который пропускаем
    char news1[1000] = "";
    char *null_cheak = NULL;
    int rescompresss1 = Compress(s1);
    int rescleanw = CleanW(w);
    if (rescompresss1 == -1){printf("Error with string s1"); return 0;}
    else if(rescleanw== -2){printf("Error with string w"); return 0;}
    char *res = WritestringwithoutW(s1,w,news1);
    if(res){
      printf("Remaining words:%s",news1);
      return 0;}
    else{
      printf("Error with NULL%s",news1);
      return 0;}
}
