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

//fdsd. F |  fds -> fdsd
//fdsd. F | fdsd -> пустота


//ads asd . пав a || ads asd -> asd
//ads asd . пав || ads. -> asd
// char s1[1000] = "today is a beautiful day. The sun is shining, and the sky is blue. I am sitting in the park with my friend. We are drinking coffee and eating cookies. Children are running, and birds are singing. I love this peaceful atmosphere. It is the perfect day to relax and be happy";// строка в которой пропускаем
int GetValidWordCount(char *text)
{
  if (!text){return -3;}
  if (text[0] == '\0'){return -1;}
  int i=0;
  while (text[i] == ' '){i++;}
  if(i > 0){
    int j = 0;
    while (text[i] != '\0'){text[j] = text[i]; i++;j++;}
    text[j] = '\0';}
  bool flag = false;
  bool dot = false;
  i = 0;
  int count= 0;
  while (text[i] != '\0' && !dot){
      if (text[i] == '.'){dot = true; continue;}
      else if(text[i] == ',' || text[i] == ' '){
          if(flag){
              count++;
              flag = false;}
          i++;}
      else if (text[i] >= 97 && text[i] <= 122){flag = 1; i++;}
      else{return -1;}}


  if (flag){count++;}
  return count;
}


int FindLenofWord(char *text,int i){ // получаем на вход s1(исходная строка) , i - начало нового слова , slovo-само слово которое делаем
      int dlina = 0;//счетчик длины нового слова
      if (text[i] == '\0') {
          return -4;}
      bool cheak_razdel = (text[i+dlina] == ',' || text[i+dlina] == ' ' || text[i+dlina] == '\0' || text[i+dlina] == '.');
      while (!cheak_razdel){ // идем пока не встретим разделитель
            dlina++;
            cheak_razdel = (text[i+dlina] == ',' || text[i+dlina] == ' ' || text[i+dlina] == '\0'|| text[i+dlina] == '.');}
      return dlina; // возвращаем длину слова которое нашли
}


int SravnenieSlov(char *slovo1, int start1, char *slovo2, int start2){ // слово1 начало 1 слова слово2 начало 2 слова
    int len1 = FindLenofWord(slovo1,start1);
    int len2 = FindLenofWord(slovo2,start2);
    bool flag = true;
    if (len1 != len2){
          flag = 0;}// отличны по длине
    else{
      for (int j =0; j < len2; j++){
          if (slovo1[start1 + j]!= slovo2[start2+j] && flag ==true){
              flag = false;}}} //сравнение по символам
    return flag;
}
int RabotaCode(char *text, char *slovo, int *massive){
  if (!slovo){return -3;}
  if (!(slovo == NULL || slovo[0] == '\0')){
    if (GetValidWordCount(slovo) < 0){return -2;}
    if (FindLenofWord(slovo,0)<=0){return -2;}}
  int i = 0;
  int k = 0;
  while (text[i] != '\0'){
    if (text[i] == '.'){text[i] = '\0'; continue;}
    else if (text[i] == ',' || text[i] == ' '){i++;}
    else{
        int wordlen = FindLenofWord(text,i);
        if(!SravnenieSlov(text,i,slovo,0)){
            massive[k] = i;
            k++;}
        i = i+wordlen;}}
  massive[k] = -1;
  return 1;
}
void PrintWords(char *text, int *massive) {
    int k = 0;
    while (massive[k] != -1){
        int startw = massive[k];
        int len = FindLenofWord(text, startw);
        printf(" ");
        for (int j = 0; j < len; j++) {
            printf("%c", text[startw + j]);}
        k++;
    }
}

int main()
{
    char s1[1000] = "ads dsa fasd.";// строка в которой пропускаем
    char w[1000] = "ads dsa.";// символ который пропускаем
    int starts[1000] = {0};
    char *null_cheak = NULL;

    int res = GetValidWordCount(s1);
    if (res < 0) {
        if (res == -3){printf("Error with NULL");}
        else{printf("Error string");}
        return 0;
    }
    res = RabotaCode(s1, w, starts);
    if (res < 0){
        if (res == -3){printf("Error with NULL");}
        else{
        printf("Error!");}
        return 0;}
    PrintWords(s1, starts);
    return 0;
}
