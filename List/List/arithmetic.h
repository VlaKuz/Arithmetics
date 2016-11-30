#ifndef __ARITHMETIC_STRUCT
#define __ARITHMETIC_STRUCT

#include <iostream>
#include <string>
#include "cstdlib"
#include "tlist.h"

using namespace std;

int Priority(char); //done приоритет
bool Brackets(char *); //done контроль скобок
void UnarMinus(char *,char *); //done запись унарного минуса
bool Operation(char ); //done определение операций
int TypeChar(char );  //done разбиение на лекс.
void ConvertInPostfix (const char* ,char *); //done обр. польская запись
void PointToComma(char *); //done перев. точки в запятую
bool FindUnarMinus(char *); //done определение унар. минуса
bool CheckOperationsInBegEndWithBrack(char* ); //done проверка кор. операций в начале конце выражения и после откр. и перед закрыв. скобками
bool CheckOperationsInSuccession(char *); //done проверка кор. операций на запись их подряд
bool CheckCorrectSymbols(char *); //done проверка кор. записи символов
bool CheckPositionOfDotAndComma(char *); //done кор. расстановки точек и запятых
bool CheckVariable(char *); //done кор. наличия переменных
bool CheckManyVariablesInSuccession(char *); //done кор. записи нескольких переменных подряд
bool CheckStrAtallChecks(char *); //done все проверки корректности вместе взятые 
void FindWritePositVariable (const char *, int * ); //done поиск переменных в выражении
bool CorrectOfNumb(char *); //done кор. ввода числа
double Numb(char *); //done перевод строки в число (atof)
void InputValuable(char *,char *); //done входные параметры переменных
double ResultsCount(char *); //done подсчет выражения


#endif 
