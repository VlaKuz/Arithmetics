#include "../List/List/arithmetic.h"
#include "tlist.h"

int Priority(char s) //done приоритет
{
	int prior;
	switch (s) //определение приоритета операций
	{
		case '(':
	{ prior=0; break;}
		case ')':
	{ prior=0; break;}
		case '+':
	{ prior=1; break;}
		case '-':
	{ prior=1; break;}
		case '*':
	{ prior=2; break;}
		case '/':
	{ prior=2; break;}
	}
return prior;
}/*---------------------------------------------------------------------*/

bool Operation(char s) //done определение операций
{
	bool f=false;
	char signum[]="-+*/"; 
	for(int i=0;i<6;i++)
		if (s==signum[i]) //данный символ является ли знаком операции?
		{
			f=true;
			break;
		}
	return f;
}/*---------------------------------------------------------------------*/

int TypeChar(char s) //done разбиение на лекс.
{
	if ( Operation(s) ) //операция
		return 1;
	else if(isdigit(s)) //число
		return 2;
	else if((s=='(')||(s==')')) //скобка
		return 3;
	else if((s=='.')||(s==',')) //тчк. или зап.
		return 4;
	else if(isalpha(s)) //буква (параметр)
		return 5;
	else 
		return 0; //остальное

}/*---------------------------------------------------------------------*/
 
bool Brackets(char *s) //done контроль скобок
{
	Stack<char> Stack_1;
	int i=0;
	while (s[i] != '\0')
	{
		if (s[i] =='(')
			Stack_1.PushElem('(');
		if (s[i] == ')')
		{
			if (Stack_1.EmptyStack())
			{

				return false; //т.е. в стеке не оказ. откр. скобки 
			}
			else 
				Stack_1.DelElem();
		}
		i++;
	}
	if (Stack_1.EmptyStack()) //в конце концов стек освободился
		return true;
	else
	{
		return false;
	}
}/*---------------------------------------------------------------------*/

void UnarMinus(char *s, char *res) //done запись унарного минуса
{
	int len = strlen(s);
	int j=0;
	if (s[0]=='-') //первый символ оказался -
	{
		res[j++]='0';
		res[j++]='-';
	}
	else
		res[j++]=s[0];
	for (int i=1;i<len;i++)
	{
		if (s[i]=='-') 
		{
			if((s[i-1]=='(')&&((TypeChar(s[i+1])==2)||(TypeChar(s[i+1])==5))) //проверка является ли унарным минус (после откр. скобкой перед симв.) 
			{
				res[j++]='0';
				res[j++]='-';
			}
			else 
				res[j++]='-'; //иначе бинарный
		}
		else
		{
			res[j]=s[i];
			j++;
		}
	}
	res[j]='\0';
}/*---------------------------------------------------------------------*/

void ConvertInPostfix(const char* s,char *res) //done обр. польская запись
{
	Stack<char> Stack_2(256);
	int len = strlen(s);
	int j=0; 
	int m=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='(')
			Stack_2.PushElem('('); //кладем если скобка
		if (s[i]==')')
		{
			char a =Stack_2.DelElem(); //если закрывается удаляем эл-т из ст.
			while (a !='(') //пока не дошли до откр. скобки заносим в массив поэлементно символы
			{
				res[j]=a;
				j++;
				a=Stack_2.DelElem();
			}
		}
		if(Operation(s[i])) //если попалась операция
		{
			if (Stack_2.EmptyStack())
				Stack_2.PushElem(s[i]); //кладем ее в пустой ст.
			else 
			{
				char oper = Stack_2.RetTopElem();
				while(Priority(s[i])<=Priority(oper)) //если не пустой смотрим на приоритет операций
				{
					res[j]=Stack_2.DelElem(); //более "сильную" операцию в ответ
					j++;
					if (Stack_2.EmptyStack()!=true)
						oper=Stack_2.RetTopElem();
					else 
						oper='(';
				}
				Stack_2.PushElem(s[i]); //в итоге клад операц.
			}
		}
		if (TypeChar(s[i])==2) //число
		{
			if ((TypeChar(s[i+1])==2)||(TypeChar(s[i+1])==4))
			{
				res[j]=s[i]; //если число целое или с дес. частью запишем в ответ
				j++;
			}
			else
			{
				res[j]=s[i]; //в ином сл. если дальше уже не число, то сделаем пробел
				j++;
				res[j]=' ';
				j++;
			}
		}
		if (TypeChar(s[i])==5) //параметр
		{
			res[j]=s[i]; //занесли + пробел
			j++;
			res[j]=' ';
			j++;
		}
		if (TypeChar(s[i])==4) //точку или зап. просто заносим
		{
			res[j]=s[i];
			j++;
		}
	}
	while(Stack_2.EmptyStack()!=true) //в конце если стек не пустой выгружаем из него всё оставшееся
	{
		res[j]=Stack_2.DelElem();
		j++;
	}
	res[j]='\0';
}/*---------------------------------------------------------------------*/

