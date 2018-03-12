extern "C" int __declspec(dllexport)add(int x,int y);//declspec前面是两个下划线
int add(int x,int y)
{
	int a=x+y+10;
	return a;
}