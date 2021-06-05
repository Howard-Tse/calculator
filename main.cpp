#include<iostream>
#include<fstream>
#include<string.h>
#include<math.h>
#include<Windows.h>
#include<stdlib.h>

using namespace std;

struct Data
{
	double data[100];
	int top;
};

struct Symbol
{
	char symbol[100];
	int top;
};

double f(int type, double a, double b, double c, double x);//计算根据x函数值y
void print_fun(int type, double a, double b, double c);//输出函数表达式
void f1();								//初等函数的运算
void f2();								//科学计算器
void f3();								//计算公约数与公倍数的界面
int input_is_right(string t);			//检查输入数据是否正确
int GCD(int num1, int num2);			//计算最大公约数
int LCM(int num1, int num2);			//计算最小公倍数
double integral(int type, double a, double b, double c, double x1, double x2);	//计算定积分
void init_operate_num(struct Data* StackNum);		//初始化数据栈
void init_operate_symbol(struct Symbol* StackSymbol);//初始化符号栈
void in_data(struct Data* StackNum, double num);	//写入数据栈
void in_symbol(struct Symbol* StackSymbol, char ch);//写入符号栈
double read_data(struct Data* StackNum);				//读取数据栈
char read_symbol(struct Symbol* StackSymbol);		//读取符号栈
double put_data(struct Data* StackNum);				//从数据栈中取出数据
char put_symbol(struct Symbol* StackSymbol);		//从符号栈中取出符号
int judge(char ch);									//判断符号优先级
double calculate(double num1, double num2, char c);	//进行四则运算，c为符号，num1和num2为运算数，返回值为结果
void change_radix(int hex, char* str);

int main()
{
	int choose = 0;
	while (1)
	{
		system("cls");
		cout << endl << "请选择：" << endl;
		cout << "1.初等函数的运算" << endl;
		cout << "2.科学计算器" << endl;
		cout << "3.计算最大公约数和最小公倍数" << endl;
		cout << "4.退出" << endl;
		cout << "请选择一项:";
		cin >> choose;
		if (choose == 4)
			break;
		switch (choose)
		{
		case 1:f1(); break;
		case 2:f2(); break;
		case 3:f3(); break;
		default: {
			cout << "输入错误" << endl; 
			Sleep(1000);
			cin.clear();
			cin.ignore(1000, '\n');
		}
		}
	}
	return 0;
}

double f(int type, double a, double b, double c, double x)
{
	double y = 0;
	switch (type)
	{
	case 1:y = a * x + b; break;
	case 2:y = a * x * x + b * x + c; break;
	case 3:y = pow(x, a); break;
	case 4:y = pow(a, x); break;
	case 5:y = log(x) / log(a); break;
	case 61:y = sin(x); break;
	case 62:y = cos(x); break;
	case 63:y = tan(x); break;
	case 7:y = a / x; break;
	}
	return y;
}

void print_fun(int type, double a, double b, double c)
{
	switch (type)
	{
	case 1:cout << "y = " << a << " * x + " << b; break;
	case 2:cout << "y = " << a << " * x^2 + " << b << " * x + " << c; break;
	case 3:cout << "y = x ^ " << a; break;
	case 4:cout << "y = " << a << "^x"; break;
	case 5:cout << "y = log" << a << "(x)"; break;
	case 61:cout << "y = sin(x)"; break;
	case 62:cout << "y = cos(x)"; break;
	case 63:cout << "y = tan(x)"; break;
	case 7:cout << "y = " << a << " / x"; break;
	}
}

