#include "../List/List/arithmetic.h"
#include "tlist.h"
#include <gtest.h>

TEST(Arithmetic,can_identify_type_1)
{
	int Test_Type;
	char Test_String[]="8.3*(c)";
	for (int i=0;i<6;i++)
		Test_Type=TypeChar(Test_String[0]);
	EXPECT_EQ(2,Test_Type);
}
TEST(Arithmetic,can_identify_type_2)
{
	int Test_Type;
	char Test_String[]="8.3*(c)";
	for (int i=0;i<6;i++)
		Test_Type=TypeChar(Test_String[1]);
	EXPECT_EQ(4,Test_Type);
}

TEST(Arithmetic,can_identify_type_3)
{
	int Test_Type;
	char Test_String[]="8.3*(c)";
	for (int i=0;i<6;i++)
		Test_Type=TypeChar(Test_String[2]);
	EXPECT_EQ(2,Test_Type);
}
TEST(Arithmetic,can_identify_type_4)
{
	int Test_Type;
	char Test_String[]="8.3*(c)";
	for (int i=0;i<6;i++)
		Test_Type=TypeChar(Test_String[3]);
	EXPECT_EQ(1,Test_Type);
}
TEST(Arithmetic,can_identify_type_5)
{
	int Test_Type;
	char Test_String[]="8.3*(c)";
	for (int i=0;i<6;i++)
		Test_Type=TypeChar(Test_String[4]);
	EXPECT_EQ(3,Test_Type);
}
TEST(Arithmetic,can_identify_type_6)
{
	int Test_Type;
	char Test_String[]="8.3*(c)";
	for (int i=0;i<6;i++)
		Test_Type=TypeChar(Test_String[5]);
	EXPECT_EQ(5,Test_Type);
}

TEST(Arithmetic,can_identify_type_7)
{
	int Test_Type;
	char Test_String[]="8.3*(c)";
	for (int i=0;i<6;i++)
		Test_Type=TypeChar(Test_String[6]);
	EXPECT_EQ(3,Test_Type);
}

TEST(Arithmetic,can_identify_priority_1)
{
	int prior;
	char Test_String[]="2*a";
	prior=Priority(Test_String[1]);
	EXPECT_EQ(2,prior);
}

TEST(Arithmetic,can_identify_priority_2)
{
	int prior;
	char Test_String[]="2+a";
	prior=Priority(Test_String[1]);
	EXPECT_EQ(1,prior);
}

TEST(Arithmetic,can_identify_priority_3)
{
	int prior;
	char Test_String[]="(1+b)*a";
	prior=Priority(Test_String[0]);
	EXPECT_EQ(0,prior);
}

TEST(Arithmetic,can_identify_operation_1)
{
	char Test_String[]="3+(2*a)";
	EXPECT_EQ(true,Operation(Test_String[1]));
}
TEST(Arithmetic,can_identify_operation_2)
{
	char Test_String[]="3+(2*a)";
	EXPECT_EQ(true,Operation(Test_String[4]));
}
TEST(Arithmetic,can_identify_operation_3)
{
	char Test_String[]="3/(2-a)";
	EXPECT_EQ(true,Operation(Test_String[1]));
}
TEST(Arithmetic,can_identify_operation_4)
{
	char Test_String[]="3/(2-a)";
	EXPECT_EQ(true,Operation(Test_String[4]));
}

TEST(Arithmetic,can_check_brackets)
{
	char Test_String[]="(1+a)*b";
	EXPECT_EQ(true,Brackets(Test_String));
}

TEST(Arithmetic,error_check_brackets_opened)
{
	char Test_String[]="((1+a)*b";
	EXPECT_EQ(false,Brackets(Test_String));
}

TEST(Arithmetic,error_check_brackets_closed)
{
	char Test_String[]=")(1+a)*b";
	EXPECT_EQ(false,Brackets(Test_String));
}

TEST(Arithmetic,can_check_operations_in_the_end_begin_with_brackets)
{
	char Test_String[]="(1+3)-2*4";
	EXPECT_EQ(true,CheckOperationsInBegEndWithBrack(Test_String));
}