void PointToComma(char *s) //done перев. точки в запятую
{
	int len = strlen(s);
	for (int i=0;i<len;i++)
	{
		if (TypeChar(s[i])==4) //перевод из . в ,
		{
			if (s[i]=='.') 
				s[i]=','; 
		}
	}
}/*---------------------------------------------------------------------*/

bool FindUnarMinus(char *s) //done определение унар. минуса
{
	int i=1;
	int f=0;
	int len = strlen(s);
	if (s[0]=='-') //попался унарный минус в самом начале выражения
		f=1;
	while(s[i]!='\0')
	{
		if (s[i]=='-')
		{
			if((s[i-1]=='(')&&((TypeChar(s[i+1])==2)||(TypeChar(s[i+1])==5))) //ловим унарный минус после откр. скобки
			{
				f=1;
				break;
			}
		}
		i++;
	}
	if (f==1)  //попался
		return true;
	else   //не попался
		return false;
}/*---------------------------------------------------------------------*/

bool CheckOperationsInBegEndWithBrack(char* s) //done проверка кор. операций в начале конце выражения и после откр. и перед закрыв. скобками
{
	int len=strlen(s);
	for (int i=1;i<len-1;i++)
	{
	if(Operation(s[i]))
		if((s[i-1]=='(')||(s[i+1]==')'))
		{
			cout<< " операция после открыв. скобки (не унарный -) или перед закрыв.  " << i+1 << endl;
			return false;
		}
	}
	if (Operation(s[0]))
	{
		cout<< " операция в начале выражения (не унарный -) " << endl;
		return false;
	}
	else if (Operation(s[len-1]))
	{
			cout<< " операция в конце выражения " << len << endl;
			return false;
	}
	return true;
}/*---------------------------------------------------------------------*/

bool CheckOperationsInSuccession(char *s) //done проверка кор. операций на запись их подряд
{
	int len=strlen(s);
	for (int i=0;i<len-1;i++)
	{
		if (Operation(s[i]))
		{
			if (Operation(s[i+1]))
			{
				cout<< " 2 операции подряд " << i+1 << " и " << i+2 << endl;
				return false;
			}
		}
	}
		return true;
}/*---------------------------------------------------------------------*/

bool CheckCorrectSymbols(char *s) //done проверка кор. записи символов
{
	int len = strlen(s);
	for (int i=0;i<len;i++)
		if(TypeChar(s[i])==0)
		{
			cout << " Посторонний символ " << i+1 <<endl;
			return false;
		}
		return true;
}/*---------------------------------------------------------------------*/

bool CheckPositionOfDotAndComma(char *s) //done кор. расстановки точек и запятых
{

	int len = strlen(s);
	if ((TypeChar(s[0])==4)||(TypeChar(s[len-1])==4))
		{
			cout << " Точка или запятая в начале или конце выражения " <<endl;
			return false;
		}
	else 
	{
		for (int i=1;i<len-1;i++)
			if(TypeChar(s[i])==4)
			{
				if((TypeChar(s[i-1])!=2)||(TypeChar(s[i+1])!=2))
				{
					cout << " Точка или запятая используется не с числом  " <<endl;
					return false;
				}
			}
			return true;
	}	
}/*---------------------------------------------------------------------*/

bool CheckVariable(char *s) //done кор. наличия переменных
{
	int len = strlen(s);
	for (int i=0;i<len;i++)
	{
		if(TypeChar(s[i])==5) //проверяем налич. переменных
			return true;
	}
		return false;
}/*---------------------------------------------------------------------*/
bool CheckManyVariablesInSuccession(char *s) //done кор. записи нескольких переменных подряд
{
	int len = strlen(s);
	for (int i=0;i<len-1;i++)
		if((TypeChar(s[i])==5)&&(TypeChar(s[i+1])==5))
		{
			cout << " несколько перемменных подряд " <<endl;
			return false;
		}
		return true;
}/*---------------------------------------------------------------------*/
bool CheckStrAtallChecks(char* s) //done все проверки корректности вместе взятые 
{
	if((Brackets(s))&&(CheckOperationsInBegEndWithBrack(s))&&(CheckOperationsInSuccession(s))&&(CheckCorrectSymbols(s))&&(CheckPositionOfDotAndComma(s))&&(CheckManyVariablesInSuccession(s)))
		return true;
	else
		return false;
}/*---------------------------------------------------------------------*/

