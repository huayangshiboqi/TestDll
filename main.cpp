#include<stdio.h>
#include<windows.h>
typedef int(*lpAddFun)(int,int);          //lpAddFun��ָ��һ��������ָ�롣ע������д������������int������int,int����Ҫ��Ͼ���ĺ�����д
#pragma comment (lib,"User32.lib")        //���������Ϊ�����õ���MessageBox��������ʾ������ʱ����User32.lib


int WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
	HINSTANCE hDll;       //�������
	lpAddFun addFun;      //ָ������ָ�룬׼ȷ˵��ָ�������β�����Ϊint��int,����ֵΪint�ĺ�����ָ��
	int i=0;
	hDll=LoadLibrary(__TEXT("D:\\study software\\VS 2005 vc++8.0\\Had installed\\VC\\projects\\testdll\\Debug\\programdll.dll"));
	//���ҵ������Ҫ���õ�.dll�ļ���TEXTǰ���������»��ߡ�����·������˫"\"����Ϊһ��\�п�����ת���ַ���
	if(hDll!=NULL)        //hDll������NULL����ʾ�ҵ������.dll�ļ��������Ҹ��ļ��е�ĳ������
	{
		addFun=(lpAddFun)GetProcAddress(hDll,"add");//�Ӹ�.dll�ļ��У��ҵ�add������ַ�������������ָ��
		if(addFun!=NULL)  //addFun������NULL����ʾadd�������ҵ��ˣ����ɹ��ѵ�ַ�ɹ�������addFun
		{
			i=addFun(3,8);//����addFun��һ��ָ�룬��������add�������һ��ָ��
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

