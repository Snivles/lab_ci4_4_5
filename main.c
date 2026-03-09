#include <stdio.h>
#include <string.h>
#include <stdbool.h>
// abcdefg | cde -> abcdefg с 1 словом отличным от w работает исправно
// abcdefg. | cde -> abcdefg с 1 словом отличным от w и точкой на конце работает хорошо и работает исправно
// abcdefg. cdef | cde -> abcdefg с 1 словом словом до точки и 1 после отличными от w работает исправно тк мы не обрабатываем слова за точкой
// abcdefg. FDS | cde -> abcdefg с 1 словом словом до точки и 1 после отличными (c недопустимыми символами) от w работает исправно тк мы не обрабатываем слова за точкой
// abcdefg abcdefg | cde -> abcdefg abcdefg с 2 словам отличными от w работает тоже исправно

// cde | cde -> пустая строка тк слово(одно единственное) совпадает с w все хорошо

// "" | cde -> ОШИБКА тк на вход поступает непустая строка
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


//NULL | abc -> Error with NULL
// abc | NULL -> Error with NULL

//мусор | abc -> Ошибка code 11
// abc | мусор -> Ошибка code 11

int Takeaword(char *s1,int i,char *slovo){
      int count = 0;//счетчик длины нынешнего слова
      bool cheak_razdel = (s1[i+count] == ',' || s1[i+count] == '.' || s1[i+count] == ' ' || s1[i+count] == '\0');
      while (!cheak_razdel){
            if(!(s1[i+count] >= 97 && s1[i+count] <= 122)){return -1;}
            slovo[count] = s1[i+count];
            count++;
            cheak_razdel = (s1[i+count] == ',' || s1[i+count] == '.' || s1[i+count] == ' ' || s1[i+count] == '\0');}
      slovo[count] = '\0';// слово отлично от w
      return count;
}


int SravnenieSlov(char *w, int count,char *slovo){
    int flag = 1;
    size_t lenw = strlen(w);
    if (count != (int)lenw){flag = 0;}// отличны по длине
    else{
      for (int j =0; j < count; j++){
          if (slovo[j]!= w[j] && flag ==1){flag = 0;}}} //сравнение по символам
    return flag;
}



int WritestringwithoutW(char *s1,char *w,int* news1){
    if(!(s1&& w)){return -3;}
    if (s1[0] == '\0'){return -1;}
    int k = 0;
    int i = 0;
    while (w[i] != '\0'){
        if ((w[i] >= 65 && w[i] <= 90)){i++; continue;}
        else if (!(w[i] >= 97 && w[i] <= 122)) {
            return -2;}
        i++;}
    i = 0;
    bool cheak_razdel = s1[i] == ',' || s1[i] == '.' || s1[i] == ' ' || s1[i] == '\0';
    bool cheak_simvol = (s1[i] >= 97 && s1[i] <= 122);
    while (s1[i]!='\0'){
      if (s1[i]=='.'){s1[i] ='\0'; continue;}
      else if (s1[i] == ' ' || s1[i] == ',') {
              i++;  // просто пропускаем разделитель
              continue;}
      else if(!(s1[i] >= 97 && s1[i] <= 122)){return -1;}
      char slovo[1000] = "";
      int count = Takeaword(s1,i,slovo);
      if (count == -1){return -1;}
      int sravnenieslov = SravnenieSlov(w,count,slovo);

      if (sravnenieslov == 0){
              news1[k] = i;
              k++;}
        i+= count;
      cheak_razdel = (s1[i] == ',' || s1[i] == '.' || s1[i] == ' ' || s1[i] == '\0');
      cheak_simvol = (s1[i] >= 97 && s1[i] <= 122);
        if (!(cheak_razdel || cheak_simvol) && s1[i] != '\0') {
            return -1;
        }}
    news1[k] = -1; //конец массива
    return 1;}

int main()
{
    char s1[1000] = "fds";// строка в которой пропускаем
    char w[1000] = "Fasdas";// символ который пропускаем
    int news1[1000] = {0};
    char *null_cheak = NULL;

    int res = WritestringwithoutW(s1,w,news1);
    if(res==1){
      printf("Remaining words:");
      for(int i = 0; news1[i] != -1 ;i++){
          char slovo[1000] = "";
          int len = Takeaword(s1,news1[i],slovo);
          if (len>0){printf("%s",slovo);}
      return 0;}}
    else if(res==-3){printf("Error with NULL");}
    else if(res == -2){printf("Error with string w");}
    else if(res==-1){printf("Error with string s1");}
}
