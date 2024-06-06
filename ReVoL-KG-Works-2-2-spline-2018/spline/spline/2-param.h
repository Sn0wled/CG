// 2007 ReVoL Primer Template
// 2-param.h

// рисует параметрический сплайн (сегмент)
// px, py - массивы координат точек
// ln     - количество сегментов пр€мых
void draw_param(HDC hdc, const int * px, const int * py, int ln) {
}

// рисует сегмент кубического сплайна
// x0, y0   - координаты начальной точки
// x1, y1   - координаты конечной точки
// k0x, k0y - дифференциал в начальной точке
// k1x, k1y - дифференциал в конечной точке
// t        - максимальное значение параметра
// ln       - количество пр€мых линий
void draw_segment(HDC hdc, int x0, int y0, int x1, int y1, double k0x, double k0y, double k1x, double k1y, double t2, int ln) {
}
