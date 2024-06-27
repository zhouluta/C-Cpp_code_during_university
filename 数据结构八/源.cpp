#pragma warning (suppress : 4996)
#include<stdio.h> 
#include<windows.h> //win32函数（窗体）
#include<math.h>

extern "C" WINBASEAPI HWND WINAPI GetConsoleWindow();
//上面这句声明GetConsoleWindow()这个Win32函数是C语言编写的。
//当前这个源程序是C++源文件。它们在编译后的调用约定不同。

int main()
{
	unsigned char red[500 * 500];//最大500*500的图像
	unsigned char green[500 * 500];
	unsigned char blue[500 * 500];
	int height, width;
	HWND hwnd;
	HDC hdc;
	hwnd = GetConsoleWindow();//获取准备绘图的窗口。
	hdc = GetDC(hwnd);//获取窗口的客户区（正文区域）

	FILE* fp = fopen("RAW\\a1.raw", "rb");
	fseek(fp, 0, SEEK_END);//定位到文件的最后面
	long length = ftell(fp);//ftell获得该文件指示符此时的偏移量,此时已经是在文件末尾,故能获得文件的大小
	height = width = (int)sqrt(length / 3);//图像都是正方形
	fseek(fp, 0, SEEK_SET);//文件指针重回头部
	fread(red, 1, height * width, fp);
	fread(green, 1, height * width, fp);
	fread(blue, 1, height * width, fp);
	fclose(fp);

	for (int i = 0;i < height;i++) {
		for (int j = 0;j < width;j++) {
			long off;
			off = i * width + j;//像素在数组中的偏移量
			SetPixel(hdc, j, i, RGB(red[off], green[off], blue[off]));
			//RGB()把三种颜色混合
		}
	}

	ReleaseDC(hwnd, hdc);
	getchar();
	return 0;
}