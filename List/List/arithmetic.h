#ifndef __ARITHMETIC_STRUCT
#define __ARITHMETIC_STRUCT

#include <iostream>
#include <string>
#include "cstdlib"
#include "tlist.h"

using namespace std;

int Priority(char); //done ���������
bool Brackets(char *); //done �������� ������
void UnarMinus(char *,char *); //done ������ �������� ������
bool Operation(char ); //done ����������� ��������
int TypeChar(char );  //done ��������� �� ����.
void ConvertInPostfix (const char* ,char *); //done ���. �������� ������
void PointToComma(char *); //done �����. ����� � �������
bool FindUnarMinus(char *); //done ����������� ����. ������
bool CheckOperationsInBegEndWithBrack(char* ); //done �������� ���. �������� � ������ ����� ��������� � ����� ����. � ����� ������. ��������
bool CheckOperationsInSuccession(char *); //done �������� ���. �������� �� ������ �� ������
bool CheckCorrectSymbols(char *); //done �������� ���. ������ ��������
bool CheckPositionOfDotAndComma(char *); //done ���. ����������� ����� � �������
bool CheckVariable(char *); //done ���. ������� ����������
bool CheckManyVariablesInSuccession(char *); //done ���. ������ ���������� ���������� ������
bool CheckStrAtallChecks(char *); //done ��� �������� ������������ ������ ������ 
void FindWritePositVariable (const char *, int * ); //done ����� ���������� � ���������
bool CorrectOfNumb(char *); //done ���. ����� �����
double Numb(char *); //done ������� ������ � ����� (atof)
void InputValuable(char *,char *); //done ������� ��������� ����������
double ResultsCount(char *); //done ������� ���������


#endif 