TEST(Arithmetic,can_check_operations_in_the_end)
{
	char Test_String[]="1+";
	EXPECT_EQ(false,CheckOperationsInBegEndWithBrack(Test_String));
}

TEST(Arithmetic,can_check_operations_in_the_begin)
{
	char Test_String[]="*2";
	EXPECT_EQ(false,CheckOperationsInBegEndWithBrack(Test_String));
}

TEST(Arithmetic,can_check_operations_with__opened_brackets)
{
	char Test_String[]="(+3)";
	EXPECT_EQ(false,CheckOperationsInBegEndWithBrack(Test_String));
}

TEST(Arithmetic,can_check_operations_with_closed_brackets)
{
	char Test_String[]="(4+)";
	EXPECT_EQ(false,CheckOperationsInBegEndWithBrack(Test_String));
}

TEST(Arithmetic,can_check_operations_in_succession_with_many_operations_positive_answer)
{
	char Test_String[]="1+3-2*4";
	EXPECT_EQ(true,CheckOperationsInBegEndWithBrack(Test_String));
}

TEST(Arithmetic,can_check_operations_in_succession_with_many_operations)
{
	char Test_String[]="1+/*2+3";
	EXPECT_EQ(false,CheckOperationsInSuccession(Test_String));
}

TEST(Arithmetic,can_check_operations_in_succession_with_two_operations)
{
	char Test_String[]="1+*2+3";
	EXPECT_EQ(false,CheckOperationsInSuccession(Test_String));
}

TEST(Arithmetic,can_check_correctness_of_symbols)
{
	char Test_String[]="a+1!@#b";
	EXPECT_EQ(false,CheckCorrectSymbols(Test_String));
}

TEST(Arithmetic,can_check_correctness_of_symbols_true_answer)
{
	char Test_String[]="a+1";
	EXPECT_EQ(true,CheckCorrectSymbols(Test_String));
}

TEST(Arithmetic,can_check_right_position_dot_or_comma)
{
	char Test_String[]="1.2+3,3-2+a";
	EXPECT_EQ(true,CheckPositionOfDotAndComma(Test_String));
}

TEST(Arithmetic,can_check_wrong_position_dot_or_comma_at_begin)
{
	char Test_String[]=".2+3,3-2+a";
	EXPECT_EQ(false,CheckPositionOfDotAndComma(Test_String));
}

TEST(Arithmetic,can_check_wrong_position_dot_or_comma_at_end)
{
	char Test_String[]="1.2+3,";
	EXPECT_EQ(false,CheckPositionOfDotAndComma(Test_String));
}

TEST(Arithmetic,can_check_wrong_position_dot_or_comma_in_succession)
{
	char Test_String[]="1.2+3,.1";
	EXPECT_EQ(false,CheckPositionOfDotAndComma(Test_String));
}

TEST(Arithmetic,can_check_many_variables_true)
{
	char Test_String[]="a+b";
	EXPECT_EQ(true,CheckManyVariablesInSuccession(Test_String));
}

TEST(Arithmetic,can_check_amount_of_letters_in_vars_false)
{
	char Test_String[]="ab+1";
	EXPECT_EQ(false,CheckManyVariablesInSuccession(Test_String));

}

TEST(Arithmetic,can_check_str_at_all_true)
{
	char Test_String[]="5+3*a*b-7";
	EXPECT_EQ(true,CheckStrAtallChecks(Test_String));
}

TEST(Arithmetic,can_check_str_at_all_false)
{
	char Test_String[]="(/3a..%^&-2#a*bdsac*/+";
	EXPECT_EQ(false,CheckStrAtallChecks(Test_String));
}

TEST(Arithmetic,can_check_variable)
{
	char Test_String[]="a+2";
	EXPECT_EQ(true,CheckVariable(Test_String));
}

TEST(Arithmetic,can_not_check_variable)
{
	char Test_String[]="1+2";
	EXPECT_EQ(false,CheckVariable(Test_String));
}

TEST(Arithmetic,can_identify_unary_minus)
{
	char Test_String[]="(-3.1*a)+2";
	EXPECT_TRUE(FindUnarMinus(Test_String));
}

