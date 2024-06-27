#pragma warning (suppress : 4996)
#include<stdio.h> 
#include<windows.h> //win32���������壩
#include<math.h>

extern "C" WINBASEAPI HWND WINAPI GetConsoleWindow();
//�����������GetConsoleWindow()���Win32������C���Ա�д�ġ�
//��ǰ���Դ������C++Դ�ļ��������ڱ����ĵ���Լ����ͬ��

int main()
{
	unsigned char red[500 * 500];//���500*500��ͼ��
	unsigned char green[500 * 500];
	unsigned char blue[500 * 500];
	int height, width;
	HWND hwnd;
	HDC hdc;
	hwnd = GetConsoleWindow();//��ȡ׼����ͼ�Ĵ��ڡ�
	hdc = GetDC(hwnd);//��ȡ���ڵĿͻ�������������

	FILE* fp = fopen("RAW\\a1.raw", "rb");
	fseek(fp, 0, SEEK_END);//��λ���ļ��������
	long length = ftell(fp);//ftell��ø��ļ�ָʾ����ʱ��ƫ����,��ʱ�Ѿ������ļ�ĩβ,���ܻ���ļ��Ĵ�С
	height = width = (int)sqrt(length / 3);//ͼ����������
	fseek(fp, 0, SEEK_SET);//�ļ�ָ���ػ�ͷ��
	fread(red, 1, height * width, fp);
	fread(green, 1, height * width, fp);
	fread(blue, 1, height * width, fp);
	fclose(fp);

	for (int i = 0;i < height;i++) {
		for (int j = 0;j < width;j++) {
			long off;
			off = i * width + j;//�����������е�ƫ����
			SetPixel(hdc, j, i, RGB(red[off], green[off], blue[off]));
			//RGB()��������ɫ���
		}
	}

	ReleaseDC(hwnd, hdc);
	getchar();
	return 0;
}