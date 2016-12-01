#include "../List/arithmetic.h"
#include "tlist.h"
#define MAX 256;

void main(void)
{
setlocale(LC_ALL, "Russian");
char String[256];
int Size=MAX;
cout<<"Введите выражение:"<<endl;
gets (String);
char * working_str;
working_str = new char [Size];
if(FindUnarMinus(String))
	{
		UnarMinus(String,working_str);
	}
	else
	{
		int i=0;
		while(String[i]!='\0')
		{
			working_str[i]=String[i];
			i++;
		}
		working_str[i]='\0';
	}
if (CheckStrAtallChecks(working_str)==false)
	cout<<"Исходное выражение введено некорректно"<<endl;
else
	
{
	double res;
	char * working_str_postf_1 ;
	char * working_str_postf_2 ;
	working_str_postf_1 = new char [Size];
	working_str_postf_2 = new char [Size];
	ConvertInPostfix(working_str,working_str_postf_1);
	InputValuable(working_str_postf_1,working_str_postf_2);
	PointToComma(working_str_postf_2);
	res=ResultsCount(working_str_postf_2);
	cout << "ответ = " << res <<endl;
	delete []working_str_postf_1;
	delete []working_str_postf_2;
}
}