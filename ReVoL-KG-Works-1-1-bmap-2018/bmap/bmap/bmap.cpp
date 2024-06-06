// 2018 ReVoL Primer Template
// bmap.cpp
#include "bmap.h"
// путь к файлу BMP
#define PATH ".\\ch01.bmp"
//#define PATH "ch04.bmp"
//#define PATH "ch08.bmp"
//#define PATH "ch24.bmp"

// исследование BMP
void bitmap() {
	FILE* bin = fopen(PATH, "rb");
	if (!bin) return;
	BITMAPFILEHEADER bmfh;
	int res = fread((void*)&bmfh, sizeof(BITMAPFILEHEADER), 1, bin);
	if (res == 0) return;
	fclose(bin);
}

// исследование метафайла
void metafile() {
}
