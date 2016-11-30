#include "../List/List/arithmetic.h"
#include "tlist.h"

int Priority(char s)
{
	int prior;
	switch (s)
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

bool Operation(char s)
{
	bool f=false;
	char signum[]="-+*/";
	for(int i=0;i<6;i++)
		if (s==signum[i])
		{
			f=true;
			break;
		}
	return f;
}/*---------------------------------------------------------------------*/

int TypeChar(char s)
{
	if ( Operation(s) )
		return 1;
	else if(isdigit(s))
		return 2;
	else if((s=='(')||(s==')'))
		return 3;
	else if((s=='.')||(s==','))
		return 4;
	else if(isalpha(s))
		return 5;
	else 
		return 0;

}/*---------------------------------------------------------------------*/

bool Brackets(char *s)
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

				return false;
			}
			else 
				Stack_1.DelElem();
		}
		i++;
	}
	if (Stack_1.EmptyStack())
		return true;
	else
	{
		return false;
	}
}/*---------------------------------------------------------------------*/

void UnarMinus(char *s, char *res)
{
	int len = strlen(s);
	int j=0;
	if (s[0]=='-')
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
			if((s[i-1]=='(')&&((TypeChar(s[i+1])==2)||(TypeChar(s[i+1])==5)))
			{
				res[j++]='0';
				res[j++]='-';
			}
			else 
				res[j++]='-';
		}
		else
		{
			res[j]=s[i];
			j++;
		}
	}
	res[j]='\0';
}/*---------------------------------------------------------------------*/

void ConvertInPostfix(const char* s,char *res)
{
	Stack<char> Stack_2(256);
	int len = strlen(s);
	int j=0; 
	int m=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='(')
			Stack_2.PushElem('(');
		if (s[i]==')')
		{
			char a =Stack_2.DelElem();
			while (a !='(')
			{
				res[j]=a;
				j++;
				a=Stack_2.DelElem();
			}
		}
		if(Operation(s[i]))
		{
			if (Stack_2.EmptyStack())
				Stack_2.PushElem(s[i]);
			else 
			{
				char oper = Stack_2.RetTopElem();
				while(Priority(s[i])<=Priority(oper))
				{
					res[j]=Stack_2.DelElem();
					j++;
					if (Stack_2.EmptyStack()!=true)
						oper=Stack_2.RetTopElem();
					else 
						oper='(';
				}
				Stack_2.PushElem(s[i]);
			}
		}
		if (TypeChar(s[i])==2)
		{
			if ((TypeChar(s[i+1])==2)||(TypeChar(s[i+1])==4))
			{
				res[j]=s[i];
				j++;
			}
			else
			{
				res[j]=s[i];
				j++;
				res[j]=' ';
				j++;
			}
		}
		if (TypeChar(s[i])==5)
		{
			res[j]=s[i];
			j++;
			res[j]=' ';
			j++;
		}
		if (TypeChar(s[i])==4)
		{
			res[j]=s[i];
			j++;
		}
	}
	while(Stack_2.EmptyStack()!=true)
	{
		res[j]=Stack_2.DelElem();
		j++;
	}
	res[j]='\0';
}/*---------------------------------------------------------------------*/

void PointToComma(char *s)
{
	int len = strlen(s);
	for (int i=0;i<len;i++)
	{
		if (TypeChar(s[i])==4)
		{
			if (s[i]=='.')
				s[i]=',';
		}
	}
}/*---------------------------------------------------------------------*/

bool FindUnarMinus(char *s)
{
	int i=1;
	int f=0;
	int len = strlen(s);
	if (s[0]=='-')
		f=1;
	while(s[i]!='\0')
	{
		if (s[i]=='-')
		{
			if((s[i-1]=='(')&&((TypeChar(s[i+1])==2)||(TypeChar(s[i+1])==5)))
			{
				f=1;
				break;
			}
		}
		i++;
	}
	if (f==1)
		return true;
	else 
		return false;
}/*---------------------------------------------------------------------*/

bool CheckOperationsInBegEndWithBrack(char* s)
{
	int len=strlen(s);
	for (int i=1;i<len-1;i++)
	{
	if(Operation(s[i]))
		if((s[i-1]=='(')||(s[i+1]==')'))
		{
			cout<< " bracket and operation  " << i+1 << endl;
			return false;
		}
	}
	if (Operation(s[0]))
	{
		cout<< " operation at the begin " << endl;
		return false;
	}
	else if (Operation(s[len-1]))
	{
			cout<< " operation at the end " << len << endl;
			return false;
	}
	return true;
}/*---------------------------------------------------------------------*/

