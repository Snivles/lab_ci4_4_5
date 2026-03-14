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

int Validation(char *text)
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
  i = 0;
  int count= 0;
  while (text[i] != '\0'){
      if(text[i] == ',' || text[i] == ' '){
          if(flag){
              count++;
              flag = false;}
          i++;}
      else if (text[i] >= 97 && text[i] <= 122){flag = 1; i++;}
      else if (text[i] == '.'){continue;}
      else{return -1;}}


  if (flag){count++;}
  if(count ==0){return -1;}
  printf("%s",text);
  return count;
}

int Dlina_W(char *slovo){
  int res = Validation(slovo);
  if(res != 1){return -2;}
  int i = 0;
  int dlina = 0;
  while(slovo[dlina] != '\0' && slovo[dlina] != ' '){
      dlina ++;}
  return dlina;
}

int FindLenofWord(char *text,int i){ // получаем на вход s1(исходная строка) , i - начало нового слова , slovo-само слово которое делаем
      int dlina = 0;//счетчик длины нового слова
      if (text[i] == '\0') {
          return -4;}
      bool cheak_razdel = (text[i+dlina] == ',' || text[i+dlina] == ' ' || text[i+dlina] == '\0');
      while (!cheak_razdel){ // идем пока не встретим разделитель
            dlina++;
            cheak_razdel = (text[i+dlina] == ',' || text[i+dlina] == ' ' || text[i+dlina] == '\0');}
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


int main()
{
    char s1[1000] = "  affasd asd ";// строка в которой пропускаем
    char w[1000] = "  fasd ";// символ который пропускаем
    int news1[1000] = {0};
    char *null_cheak = NULL;



    int res = Validation(s1);
    printf("%d\n",res);
    res = Dlina_W(w);

    printf("%d",res);


    return 0;
}
