// 2007 ReVoL Primer Template
// 2-param.h

// рисует параметрический сплайн (сегмент)
// px, py - массивы координат точек
// ln     - количество сегментов пр€мых
void draw_param(HDC hdc, const int * px, const int * py, int ln) {
	double k0x = 0, k0y = 0, k1x = 0, k1y = 0;
	double t = 0;
	double x0 = px[0], y0 = py[0], x1 = px[1], y1 = py[1];
	double dx = px[0] - px[GRIP_L];
	double dy = py[0] - py[GRIP_L];
	double d = pow(pow(dx, 2) + pow(dy, 2), 0.5);
	t = pow(pow(x0 - x1, 2) + pow(y0 - y1, 2), 0.5);
	k0x = dx / d;
	k0y = dy / d;
	dx = px[GRIP_R] - px[1];
	dy = py[GRIP_R] - py[1];
	d = pow(pow(dx, 2) + pow(dy, 2), 0.5);
	k1x = dx / d;
	k1y = dy / d;
	draw_segment(hdc, x0, y0, x1, y1, k0x, k0y, k1x, k1y, t, ln);
}

// рисует сегмент кубического сплайна
// x0, y0   - координаты начальной точки
// x1, y1   - координаты конечной точки
// k0x, k0y - дифференциал в начальной точке
// k1x, k1y - дифференциал в конечной точке
// t        - максимальное значение параметра
// ln       - количество пр€мых линий
void draw_segment(HDC hdc, int x0, int y0, int x1, int y1, double k0x, double k0y, double k1x, double k1y, double t2, int ln) {
	double a3x = (3 * (x1 - x0)) / pow(t2, 2) - (k0x + k0x + k1x) / t2;
	double a3y = (3 * (y1 - y0)) / pow(t2, 2) - (k0y + k0y + k1y) / t2;
	double a4x = (2 * (x0 - x1)) / pow(t2, 3) + (k0x + k1x) / pow(t2, 2);
	double a4y = 2 * ((y0 - y1)) / pow(t2, 3) + (k0y + k1y) / pow(t2, 2);
	double dt = t2 / ln;
	double t = 0;
	MoveToEx(hdc, x0, y0, 0);
	for (int i = 0; i < ln; i++) {
		t += dt;
		double x = x0 + (k0x + (a3x + a4x * t) * t) * t;
		double y = y0 + (k0y + (a3y + a4y * t) * t) * t;
		LineTo(hdc, x, y);
	}

}