void FindWritePositVariable (const char *s, int * res) //done поиск переменных в выражении
{
	int j=0;
	for (int i=0;i<strlen(s);i++) //поиск и запись переменных в выражениии (запись в массив)
		if(TypeChar(s[i])==5)
		{
			res[j]=i;
			j++;
		}
}/*---------------------------------------------------------------------*/

bool CorrectOfNumb(char *s) //done кор. ввода числа
{
	int len = strlen(s);
	if (CheckPositionOfDotAndComma(s)!=true) //нарушен ввод точек и запятых
		return false;
	if ((Operation(s[0]))&&(s[0]!='-')) //нарушение: ввод бинарных операций
		return false;
	for (int i=0;i<len;i++)  //нарушение: ввод постронних эл-тов
	{
		if((TypeChar(s[i])==0)||(TypeChar(s[i])==1)||(TypeChar(s[i])==5)||(TypeChar(s[i])==3)) 
		{
			return false;
		}	
	}
	return true;
}/*---------------------------------------------------------------------*/

double Numb(char *s) //done перевод строки в число (atof)
{
	double result=atof(s);
	return result;
}/*---------------------------------------------------------------------*/

void InputValuable(char *s, char *res) //done входные параметры переменных
{
	int *numb;
	int Size_numb=256;
	int j=0; 
	int k=0; 
	int len=strlen(s);
	numb=new int[Size_numb];
	for (int i=0;i<Size_numb;i++) //создание спец. мас.
		numb[i]=-1;
	FindWritePositVariable(s,numb);
	if (numb[0]!=-1) //проверяем, есть ли вообще параметры в нашей задаче
		cout << " В выражении присутствуют параметры " <<endl;
	for (int t=0;t<len;t++)
	{
		if (numb[j]!=t) //позиция пар-ра не совпала с текущей, зн. просто число
		{
			res[k]=s[t];
			k++;
		}
		else //параметр
		{
			int f=1;
			char str[256];
			int i=0;
			while (f==1)
			{
				cout << s[numb[j]]<< "=";
				gets_s(str);  //ввод значения параметра
				if (CorrectOfNumb(str)!=true)  //проверка корректности
				{
					cout << " " <<endl;
				}
				else
				{
					if(str[0]=='-') //унарный минус
					{
						res[k]='0';
						k++;
						res[k]=' ';
						k++;
						i=1;
						while (str[i]!='\0')
						{
							res[k]=str[i];
							k++;
							i++;
						}
						res[k]=' ';
						k++;
						res[k]='-';
						k++;
						t++;
					}
					else //без унарного минуса
					{
						while (str[i]!='\0')
						{
							res[k]=str[i];
							k++;
							i++;
						}
					}
					f=0;
				}
			}
			j++;
		}		
	}
	res[k]='\0';
	delete []numb;
}/*---------------------------------------------------------------------*/

double ResultsCount(char *s) //done подсчет выражения
{
	Stack<double> Stack_1(256);
	int len=strlen(s);
	int p=0; 
	int t=0;
	int j=0;
	double res;
	while(s[j]!='\0') //пошли по строке
	{
		if(TypeChar(s[j])==2) //если число
		{ 
			char str[256];
			int k=0;
			double numb;	
			t=j;
			while(s[t]!=' ') //занесли число в строку
			{
				str[k]=s[t];
				t++;
				k++;
			}
			str[k]='\0';
			p=t-j+1; //переход (на сколько)
			numb=Numb(str); //переводим стр. в число
			Stack_1.PushElem(numb); //клад в стек
			j=j+p-1; //сам переход
		} 
		if (Operation(s[j])) //попалась операция
		{
			double r,l; //2 верхних эл-та стека
			r=Stack_1.DelElem();
			l=Stack_1.DelElem();
			switch(s[j]) //выполняем операцию
			{
				case '+':
				{
					res=l+r;
					break;
				}
				case '-':
				{
					res=l-r;
					break;
				}
				case '*':
				{
					res=l*r;
					break;
				}
				case '/':
				{
					res=l/r;
					break;
				}
			}
			Stack_1.PushElem(res); //положили рез-тат в стек
		}
		j++;
	}
	return Stack_1.DelElem();
}/*---------------------------------------------------------------------*/