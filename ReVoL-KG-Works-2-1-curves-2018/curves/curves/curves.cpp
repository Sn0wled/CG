/* 2018 ReVoL Primer Template */
/* curves.cpp */
#include "curves.h"
// Размер графика
#define GX 7.0
#define GY 2.0
// шаг по х
#define DX 5

void pixel(HDC hdc, int X, int Y);
void moveTo(HDC hdc, int X, int Y);
void lineTo(HDC hdc, int X, int Y);
void byPoints(HDC hdc); // рисует функцию точками
void byLines(HDC hdc); // рисует функцию линиями
double funca(double x);

// размер устройства вывода
int WX = 0, WY = 0;
//масштаб осей
double SX = 0, SY = 0;
//центр системы координат
int CX = 0, CY = 0;

// параметры вывода
void setview() {
    RECT rc;
    GetClientRect(hWndGDE, &rc);
    WX = rc.right - rc.left;
    WY = rc.bottom - rc.top;
    CX = (rc.right + rc.left) / 2;
    CY = (rc.bottom + rc.top) / 2;
    SX = WX / GX;  // шобы в экранные координаты нужно свои умножить на эти числа
    SY = WY / GY;
}

/* контекст устройства GDC */
void draw() {
    setview();
    MoveToEx(GDC, 0, CY, 0);
    LineTo(GDC, WX, CY);
    MoveToEx(GDC, CX, 0, 0);
    LineTo(GDC, CX, WY);
    byPoints(GDC);
    byLines(GDC);
}

int xToScreen(double mathX) {
    return mathX * SX + CX;
}

int yToScreen(double mathY) {
    return CY + mathY * SY;
}

double xToMath(int screenX) {
    return (screenX - CX) / SX;
}

double yToMath(int screenY) {
    return (CY - screenY) / SY;
}

void byLines(HDC hdc) {
    double screenX, screenY;
    screenX = 0;
    screenY = yToScreen(funca(xToMath(screenX)));
    moveTo(hdc, screenX, screenY);
    for (screenX = DX; screenX <= WX; screenX += DX) {
        double mathX = xToMath(screenX);
        double mathY = funca(mathX);
        screenY = yToScreen(mathY);
        lineTo(hdc, screenX, screenY);
    }
}

void byPoints(HDC hdc) {
    double screenX, screenY;
    for (screenX = 0; screenX <= WX; screenX++) {
        double mathX = xToMath(screenX);
        double mathY = funca(mathX);
        screenY = yToScreen(mathY);
        pixel(hdc, screenX, screenY);
    }
}

double funca(double x) {
    return sin(x);
}

void pixel(HDC hdc, int X, int Y) {
    SetPixel(hdc, X, Y, RGB(255, 0, 0));
}

void moveTo(HDC hdc, int X, int Y) {
    MoveToEx(hdc, X, Y, 0);
}

void lineTo(HDC hdc, int X, int Y) {
    LineTo(hdc, X, Y);
}