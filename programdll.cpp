extern "C" int __declspec(dllexport)add(int x,int y);//declspecǰ���������»���
int add(int x,int y)
{
	int a=x+y+10;
	return a;
}