TEST(Arithmetic,can_process_unary_minus_at_the_beginning)
{
	char Test_String[]="-2*3";
	char Test_String_2[256];
	UnarMinus(Test_String,Test_String_2);
	EXPECT_EQ('0',Test_String_2[0]);
	EXPECT_EQ('-',Test_String_2[1]);
	EXPECT_EQ('2',Test_String_2[2]);
	EXPECT_EQ('*',Test_String_2[3]);
	EXPECT_EQ('3',Test_String_2[4]);
}

TEST(Arithmetic,can_process_unary_minus_after_open_bracket)
{
	char Test_String[]="3*(-2)";
	char Test_String_2[256];
	UnarMinus(Test_String,Test_String_2);
	EXPECT_EQ('3',Test_String_2[0]);
	EXPECT_EQ('*',Test_String_2[1]);
	EXPECT_EQ('(',Test_String_2[2]);
	EXPECT_EQ('0',Test_String_2[3]);
	EXPECT_EQ('-',Test_String_2[4]);
	EXPECT_EQ('2',Test_String_2[5]);
	EXPECT_EQ(')',Test_String_2[6]);
}

TEST(Arithmetic,can_replace_point_to_comma)
{
	char Test_String[]="5.2";
	PointToComma(Test_String);
	EXPECT_EQ(',',Test_String[1]);	
}

TEST(Arithmetic,can_get_numb)
{
	char Test_String[]="1.23";
	EXPECT_EQ(1.23,Numb(Test_String));
}

TEST(Arithmetic,can_convert_in_postfix_note_1)
{
	char Test_String[]="a+1.2*3-5";
	char Test_String_2[15];
	ConvertInPostfix(Test_String,Test_String_2);
	EXPECT_EQ('a',Test_String_2[0]);
	EXPECT_EQ(' ',Test_String_2[1]);
	EXPECT_EQ('1',Test_String_2[2]);
	EXPECT_EQ('.',Test_String_2[3]);
	EXPECT_EQ('2',Test_String_2[4]);
	EXPECT_EQ(' ',Test_String_2[5]);
	EXPECT_EQ('3',Test_String_2[6]);
	EXPECT_EQ(' ',Test_String_2[7]);
	EXPECT_EQ('*',Test_String_2[8]);
	EXPECT_EQ('+',Test_String_2[9]);
	EXPECT_EQ('5',Test_String_2[10]);
	EXPECT_EQ(' ',Test_String_2[11]);
	EXPECT_EQ('-',Test_String_2[12]);
}

TEST(Arithmetic,can_convert_in_postfix_note_2)
{
	char Test_String[]="a/5+4*2-3";
	char Test_String_2[15];
	ConvertInPostfix(Test_String,Test_String_2);
	EXPECT_EQ('a',Test_String_2[0]);
	EXPECT_EQ(' ',Test_String_2[1]);
	EXPECT_EQ('5',Test_String_2[2]);
	EXPECT_EQ(' ',Test_String_2[3]);
	EXPECT_EQ('/',Test_String_2[4]);
	EXPECT_EQ('4',Test_String_2[5]);
	EXPECT_EQ(' ',Test_String_2[6]);
	EXPECT_EQ('2',Test_String_2[7]);
	EXPECT_EQ(' ',Test_String_2[8]);
	EXPECT_EQ('*',Test_String_2[9]);
	EXPECT_EQ('+',Test_String_2[10]);
	EXPECT_EQ('3',Test_String_2[11]);
	EXPECT_EQ(' ',Test_String_2[12]);
	EXPECT_EQ('-',Test_String_2[13]);
}

TEST(Arithmetic,can_give_sum)
{
	char Test_String[]="15+4";
	double Result;
	char Test_String_2[15];
	ConvertInPostfix(Test_String,Test_String_2);
	Result=ResultsCount(Test_String_2);
	EXPECT_EQ(19,Result);	
}

TEST(Arithmetic,can_give_sub)
{
	char Test_String[]="10.1-9.1";
	double Result;
	char Test_String_2[15];
	ConvertInPostfix(Test_String,Test_String_2);
	Result=ResultsCount(Test_String_2);
	EXPECT_EQ(1,Result);	
}

