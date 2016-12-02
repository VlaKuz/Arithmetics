#include "arithmetic.h"
#include "tlist.h"

void main(void)
{
	setlocale(LC_ALL, "Russian");
	char String[1024];
	int Size=1024;
	char k;
	cout<<"Меню:"<<endl;
	cout<<"1.выражение без параметром"<<endl;
	cout<<"2.выражение с параметра"<<endl;
	cout<<"3.выход"<<endl;
	cin>>k;
	bool temp=true;
	while (temp==true)
	{
	switch (k)
	{
	case '1':
		{  
			system("cls");
			cout<<"Введите выражение:"<<endl;
			cin>>String;
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
				res=ResultsCount(working_str_postf_1);
				cout << "ответ = " << res <<endl;
				_getch();
				delete []working_str_postf_1;
				delete []working_str_postf_2;
				system("cls");
				cout<<"Меню:"<<endl;
				cout<<"1.выражение без параметром"<<endl;
				cout<<"2.выражение с параметра"<<endl;
				cout<<"3.выход"<<endl;
				cin>>k;
			}
			break;
		}
	case '2':
		{
			system("cls");
			cout<<"Введите выражение:"<<endl;
			cin>>String;
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
				_getch();
				delete []working_str_postf_1;
				delete []working_str_postf_2;
				system("cls");
				cout<<"Меню:"<<endl;
				cout<<"1.выражение без параметром"<<endl;
				cout<<"2.выражение с параметра"<<endl;
				cout<<"3.выход"<<endl;
				cin>>k;
			}
			break;
		
		}
	case '3':
		{
			system("cls");
			exit(0);
		
		}
	default:
		{
			system("cls");
			cout<<"Нет такого пункта..."<<endl;
			_getch();
			system("cls");
			cout<<"Меню:"<<endl;
			cout<<"1.выражение без параметром"<<endl;
			cout<<"2.выражение с параметра"<<endl;
			cout<<"3.выход"<<endl;
			cin>>k;
		}
		break;
		
	}
	}
	_getch();
}