void f1()
{
	double a = 0, b = 0, c = 0, x = 0, y = 0, x1 = 0, x2 = 0, d = 0;
	string t;
	int choose1 = 0, choose2 = 0, choose3 = 0;
	while (1)
	{
		system("cls");
		cout << "请选择函数模型:" << endl;
		cout << "1.一次函数" << endl;
		cout << "2.二次函数" << endl;
		cout << "3.幂函数" << endl;
		cout << "4.指数函数" << endl;
		cout << "5.对数函数" << endl;
		cout << "6.三角函数" << endl;
		cout << "7.反比例函数" << endl;
		cout << "8.返回主菜单" << endl;
		cout << "你的选择:";
		cin >> choose1;
		if (choose1 == 8)
			break;
		switch (choose1)
		{
		case 1: {
			cout << "请分别输入a和b的值:" << endl;
			cin >> a
				>> b;
		}break;
		case 2:{
			cout << "请分别输入a,b,c的值:" << endl;
			cin >> a
				>> b
				>> c;
		}break;
		case 3: {
			cout << "请输入指数:" << endl;
			cin >> a;
		}break;
		case 4: {
			cout << "请输入底数:" << endl;
			cin >> a;
		}break;
		case 5: {
			cout << "请输入真数:" << endl;
			cin >> a;
		}break;
		case 6: {
			while (1)
			{
				cout << "\n请选择：" << endl;
				cout << "1.正弦函数" << endl;
				cout << "2.余弦函数" << endl;
				cout << "3.正切函数" << endl;
				cout << "你的选择:";
				cin >> choose1;
				if (choose1 > 3 || choose1 < 1)
				{
					cout << "输入错误" << endl;
					cin.clear();
					cin.ignore(1000, '\n');
					Sleep(1000);
					continue;
				}
				choose1 += 60;
				break;
			}
		}break;
		case 7: {
			cout << "请输入k的值:" << endl;
			cin >> a;
		}break;
		default: {
			cout << "输入错误" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			Sleep(1000);
			continue;
		}
		}
		while (1)
		{
			cout << "\n请输入要对函数";
			print_fun(choose1, a, b, c);
			cout << "执行的操作:" << endl;
			cout << "1.输入x计算y" << endl;
			cout << "2.计算定积分" << endl;
			cout << "3.计算导数" << endl;
			cout << "4.返回上一级" << endl;
			cout << "你的选择:";
			cin >> choose2;
			if (choose2 == 4)
				break;
			switch (choose2)
			{
			case 1: {
				cout << "请输入x" << endl;
				cin >> x;
				cout << endl
					<< "y = "
					<< f(choose1, a, b, c, x)
					<< endl;
			}break;
			case 2: {
				cout << "请输入积分区域（先输入积分下限，再输入积分上限）:" << endl;
				cin >> x1
					>> x2;
				print_fun(choose1, a, b, c);
				cout << "该函数从 "
					<< x1
					<< "到"
					<< x2
					<< " 的定积分为"
					<< integral(choose1, a, b, c, x1, x2)
					<< endl
					<< endl;
			}break;
			case 3: {
				cout << "请输入x的值:";
				cin >> x;
				d = (f(choose1, a, b, c, x + 0.001) - f(choose1, a, b, c, x)) / 0.001;
				print_fun(choose1, a, b, c);
				cout << " 该函数在x = "
					<< x
					<< "处的导数为"
					<< d
					<< endl
					<< endl;
			}break;
			default: {
				cout << "输入错误" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				Sleep(1000);
				continue;
			}
			}
		}
	}
}

