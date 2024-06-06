// 2007 ReVoL Primer Template
// 3-multi.h

// матрица-столбец дифференциалов
point K[MAX_POINT];
// матрица-столбец свободных элементов
point B[MAX_POINT];
// длины сегментов
double T[MAX_POINT];

// рисует многосегментный параметрический сплайн
// px, py - массивы координат точек
// m      - количество точек (схватов)
// ln     - количество сегментов прямых
void draw_segments(HDC hdc, int * px, int * py, int m, int ln) {
	int n = m - 1;
	for (int i = 1; i <= n; i++) {
		T[i] = sqrt(pow(px[i] - px[i - 1], 2) + pow(py[i] - py[i - 1], 2));
	}
	// вычисляем начальный и конечный дифферинциалы (K[0], K[n])
	int dx = px[1] - px[GRIP_L];
	int dy = py[1] - py[GRIP_L];
	double d = sqrt(pow(dx, 2) + pow(dy, 2));
	K[0].x = dx / d;
	K[0].y = dy / d;
	dx = px[GRIP_R] - px[m];
	dy = py[GRIP_R] - py[m];
	d = sqrt(pow(dx, 2) + pow(dy, 2));
	K[n].x = dx / d;
	K[n].y = dy / d;
	// вычисление свободных элементов B
	for (int i = 1; i < n; i++) {
		B[i].x = 3 * ((px[i + 1] - px[i]) * T[i] / T[i + 1] + (px[i] - px[i - 1]) * T[i + 1] / T[i]);
		B[i].y = 3 * ((py[i + 1] - py[i]) * T[i] / T[i + 1] + (py[i] - py[i - 1]) * T[i + 1] / T[i]);
	}
	solve_tgs(K, B, T, n);
	for (int i = 0, j = 1; i < n; i++, j++) {
		draw_segment(hdc, px[i], py[i], px[j], py[j], K[i].x, K[i].y, K[j].x, K[j].y, T[j], ln);
	}
}