bool CheckOperationsInSuccession(char *s)
{
	int len=strlen(s);
	for (int i=0;i<len-1;i++)
	{
		if (Operation(s[i]))
		{
			if (Operation(s[i+1]))
			{
				cout<< "two operations in succession " << i+1 << " and " << i+2 << endl;
				return false;
			}
		}
	}
		return true;
}/*---------------------------------------------------------------------*/

bool CheckCorrectSymbols(char *s)
{
	int len = strlen(s);
	for (int i=0;i<len;i++)
		if(TypeChar(s[i])==0)
		{
			cout << " Another Symbol " << i+1 <<endl;
			return false;
		}
		return true;
}/*---------------------------------------------------------------------*/

bool CheckPositionOfDotAndComma(char *s)
{

	int len = strlen(s);
	if ((TypeChar(s[0])==4)||(TypeChar(s[len-1])==4))
		return false;
	else 
	{
		for (int i=1;i<len-1;i++)
			if(TypeChar(s[i])==4)
			{
				if((TypeChar(s[i-1])!=2)||(TypeChar(s[i+1])!=2))
					return false;
			}
			return true;
	}	
}/*---------------------------------------------------------------------*/

bool CheckVariable(char *s)
{
	int len = strlen(s);
	for (int i=0;i<len;i++)
	{
		if(TypeChar(s[i])==5)
			return true;
	}
		return false;
}/*---------------------------------------------------------------------*/
bool CheckManyVariablesInSuccession(char *s)
{
	int len = strlen(s);
	for (int i=0;i<len-1;i++)
		if((TypeChar(s[i])==5)&&(TypeChar(s[i+1])==5))
		{
			cout << " too much variables in succession " << i+1 <<endl;
			return false;
		}
		return true;
}/*---------------------------------------------------------------------*/
bool CheckStrAtallChecks(char* s)
{
	if((Brackets(s))&&(CheckOperationsInBegEndWithBrack(s))&&(CheckOperationsInSuccession(s))&&(CheckCorrectSymbols(s))&&(CheckPositionOfDotAndComma(s))&&(CheckManyVariablesInSuccession(s)))
		return true;
	else
		return false;
}/*---------------------------------------------------------------------*/

void FindWritePositVariable (const char *s, int * res)
{
	int j=0;
	for (int i=0;i<strlen(s);i++)
		if(TypeChar(s[i])==5)
		{
			res[j]=i;
			j++;
		}
}/*---------------------------------------------------------------------*/

bool CorrectOfNumb(char *s)
{
	int len = strlen(s);
	if (CheckPositionOfDotAndComma(s)!=true)
		return false;
	if ((Operation(s[0]))&&(s[0]!='-'))
		return false;
	for (int i=0;i<len;i++)
	{
		if((TypeChar(s[i])==0)||(TypeChar(s[i])==1)||(TypeChar(s[i])==5)||(TypeChar(s[i])==3))
		{
			return false;
		}	
	}
	return true;
}/*---------------------------------------------------------------------*/

double Numb(char *s)
{
	double result=atof(s);
	return result;
}/*---------------------------------------------------------------------*/

void InputValuable(char *s, char *res) 
{
	int *numb;
	int Size_numb=256;
	int j=0; 
	int k=0; 
	int len=strlen(s);
	numb=new int[Size_numb];
	for (int i=0;i<Size_numb;i++)
		numb[i]=-1;
	FindWritePositVariable(s,numb);
	if (numb[0]!=-1)
		cout << "" <<endl;
	for (int t=0;t<len;t++)
	{
		if (numb[j]!=t)
		{
			res[k]=s[t];
			k++;
		}
		else
		{
			int f=1;
			char str[256];
			int i=0;
			while (f==1)
			{
				cout << s[numb[j]]<< "=";
				gets_s(str);
				if (CorrectOfNumb(str)!=true)
				{
					cout << " " <<endl;
				}
				else
				{
					if(str[0]=='-')
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
					else
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

double ResultsCount(char *s)
{
	Stack<double> Stack_1(256);
	int len=strlen(s);
	int p=0; 
	int t=0;
	int j=0;
	double res;
	while(s[j]!='\0')
	{
		if(TypeChar(s[j])==2)
		{ 
			char str[256];
			int k=0;
			double numb;	
			t=j;
			while(s[t]!=' ')
			{
				str[k]=s[t];
				t++;
				k++;
			}
			str[k]='\0';
			p=t-j+1;
			numb=Numb(str);
			Stack_1.PushElem(numb);
			j=j+p-1;
		}
		if (Operation(s[j]))
		{
			double r,l;
			r=Stack_1.DelElem();
			l=Stack_1.DelElem();
			switch(s[j])
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
			Stack_1.PushElem(res);
		}
		j++;
	}
	return Stack_1.DelElem();
}/*---------------------------------------------------------------------*/