void f2()
{
	struct Data data;
	struct Symbol symbol;
	system("cls");
	cout << endl << "科学计算器" << endl << endl;
	cout << "+ - * / ^ 分别对应加法、减法、乘法、除法和指数运算" << endl;
	cout << "二进制数以0开头" << endl;
	cout << "十六进制数以0x开头" << endl;
	cout << "输入exit返回主菜单" << endl;
	cin.get();
	while (1)
	{
		init_operate_num(&data);
		init_operate_symbol(&symbol);
		int i = 0, t = 0;
		double sum = 0, num_l = 0, num_r = 0;
		char v[100] = { 0 }, c;								//数组v用于保存每一个符号之间的数字（字符串）
		char* str = (char*)malloc(sizeof(char) * 200);
		cout << endl << "请输入计算式:" << endl;
		while (1)
		{
			c = cin.get();
			if (c == '\n')
				break;
			str[i] = c;
			i++;
		}
		str[i] = '\0';
		if (str[0] == 'e' && str[1] == 'x' && str[2] == 'i' && str[3] == 't')
			break;
		for (i = 0; str[i] != '\0'; i++)
		{
			if (i == 0 && str[i] == '-')
			{
				v[t++] = str[i];
			}
			else if (str[i] == '(' && str[i + 1] == '-')
			{
				i++;
				v[t++] = str[i++];
				while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == 'x' || (str[i] >= 'a' && str[i] <= 'f'))
				{
					v[t] = str[i];
					t++;
					i++;
				}
				if (v[0] == '0')
				{
					if (v[1] == 'x' || v[1] == 'X')
						change_radix(16, v);
					if (v[1] >= '0' && v[1] <= '9')
						change_radix(2, v);
				}
				in_data(&data, atof(v));	//把读取到的数字（字符串）转换为double型数字并放入数据栈中
				while (t > 0)				//清空t数组
				{
					v[t] = 0;
					t--;
				}
				if (str[i] != ')')
				{
					i--;
					in_symbol(&symbol, '(');
				}
			}
			else if (str[i] >= '0' && str[i] <= '9')
			{
				while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == 'x' || (str[i] >= 'a' && str[i] <= 'f'))
				{
					v[t] = str[i];
					t++;
					i++;
				}
				if (v[0] == '0')
				{
					if (v[1] == 'x' || v[1] == 'X')
						change_radix(16, v);
					if (v[1] >= '0' && v[1] <= '9')
						change_radix(2, v);
				}
				in_data(&data, atof(v));
				while (t > 0)
				{
					v[t] = 0;
					t--;
				}
				i--;
			}
			else
			{
				if (symbol.top == -1)
				{ //如果符号栈没有元素，直接把符号放入符号栈 
					in_symbol(&symbol, str[i]);
				}
				else if (judge(str[i]) == 1)
				{ //如果此符号是'('，直接放入符号栈 
					in_symbol(&symbol, str[i]);
				}
				else if (judge(str[i]) == 2)
				{ //如果此符号是'+'或'-'，判断与栈顶符号是优先级 
					if (judge(read_symbol(&symbol)) == 1)
					{ //如果栈顶符号是'('，放入符号栈 
						in_symbol(&symbol, str[i]);
					}
					else if (judge(read_symbol(&symbol)) == 2)
					{ //如果栈顶符号是'+'或'-'，则出栈运算 
						while (symbol.top >= 0 && data.top >= 1)
						{ //循环出栈
							num_r = put_data(&data);
							num_l = put_data(&data);
							sum = calculate(num_l, num_r, put_symbol(&symbol));
							in_data(&data, sum); //将运算结果压入数据栈 
						}
						in_symbol(&symbol, str[i]); //新符号进栈 
					}
					else if (judge(read_symbol(&symbol)) == 3)
					{ //如果栈顶符号是'*'或'/'或'^'，则进符号栈 
						while (symbol.top >= 0 && data.top >= 1)
						{ //循环出栈
							num_r = put_data(&data);
							num_l = put_data(&data);
							sum = calculate(num_l, num_r, put_symbol(&symbol));
							in_data(&data, sum); //将运算结果压入数据栈 
						}
						in_symbol(&symbol, str[i]); //新符号进栈 
					}
					/*栈顶符号不可能是')'，故不做判断*/
				}
				else if (judge(str[i]) == 3)
				{ //如果此符号是'*'或'/'或'^'，则判断与栈顶符号是优先级
					if (judge(read_symbol(&symbol)) == 1)
					{ //如果栈顶符号是'('，放入符号栈 
						in_symbol(&symbol, str[i]);
					}
					else if (judge(read_symbol(&symbol)) == 2)
					{ //如果栈顶符号是'+'或'-'，则进符号栈
						in_symbol(&symbol, str[i]); //新符号进栈
					}
					else if (judge(read_symbol(&symbol)) == 3)
					{ //如果栈顶符号是'*'或'/'或'^'，则出栈运算 
						while (symbol.top >= 0 && data.top >= 1)
						{ //循环出栈
							num_r = put_data(&data);
							num_l = put_data(&data);
							sum = calculate(num_l, num_r, put_symbol(&symbol));
							in_data(&data, sum); //将运算结果压入数据栈 
						}
						in_symbol(&symbol, str[i]); //新符号进栈
					}
				}
				else if (judge(str[i]) == 4)
				{ // 如果此符号是')'，则出栈运算直到遇到'('
					do
					{ //循环出栈直到遇到'('
						num_r = put_data(&data);
						num_l = put_data(&data);
						sum = calculate(num_l, num_r, put_symbol(&symbol));
						in_data(&data, sum); //将运算结果压入数据栈 
					} while (judge(read_symbol(&symbol)) != 1);
					put_symbol(&symbol); //括号内运算结束后使'('出栈 
				}
				else if (judge(str[i]) == 0)
				{
					cout << "输入错误" << endl;
					cin.clear();
					cin.ignore(1000, '\n');
					continue;
				}
			}
		}
		free(str); //释放内存空间
		while (symbol.top != -1)
		{
			num_r = put_data(&data);
			num_l = put_data(&data);
			sum = calculate(num_l, num_r, put_symbol(&symbol));
			in_data(&data, sum);
		}
		cout << " = " << data.data[0] << endl;
	}
}

