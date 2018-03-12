#include<stdio.h>
#include<windows.h>
typedef int(*lpAddFun)(int,int);          //lpAddFun，指向一个函数的指针。注意这种写法，返回类型int，参数int,int，都要结合具体的函数来写
#pragma comment (lib,"User32.lib")        //加这个是因为下面用到了MessageBox函数，表示在链接时链接User32.lib


int WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
	HINSTANCE hDll;       //函数句柄
	lpAddFun addFun;      //指向函数的指针，准确说是指向两个形参类型为int，int,返回值为int的函数的指针
	int i=0;
	hDll=LoadLibrary(__TEXT("D:\\study software\\VS 2005 vc++8.0\\Had installed\\VC\\projects\\testdll\\Debug\\programdll.dll"));
	//先找到这个需要调用的.dll文件。TEXT前面是两个下划线。绝对路径中是双"\"，因为一个\有可能是转义字符等
	if(hDll!=NULL)        //hDll不等于NULL，表示找到了这个.dll文件，继续找该文件中的某个函数
	{
		addFun=(lpAddFun)GetProcAddress(hDll,"add");//从该.dll文件中，找到add函数地址，赋给这个函数指针
		if(addFun!=NULL)  //addFun不等于NULL，表示add函数被找到了，并成功把地址成功赋给了addFun
		{
			i=addFun(3,8);//这里addFun是一个指针，而函数名add本身就是一个指针
			if(i==11)
				MessageBox(NULL,TEXT("RIGHT"),TEXT("RIGHT"),MB_OK); 
			else
				MessageBox(NULL,TEXT("OK"),TEXT("OK"),MB_OK); 
			printf("%d",i);
		}
		else
			MessageBox(NULL,TEXT("hellow"),TEXT("D"),MB_OK);
		FreeLibrary(hDll);
	}
	else
		MessageBox(NULL,TEXT("nidaye"),TEXT("D"),MB_OK);
   return 0;
}