TEST(Arithmetic,can_give_mult)
{
	char Test_String[]="2*2.5";
	double Result;
	char Test_String_2[15];
	ConvertInPostfix(Test_String,Test_String_2);
	Result=ResultsCount(Test_String_2);
	EXPECT_EQ(5,Result);	
}

TEST(Arithmetic,can_give_div)
{
	char Test_String[]="5/2";
	double Result;
	char Test_String_2[15];
	ConvertInPostfix(Test_String,Test_String_2);
	Result=ResultsCount(Test_String_2);
	EXPECT_EQ(2.5,Result);	
}

TEST(Arithmetic, calculate_big_string_with_using_brack)
{
	char Test_String[]="(4-3*5+1)-10/2";
	double Result;
	char Test_String_2[50];
	ConvertInPostfix(Test_String,Test_String_2);
	Result=ResultsCount(Test_String_2);
	EXPECT_EQ(-15,Result);	
}

TEST(Arithmetic,calculate_big_string)
{
	char Test_String[]="6+3*2-4+2*2.5";
	double Result;
	char Test_String_2[50];
	ConvertInPostfix(Test_String,Test_String_2);
	Result=ResultsCount(Test_String_2);
	EXPECT_EQ(13,Result);	
}

TEST(Arithmetic,find_variables)
{
	char Test_String[]="1+a+b-3+c";
	int Result[3];
	for(int i=0;i<3;i++)
		Result[i]=-1;
	FindWritePositVariable(Test_String,Result);
	EXPECT_EQ(2,Result[0]);
	EXPECT_EQ(4,Result[1]);
	EXPECT_EQ(8,Result[2]);
}

TEST(Arithmetic,can_variable_number_inp)
{
	char Test_String[]="a+1.2"; //a=1
	char Test_String_2[15];
	char Test_String_3[15];
	ConvertInPostfix(Test_String,Test_String_2);
	InputValuable(Test_String_2,Test_String_3);
	EXPECT_EQ('1',Test_String_3[0]);
	EXPECT_EQ(' ',Test_String_3[1]);
	EXPECT_EQ('1',Test_String_3[2]);
	EXPECT_EQ('.',Test_String_3[3]);
	EXPECT_EQ('2',Test_String_3[4]);
	EXPECT_EQ(' ',Test_String_3[5]);
	EXPECT_EQ('+',Test_String_3[6]);
}
TEST(Arithmetic,can_variable_big_number_inp)
{
	char Test_String[]="a+1.2"; //a=10
	char Test_String_2[15];
	char Test_String_3[15];
	ConvertInPostfix(Test_String,Test_String_2);
	InputValuable(Test_String_2,Test_String_3);
	EXPECT_EQ('1',Test_String_3[0]);
	EXPECT_EQ('0',Test_String_3[1]);
	EXPECT_EQ(' ',Test_String_3[2]);
	EXPECT_EQ('1',Test_String_3[3]);
	EXPECT_EQ('.',Test_String_3[4]);
	EXPECT_EQ('2',Test_String_3[5]);
	EXPECT_EQ(' ',Test_String_3[6]);
	EXPECT_EQ('+',Test_String_3[7]);
}

TEST(Arithmetic,calculate_big_string_with_variable_1)
{
	char Test_String[]="6+3*a-4+2*2.5"; //a=5
	double Result;
	char Test_String_2[50];
	char Test_String_3[50];
	ConvertInPostfix(Test_String,Test_String_2);
	InputValuable(Test_String_2,Test_String_3);
	Result=ResultsCount(Test_String_3);
	EXPECT_EQ(22,Result);	
}

TEST(Arithmetic,calculate_big_string_with_variable_2)
{
	char Test_String[]="1+2*a-12.5/2.5"; //a=3.1
	double Result;
	char Test_String_2[50];
	char Test_String_3[50];
	ConvertInPostfix(Test_String,Test_String_2);
	InputValuable(Test_String_2,Test_String_3);
	Result=ResultsCount(Test_String_3);
	EXPECT_EQ(2.2,Result);	
}