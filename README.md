В ходе данной программы реализованы:

1) Шаблонный класс списков;

2) Шаблонный класс стеков, основанный на списках;

3) Ф-ии, выполняющие: разбиение исходного арифметического выражения на лексемы, различные проверки корректности выражения, перевод выражения в постфиксную (польскую) запись, вычисление выражения по постфиксной записи, а также работу вычисления выражений, содержащих параметр;

4) Создание консольного интерфейса пользователя.

Осуществляемые операции:

+,-,*,/

Функции:

int Priority(char) - приоритет

bool Brackets(char *) - контроль скобок

void UnarMinus(char *,char *) - запись унарного минуса

bool Operation(char ) - определение операций

int TypeChar(char ) - разбиение на лекс.

void ConvertInPostfix (const char* ,char *) - обр. польская запись

void PointToComma(char *) - перев. точки в запятую

bool FindUnarMinus(char *) - определение унар. минуса

bool CheckOperationsInBegEndWithBrack(char* ) - проверка кор. операций в начале конце выражения и после откр. и перед закрыв. скобками

bool CheckOperationsInSuccession(char *) - проверка кор. операций на запись их подряд

bool CheckCorrectSymbols(char *) - проверка кор. записи символов

bool CheckPositionOfDotAndComma(char *) - кор. расстановки точек и запятых

bool CheckVariable(char *) - кор. наличия переменных

bool CheckManyVariablesInSuccession(char *) - кор. записи нескольких переменных подряд

bool CheckStrAtallChecks(char *) - все проверки корректности вместе взятые 

void FindWritePositVariable (const char *, int * ) - поиск переменных в выражении

bool CorrectOfNumb(char *) - кор. ввода числа

double Numb(char *) - перевод строки в число (atof)

void InputValuable(char *,char *) - входные параметры переменных

double ResultsCount(char *) - подсчет выражения