void f3()
{
	int choose = 0, num1 = 0, num2 = 0;
	system("cls");
	while (1)
	{
		cout << "\n请选择:" << endl;
		cout << "1.计算两个数的最大公约数" << endl;
		cout << "2.计算两个数的最小公倍数" << endl;
		cout << "3.返回主菜单" << endl;
		cout << "请输入:";
		cin >> choose;
		if (choose == 1)
		{
			cout << "请输入两个数:" << endl;
			cin >> num1;
			cin >> num2;
			if (num1 < num2)
			{
				int t;
				t = num1;
				num1 = num2;
				num2 = t;
			}
			cout << num1
				<< "和"
				<< num2
				<< "的最大公约数是"
				<< GCD(num1, num2)
				<< endl;
		}
		if (choose == 2)
		{
			cout << "请输入两个数:" << endl;
			cin >> num1;
			cin >> num2;
			if (num1 < num2)
			{
				int t;
				t = num1;
				num1 = num2;
				num2 = t;
			}
			cout << num1
				<< "和"
				<< num2
				<< "的最小公倍数是"
				<< LCM(num1, num2)
				<< endl;
		}
		if (choose == 3)
			break;
	}
}

int input_is_right(string t)
{
	unsigned int i;
	for (i = 0; i < t.length(); i++)
	{
		if ((t[i] < '0' || t[i]>'9') && t[i] != '+' &&
			t[i] != '-' && t[i] != '*' && t[i] != '/' &&
			(t[i] == '0' &&(t[i + 1] != 'x' || t[i + 1] != 'X')))
			return 0;
	}
	return 1;
}

int GCD(int num1, int num2)
{
	int r = 0;
	while (1)
	{
		r = num1 % num2;
		num1 = num2;
		num2 = r;
		if (num2 == 0)
			break;
	}
	return num1;
}

int LCM(int num1, int num2)
{
	return num1 * num2 / GCD(num1, num2);
}

double integral(int type, double a, double b, double c, double x1, double x2)
{
	int x = 0;
	double sum = 0, t = 0;
	if (x1 > x2)
	{
		x = 1;
		t = x1;
		x1 = x2;
		x2 = t;
	}
	if (x1 == x2)
		return 0;
	for (; x1 < x2; x1 += 0.01)
	{
		sum += 0.01 * f(type, a, b, c, x1);
	}
	if (x == 1)
		return -sum;
	else
		return sum;
}

void init_operate_num(struct Data* StackNum)
{
	StackNum->top = -1;
}


void init_operate_symbol(struct Symbol* StackSymbol)
{
	StackSymbol->top = -1;
}

void in_data(struct Data* StackNum, double num)
{
	StackNum->top++;
	StackNum->data[StackNum->top] = num;
}

void in_symbol(struct Symbol* StackSymbol, char ch)
{
	StackSymbol->top++;
	StackSymbol->symbol[StackSymbol->top] = ch;
}

double read_data(struct Data* StackNum)
{
	return StackNum->data[StackNum->top];
}

char read_symbol(struct Symbol* StackSymbol)
{
	return StackSymbol->symbol[StackSymbol->top];
}

double put_data(struct Data* StackNum)
{
	double x;
	x = StackNum->data[StackNum->top];
	StackNum->top--;
	return x;
}

char put_symbol(struct Symbol* StackSymbol)
{
	char c;
	c = StackSymbol->symbol[StackSymbol->top];
	StackSymbol->top--;
	return c;
}

int judge(char ch)
{
	if (ch == '(')
	{
		return 1;
	}
	if (ch == '+' || ch == '-')
	{
		return 2;
	}
	else if (ch == '*' || ch == '/' || ch == '^')
	{
		return 3;
	}
	else if (ch == ')')
	{
		return 4;
	}
	return 0;
}

double calculate(double num1, double num2, char c)
{
	double sum = 0;
	switch (c) {
	case '+': {
		sum = num1 + num2;
		break;
	}
	case '-': {
		sum = num1 - num2;
		break;
	}
	case '*': {
		sum = num1 * num2;
		break;
	}
	case '/': {
		sum = num1 / num2;
		break;
	}
	case '^': {
		sum = pow(num1, num2);
		break;
	}
	}
	return sum;
}

void change_radix(int hex, char* v)
{
	unsigned int i;
	double num = 0;
	if (hex == 2)
	{
		for (i = 1; i < strlen(v); i++)
		{
			if (v[i] == '0' || v[i] == '1')
				num += (v[i] - '0') * pow(2, strlen(v) - i - 1);
			else
				return;
		}
	}
	if (hex == 16)
	{
		for (i = 2; i < strlen(v); i++)
		{
			if (v[i] >= '0' && v[i] <= '9')
				num += (v[i] - '0') * pow(16, strlen(v) - i - 1);
			else if ((v[i] >= 'a' && v[i] <= 'f'))
				num += (v[i] - 'a' + 10) * pow(16, strlen(v) - i - 1);
			else
				return;
		}
	}
	sprintf_s(v, 100, "%lf", num);
}
