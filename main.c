#include <stdio.h>
#include <string.h>
// Abcdef bcd / Aef - Дано одно слово и все буквы англ
// My name is Kirill ail / My nme s Kr - Дано несколько слов пробелы между ними остались все буквы англ
// My name is Kirill ail  /MynmesKr - Дано несколько слов пробелы между ними исчезли тк в s2 есть пробел все буквы англ
// Abcd Abcd / - пустота тк все все буквы совпадают в строчке s1 и в строчке s2 , все буквы англ
// 1234Abcd6 1234 / Abcd6 - Удалились числа , все буквы англ
// АБВГД / АБВГД - Все буквы русские и строчки s1, s2 равны ->Error with NULL!
// Привет xyz / Error with NULL!
//  Hi Мир Hi / Error with NULL!
// Test Тест т / Error with NULL!
// NULL abs / Error with NULL! передаем NULL и возникает ошибка
// пустота abcd / передаем пустоту и тк нечего удалять получается пустота / обратно наборот ничего не удалит и выведет все символы
// a@b#c$ @#$ / получаем ответ abc тк спецсимволы хорошо удалились
// aaa a / пустота , тк повторы все удалились отработала программа корректно
// abcd ура / NULL
char* Stringcompaction(char *s1, char *s2){
    if(s1 && s2){
    int s3[128] = {0};
    int i = 0;
    while(s2[i] != '\0'){
        if (s2[i] < 0 || s2[i] > 127){
          return NULL;}
        s3[(int)s2[i]] = 1;
        i++;

    int index = 0;
    i = 0;
    while (s1[i] != '\0'){
        if (s1[i] < 0 || s1[i] > 127){
          return NULL;}
        int elem = (int)s1[i];
        if (s3[elem]==0){
            s1[index] = s1[i];
            index++;}
        i++;}
    s1[index]='\0';
    return s1;}}
    else{
        return NULL;}}



int main()
{   char s1[1000] = "abcd";
    char s2[1000] = "ура";
    char *nullcheak = NULL;
    char *res = Stringcompaction(s1,s2);

    if (!res){printf("Error with NULL!");}
    else{printf("String s1 with s2 removed: %s\n",s1);}
    return 0;
}
